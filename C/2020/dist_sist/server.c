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

int main(int argc, char const *argv[])
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
            break;
        }

        cmc_log_info("Connection Accepted from %s:%d", inet_ntoa(cliaddr.sin_addr), ntohs(cliaddr.sin_port));

        bool shutdown = false;

        ssize_t length = recv(client_fd, reply, sizeof(reply) - 1, 0);

        if (length <= 0)
        {
            if (length == 0)
            {
                cmc_log_warn("Received empty message.");
            }
            else
            {
                cmc_log_warn("Data received was not valid.");
                perror("");
            }
            continue;
        }

        reply[length] = '\0';
        cmc_log_trace("Received message: %s", reply);

        char *key = NULL, *val = NULL;
        enum message_control ctrl;
        size_t key_len = 0, val_len = 0;

        bool result = msg_parse(reply, length, &ctrl, &key, &key_len, &val, &val_len);

        if (!result)
        {
            cmc_log_error("Could not parse received message");
        }
        if (ctrl == MSG_CTRL_SHUTDOWN)
        {
            cmc_log_info("Shuting down server because: %s", key);
            shutdown = true;
        }
        else
        {
            cmc_log_trace("Ctrl : %s", msg_ctrl_to_string(ctrl));
            cmc_log_trace("Key  : %s", key);
            cmc_log_trace("Val  : %s", val);
        }

        free(key);
        free(val);

        if (shutdown)
            break;
    }

    dict_free(database);
    close(server_fd); // Close file descriptor
}
