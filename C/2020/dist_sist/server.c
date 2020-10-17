#include <errno.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#include "macro_collections.h"
#include "messages.h"
#include "netapi.h"

#define CMC_DICTIONARY (dict, dictionary, , char *, char *)
CMC_CMC_HASHMAP_CORE(PUBLIC, HEADER, CMC_DICTIONARY)
CMC_CMC_HASHMAP_CORE(PUBLIC, SOURCE, CMC_DICTIONARY)

void dict_str_free(char *data)
{
    free(data);
}

struct dictionary_fkey dict_methods_key = {
    .str = cmc_str_str,
    .cmp = cmc_str_cmp,
    .hash = cmc_str_hash_sdbm,
    .free = dict_str_free
};

struct dictionary_fval dict_methods_val = {
    .str = cmc_str_str,
    .cmp = cmc_str_cmp,
    .hash = cmc_str_hash_sdbm,
    .free = dict_str_free
};

struct server_thread_arg
{
    // A pointer to the database
    struct dictionary *database;
    // The database mutex
    struct cmc_mutex *db_mutex;
    // The client's file descriptor
    int client_fd;
};

int server_thread(void *arguments);

bool server_alive = true;

int main(void)
{
    int server_fd;
    struct sockaddr_in servaddr;

    if (!net_server(&server_fd, &servaddr))
        return 1;

    /* Setting up Database */
    struct dictionary *database = dict_new(1000, 0.6, &dict_methods_key, &dict_methods_val);
    struct cmc_mutex *db_mutex = &(struct cmc_mutex){ 0 };
    if (!cmc_mtx_init(db_mutex))
    {
        cmc_log_fatal("Could not start database mutex.");
        perror("");
        close(server_fd);
        dict_free(database);
    }

    struct sockaddr_in cliaddr;
    int client_fd;

    while (server_alive)
    {
        if (!net_accept(server_fd, &client_fd, &cliaddr))
        {
            cmc_log_fatal("Failed to accept message or server timeout. Shutting down...");
            perror("");
            break;
        }

        if (server_alive)
            cmc_log_debug("Connection Accepted from %s:%d", inet_ntoa(cliaddr.sin_addr), ntohs(cliaddr.sin_port));
        else
            cmc_log_debug("Connection is Shutting down the server %s:%d", inet_ntoa(cliaddr.sin_addr), ntohs(cliaddr.sin_port));

        if (server_alive)
        {
            struct cmc_thread thread = { 0 };
            struct server_thread_arg *arg = calloc(1, sizeof(struct server_thread_arg));
            arg->database = database;
            arg->db_mutex = db_mutex;
            arg->client_fd = client_fd;

            if (!cmc_thrd_create(&thread, server_thread, arg))
            {
                cmc_log_error("Failed to spawn server thread.");
            }
        }
    }

    cmc_mtx_destroy(db_mutex);
    dict_free(database);
    close(server_fd);
}

int server_thread(void *arguments)
{
    intmax_t id = pthread_self();
    cmc_log_debug("Spawned thread %" PRIiMAX ".", id);

    /* Retrieve parameters */
    struct server_thread_arg *args = (struct server_thread_arg *)arguments;

    struct dictionary *database = args->database;
    struct cmc_mutex *db_mutex = args->db_mutex;
    int client_fd = args->client_fd;

    free(args);

    bool destroy = true;
    netapi_recv_buffer reply;

    while (true)
    {
        ssize_t length = 0;

        if (!net_recv(client_fd, reply, &length))
            break;

        if (length == 0)
            break;

        cmc_log_debug("[%d] Received message: %s", id, reply);

        struct msg_message *msg = calloc(1, sizeof(struct msg_message));

        bool result = msg_parse(reply, length, msg);

        if (!result)
        {
            cmc_log_error("[%d] Could not parse received message.", id);
            continue;
        }
        else if (msg->ctrl == MSG_CTRL_SHUTDOWN)
        {
            cmc_log_info("[%d] Shuting down server because: %s", id, msg->key);
            server_alive = false;
            break;
        }
        else if (msg->ctrl == MSG_CTRL_CREATE)
        {
            cmc_log_trace("[%d] Creating new key-value pair.", id);
            cmc_mtx_lock(db_mutex);
            dict_insert(database, msg->key, msg->val);
            int flag = dict_flag(database);
            cmc_mtx_unlock(db_mutex);

            char callback[100];

            if (flag != CMC_FLAG_OK)
            {
                cmc_log_warn("[%d] Could not add key-value pair to database - %s", id,
                    cmc_flags_to_str[flag]);

                snprintf(callback, sizeof(callback), "Could not add key-value pair to database: %s",
                    cmc_flags_to_str[flag]);
            }
            else
            {
                snprintf(callback, sizeof(callback), "%s", "OK");
            }

            destroy = false;

            if (!net_callback(client_fd, callback))
            {
                cmc_log_fatal("[%d] Could not send callback to client!", id);
            }
        }
        else if (msg->ctrl == MSG_CTRL_READ)
        {
            cmc_log_trace("[%d] Retrieving value from a key.", id);
            cmc_mtx_lock(db_mutex);
            char *value = dict_get(database, msg->key);
            cmc_mtx_unlock(db_mutex); // Unlocking here could invalidate value pointer
                                      // if another thread can quickly remove the key

            char *callback = "OK";

            if (!value)
            {
                cmc_log_warn("[%d] Failed to retrieve value from key \"%s.\"", id, msg->key);

                char *error = "Failed to retrieve value from key.";

                char *to_send = msg_create(MSG_CTRL_CALLBACK, error, strlen(error), "", 0);

                if (!to_send)
                {
                    cmc_log_error("[%d] Could not create result message.", id);
                }
                if (!net_send(client_fd, to_send, strlen(to_send)))
                {
                    cmc_log_error("[%d] Could not send result to client.", id);
                }

                free(to_send);
            }
            else
            {
                char *to_send = msg_create(MSG_CTRL_CALLBACK, callback, strlen(callback), value, strlen(value));

                if (!to_send)
                {
                    cmc_log_error("[%d] Could not create result message.", id);
                }
                else
                {
                    if (!net_send(client_fd, to_send, strlen(to_send)))
                    {
                        cmc_log_error("[%d] Could not send result to client.", id);
                    }
                }

                free(to_send);
            }
        }
        else
        {
            cmc_log_warn("[%d] Unknown control message.", id);
        }

        if (destroy)
            msg_message_destroy(msg);

        free(msg);
    }

    cmc_log_debug("Shuting down thread %" PRIiMAX ".", id);

    return 0;
}
