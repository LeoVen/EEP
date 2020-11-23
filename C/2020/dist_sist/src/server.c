#include <errno.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#include "macro_collections.h"

#include "collections.h"
#include "database.h"
#include "mail.h"
#include "messages.h"
#include "netapi.h"

/* Threads */
struct server_thread_arg
{
    // A pointer to the database
    struct dictionary *database;
    // The database mutex
    struct cmc_mutex *db_mutex;
    // A pointer to the clients connections
    struct climap *clients;
    // The clients connections mutex
    struct cmc_mutex *cl_mutex;
    // The mailing queue
    struct mailq *mails;
    // The mailing queue mutex
    struct cmc_mutex *mq_mutex;
    // The client's file descriptor for callbacks
    int client_fd;
};

int server_thread(void *arguments);
void get_datetime(char time_[32]);
void get_datefile(char date_[10]);

bool server_alive = true;

int main(void)
{
    int server_fd;
    struct sockaddr_in servaddr;

    if (!net_server(&server_fd, &servaddr))
    {
        cmc_log_fatal("Could not start server socket.");
        return 0;
    }

    /* Setting up clients list */
    struct climap *clients = cl_new(100, 0.6, &climap_methods_key, &climap_methods_val);
    struct cmc_mutex *cl_mutex = &(struct cmc_mutex){ 0 };
    if (!cmc_mtx_init(cl_mutex))
    {
        cmc_log_fatal("Could not start clients mutex.");
        perror("");
        goto error_0;
    }

    /* Setting up message queue */
    struct mailq *mails = mq_new(100, 0.6, &mailq_methods_key, &mailq_methods_val);
    struct cmc_mutex *mq_mutex = &(struct cmc_mutex){ 0 };
    if (!cmc_mtx_init(mq_mutex))
    {
        cmc_log_fatal("Could not start mails mutex.");
        perror("");
        goto error_1;
    }

    /* Setting up Database */
    struct dictionary *database = dict_new(1000, 0.6, &dict_methods_key, &dict_methods_val);
    struct cmc_mutex *db_mutex = &(struct cmc_mutex){ 0 };
    if (!cmc_mtx_init(db_mutex))
    {
        cmc_log_fatal("Could not start database mutex.");
        perror("");
        goto error_3;
    }

    if (!database_load(database, DATABASE_DEFAULT_FILE_NAME))
        cmc_log_error("Could not load database.");

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
        {
            cmc_log_debug("Connection is Shutting down the server %s:%d", inet_ntoa(cliaddr.sin_addr), ntohs(cliaddr.sin_port));
            break;
        }

        ssize_t length;
        netapi_recv_buffer client_id_recv;

        /* Get client's ID */
        if (!net_recv(client_fd, client_id_recv, &length))
        {
            cmc_log_error("Could not get client's ID.");
            continue;
        }

        size_t len = strlen(client_id_recv);
        char *client_id = calloc(1, len + 1);

        memcpy(client_id, client_id_recv, len);

        cmc_log_info("Logged in: %s", client_id);

        /* Add the client's id to the connection's list */
        cmc_mtx_lock(cl_mutex);
        cl_insert(clients, client_id, client_fd);
        int flag = cl_flag(clients);
        cmc_mtx_unlock(cl_mutex);

        if (flag != CMC_FLAG_OK)
        {
            cmc_log_error("Could not add new client id - %s", cmc_flags_to_str[flag]);
            continue;
        }

        /* Preparing thread to serve the client */
        struct cmc_thread thread = { 0 };
        struct server_thread_arg *arg = calloc(1, sizeof(struct server_thread_arg));
        arg->database = database;
        arg->db_mutex = db_mutex;
        arg->clients = clients;
        arg->cl_mutex = cl_mutex;
        arg->client_fd = client_fd;
        arg->mails = mails;
        arg->mq_mutex = mq_mutex;

        if (!cmc_thrd_create(&thread, server_thread, arg))
        {
            cmc_log_error("Failed to spawn server thread.");
            perror("");
        }
    }

    cmc_mtx_destroy(db_mutex);
    database_save(database, DATABASE_DEFAULT_FILE_NAME);
    error_3:
    dict_free(database);
    cmc_mtx_destroy(mq_mutex);
    error_1:
    mq_free(mails);
    cmc_mtx_destroy(cl_mutex);
    error_0:
    cl_free(clients);
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
    struct climap *clients = args->clients;
    struct cmc_mutex *cl_mutex = args->cl_mutex;
    struct mailq *mails = args->mails;
    struct cmc_mutex *mq_mutex = args->mq_mutex;

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

        cmc_log_debug("[%" PRIiMAX "] Received message: %s", id, reply);

        struct msg_message *msg = &(struct msg_message) { 0 };

        if (!msg_parse(reply, length, msg))
        {
            cmc_log_error("[%" PRIiMAX "] Could not parse received message.", id);
            continue;
        }
        else if (msg->ctrl == MSG_CTRL_SHUTDOWN)
        {
            cmc_log_info("[%" PRIiMAX "] Shuting down server because: %s", id, msg->key);
            server_alive = false;
            break;
        }
        else if (msg->ctrl == MSG_CTRL_CREATE)
        {
            cmc_log_trace("[%" PRIiMAX "] Creating new key-value pair.", id);
            cmc_mtx_lock(db_mutex);

            dict_insert(database, msg->key, msg->val);
            int flag = dict_flag(database);

            cmc_mtx_unlock(db_mutex);

            char callback[200];

            if (flag != CMC_FLAG_OK)
            {
                cmc_log_warn("[%" PRIiMAX "] Could not add key-value pair to database - %s", id,
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
                cmc_log_fatal("[%" PRIiMAX "] Could not send callback to client!", id);
            }
        }
        else if (msg->ctrl == MSG_CTRL_READ)
        {
            cmc_log_trace("[%" PRIiMAX "] Retrieving value from a key.", id);
            cmc_mtx_lock(db_mutex);

            char *value = dict_get(database, msg->key);

            cmc_mtx_unlock(db_mutex); // Unlocking here could invalidate value pointer
                                      // if another thread can quickly remove the key

            char *callback = "OK";

            if (!value)
            {
                cmc_log_warn("[%" PRIiMAX "] Failed to retrieve value from key \"%s\".", id, msg->key);

                char *error = "Failed to retrieve value from key.";

                char *to_send = msg_create(MSG_CTRL_CALLBACK, error, strlen(error), "", 0);

                if (!to_send)
                {
                    cmc_log_error("[%" PRIiMAX "] Could not create result message.", id);
                }
                if (!net_send(client_fd, to_send, strlen(to_send)))
                {
                    cmc_log_error("[%" PRIiMAX "] Could not send result to client.", id);
                }

                free(to_send);
            }
            else
            {
                char *to_send = msg_create(MSG_CTRL_CALLBACK, callback, strlen(callback), value, strlen(value));

                if (!to_send)
                {
                    cmc_log_error("[%" PRIiMAX "] Could not create result message.", id);
                }
                else
                {
                    if (!net_send(client_fd, to_send, strlen(to_send)))
                    {
                        cmc_log_error("[%" PRIiMAX "] Could not send result to client.", id);
                    }
                }

                free(to_send);
            }
        }
        else if (msg->ctrl == MSG_CTRL_UPDATE)
        {
            cmc_log_trace("[%" PRIiMAX "] Updating existing key-value pair.", id);
            cmc_mtx_lock(db_mutex);

            char *old_value;
            dict_update(database, msg->key, msg->val, &old_value);

            int flag = dict_flag(database);
            if (flag == CMC_FLAG_OK)
                free(old_value);

            cmc_mtx_unlock(db_mutex);

            char callback[200];

            if (flag != CMC_FLAG_OK)
            {
                cmc_log_warn("[%" PRIiMAX "] Could not update key-value pair to database - %s", id,
                    cmc_flags_to_str[flag]);

                snprintf(callback, sizeof(callback), "Could not update key-value pair to database: %s",
                    cmc_flags_to_str[flag]);
            }
            else
            {
                snprintf(callback, sizeof(callback), "%s", "OK");
            }

            destroy = false;

            if (!net_callback(client_fd, callback))
            {
                cmc_log_fatal("[%" PRIiMAX "] Could not send callback to client!", id);
            }
        }
        else if (msg->ctrl == MSG_CTRL_DELETE)
        {
            cmc_log_trace("[%" PRIuMAX "] Deleting key-value pair.", id);
            cmc_mtx_lock(db_mutex);

            char *old_value;
            dict_remove(database, msg->key, &old_value);

            int flag = dict_flag(database);
            if (flag == CMC_FLAG_OK)
                free(old_value);

            cmc_mtx_unlock(db_mutex);

            char callback[200];
            if (flag != CMC_FLAG_OK)
            {
                cmc_log_warn("[%" PRIiMAX "] Could not delete key-value pair to database - %s", id,
                    cmc_flags_to_str[flag]);

                snprintf(callback, sizeof(callback), "Could not delete key-value pair to database: %s",
                    cmc_flags_to_str[flag]);
            }
            else
            {
                snprintf(callback, sizeof(callback), "%s", "OK");
            }

            if (!net_callback(client_fd, callback))
            {
                cmc_log_fatal("[%" PRIiMAX "] Could not send callback to client!", id);
            }
        }
        else if (msg->ctrl == MSG_CTRL_BACKUP)
        {
            cmc_log_trace("Saving Database's state...");
            cmc_mtx_lock(db_mutex);

            char file_name[200];
            char date[10];
            get_datefile(date);

            snprintf(file_name, sizeof(file_name), "%sDatabaseBackup.txt", date);

            bool result = database_save(database, file_name);

            cmc_mtx_unlock(db_mutex);

            char callback[200];
            if (!result)
            {
                cmc_log_warn("[%" PRIiMAX "] Could not make database backup.", id);

                snprintf(callback, sizeof(callback), "Could not make database backup.");
            }
            else
            {
                snprintf(callback, sizeof(callback), "%s", "OK");
            }

            if (!net_callback(client_fd, callback))
            {
                cmc_log_fatal("[%" PRIiMAX "] Could not send callback to client!", id);
            }
        }
        else if (msg->ctrl == MSG_CTRL_STATUS)
        {
            size_t count = dict_count(database);
            size_t capacity = dict_capacity(database);

            char result[300];

            snprintf(result, sizeof(result), "Count: %" PRIiMAX " | Capacity: %" PRIiMAX "", count, capacity);

            char *to_send = msg_create(MSG_CTRL_STATUS, "STATUS", strlen("STATUS"), result, strlen(result));

            if (!to_send)
            {
                cmc_log_error("[%" PRIiMAX "] Could not create result message.", id);
            }
            else
            {
                if (!net_send(client_fd, to_send, strlen(to_send)))
                {
                    cmc_log_error("[%" PRIiMAX "] Could not send result to client.", id);
                }

                free(to_send);
            }
        }
        else if (msg->ctrl == MSG_CTRL_MAIL_SEND)
        {
            cmc_log_trace("[%" PRIuMAX "] Storing message for %s.", id, msg->key);

            char callback[200];

            cmc_mtx_lock(cl_mutex);
            char *cli_id = cl_get_key(clients, client_fd);
            int flag = cl_flag(clients);

            if (flag != CMC_FLAG_OK || cli_id == NULL)
                goto mail_send_error;

            // Create saved message
            char time[32];
            get_datetime(time);

            size_t len_to_insert = strlen(time) + strlen(cli_id) + msg->val_len + 7;
            char *to_insert = calloc(1, len_to_insert);

            snprintf(to_insert, len_to_insert, "%s [%s] : %s", time, cli_id, msg->val);

            cmc_mtx_unlock(cl_mutex); // No longer using cli_id

            // Add to message queue
            cmc_mtx_lock(mq_mutex);

            struct msglist *list = mq_get(mails, msg->key);

            if (mq_flag(mails) == CMC_FLAG_NOT_FOUND || list == NULL)
            {
                list = ml_new(10, &msglist_methods_val);
                ml_push_back(list, to_insert);
                flag |= ml_flag(list);

                mq_insert(mails, msg->key, list);
                flag |= mq_flag(mails);
            }
            else if (list != NULL)
            {
                ml_push_back(list, to_insert);
                flag |= ml_flag(list);
                free(msg->key); // Key is already mapped
            }

            destroy = false;
            cmc_mtx_unlock(mq_mutex);

            // Reply back to client
            mail_send_error:
            if (flag != CMC_FLAG_OK || cli_id == NULL)
            {
                cmc_log_error("[%" PRIiMAX "] Error while saving client's message.", id);

                snprintf(callback, sizeof(callback), "Error while saving client's message.");
            }
            else
            {
                snprintf(callback, sizeof(callback), "%s", "OK");
            }

            if (!net_callback(client_fd, callback))
            {
                cmc_log_fatal("[%" PRIiMAX "] Could not send callback to client!", id);
            }
        }
        else if (msg->ctrl == MSG_CTRL_MAIL_RECV)
        {
            cmc_log_trace("[%" PRIuMAX "] Retrieving messages for %s.", id, msg->key);

            size_t curr = 0, max = NETAPI_RECV_BUFFER_SIZE - 1;
            netapi_recv_buffer result = { 0 };

            char *cli_id = msg->val;

            cmc_mtx_lock(mq_mutex);

            struct msglist *list = mq_get(mails, cli_id);
            int flag = mq_flag(mails);

            if (flag != CMC_FLAG_OK || list == NULL)
                goto mail_recv_error;

            // Format all messages into one string
            int i;
            for (i = 0; i < ml_count(list); i++)
            {
                char *message = list->buffer[i];

                int delta = snprintf(&(result[curr]), max - curr, "%s\n", message);

                if (delta < 0)
                    break;

                curr += delta;
            }

            mail_recv_error:

            cmc_mtx_unlock(mq_mutex); // No longer using list

            char key[200] = { 0 };

            if (flag != CMC_FLAG_OK || cli_id == NULL)
            {
                cmc_log_error("[%" PRIiMAX "] Error while retrieving client's emails - %s", id,
                    cmc_flags_to_str[flag]);

                snprintf(key, sizeof(key), "Error while retrieving client's emails - %s",
                    cmc_flags_to_str[flag]);
            }
            else
            {
                snprintf(key, sizeof(key), "%s", "OK");
            }

            char *to_send = msg_create(MSG_CTRL_MAIL_RECV, key, strlen(key), result, strlen(result));

            if (!to_send)
            {
                cmc_log_error("[%" PRIiMAX "] Could not create result message.", id);
            }
            else
            {
                if (!net_send(client_fd, to_send, strlen(to_send)))
                {
                    cmc_log_error("[%" PRIiMAX "] Could not send result to client.", id);
                }

                // Remove emails from msg list

                cmc_mtx_lock(mq_mutex);

                struct msglist *list = mq_get(mails, cli_id);
                if (mq_flag(mails) == CMC_FLAG_OK)
                {
                    ml_clear(list);
                }

                cmc_mtx_unlock(mq_mutex); // No longer using list

                free(to_send);
            }
        }
        else
        {
            cmc_log_warn("[%" PRIiMAX "] Unknown control message.", id);
        }

        if (destroy)
            msg_message_destroy(msg);
    }

    /* Remove this client's ID because it is getting disconnected */
    cmc_mtx_lock(cl_mutex);
    char *cli_id;
    cl_remove_by_val(clients, client_fd, &cli_id, NULL);
    free(cli_id);
    int flag = cl_flag(clients);
    cmc_mtx_unlock(cl_mutex);

    if (flag != CMC_FLAG_OK)
        cmc_log_error("[%d] Could not remove client's ID from map.", id);

    cmc_log_debug("Shuting down thread %" PRIiMAX ".", id);

    return 0;
}

void get_datetime(char time_[32])
{
    time_t t = time(NULL);
    struct tm *lt = localtime(&t);
    time_[strftime(time_, 32, "%Y-%m-%d %H:%M:%S", lt)] = '\0';
}

void get_datefile(char date_[10])
{
    time_t t = time(NULL);
    struct tm *lt = localtime(&t);
    date_[strftime(date_, 10, "%Y%m%d%H%M%S", lt)] = '\0';
}
