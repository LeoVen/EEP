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

struct dictionary_fkey dict_methods = {
    .str = cmc_str_str,
    .cmp = cmc_str_cmp,
    .hash = cmc_str_hash_sdbm,
    NULL,
};

int main(void)
{
    int server_fd;
    struct sockaddr_in servaddr;

    if (!net_server(&server_fd, &servaddr))
        return 1;

    struct sockaddr_in cliaddr;
    int client_fd;

    struct dictionary *database = dict_new(1000, 0.6, &dict_methods, (struct dictionary_fval *)&dict_methods);
    netapi_recv_buffer reply;

    while (true)
    {
        if (!net_accept(server_fd, &client_fd, &cliaddr))
        {
            cmc_log_fatal("Failed to accept message. Shutting down...");
            perror("");
            break;
        }

        cmc_log_info("Connection Accepted from %s:%d", inet_ntoa(cliaddr.sin_addr), ntohs(cliaddr.sin_port));

        bool shutdown = false, destroy = true;
        ssize_t length = 0;

        if (!net_recv(client_fd, reply, &length))
            continue;

        cmc_log_trace("Received message: %s", reply);

        struct msg_message msg;

        bool result = msg_parse(reply, length, &msg);

        if (!result)
        {
            cmc_log_error("Could not parse received message");
        }
        else if (msg.ctrl == MSG_CTRL_SHUTDOWN)
        {
            cmc_log_info("Shuting down server because: %s", msg.key);
            shutdown = true;
        }
        else if (msg.ctrl == MSG_CTRL_CREATE)
        {
            dict_insert(database, msg.key, msg.val);

            char callback[100];

            if (dict_flag(database) != CMC_FLAG_OK)
            {
                cmc_log_warn("Could not add key-value pair to database - %s",
                    cmc_flags_to_str[dict_flag(database)]);

                snprintf(callback, sizeof(callback), "Could not add key-value pair to database: %s",
                    cmc_flags_to_str[dict_flag(database)]);
            }
            else
            {
                snprintf(callback, sizeof(callback), "%s", "OK");
            }

            destroy = false;

            if (!net_callback(client_fd, callback))
            {
                cmc_log_fatal("Could not send callback to client!");
            }
        }
        else if (msg.ctrl == MSG_CTRL_READ)
        {
            char *value = dict_get(database, msg.key);

            char *callback = "OK";

            if (!value)
            {
                cmc_log_warn("Failed to retrieve value from key %s.", msg.key);

                char *error = "Failed to retrieve value from key.";

                char *to_send = msg_create(MSG_CTRL_CALLBACK, error, strlen(error), "", 0);

                if (!to_send)
                {
                    cmc_log_error("Could not create result message.");
                }
                else if (!net_send(client_fd, to_send, strlen(to_send)))
                {
                    cmc_log_error("Could not send result to client.");
                }
            }
            else
            {
                char *to_send = msg_create(MSG_CTRL_CALLBACK, callback, strlen(callback), value, strlen(value));

                if (!to_send)
                {
                    cmc_log_error("Could not create result message.");
                }
                else
                {
                    if (!net_send(client_fd, to_send, strlen(to_send)))
                    {
                        cmc_log_error("Could not send result to client.");
                    }
                }

                free(to_send);
            }
        }
        // else
        // {
        //     cmc_log_trace("Ctrl : %s", msg_ctrl_to_string(ctrl));
        //     cmc_log_trace("Key  : %s", key);
        //     cmc_log_trace("Val  : %s", val);
        // }

        if (destroy)
            msg_message_destroy(&msg);

        if (shutdown)
            break;
    }

    dict_free(database);
    close(server_fd);
}
