#include <errno.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#include "macro_collections.h"
#include "messages.h"

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
    if (argc != 2)
    {
        cmc_log_fatal("Usage: %s <port_number>", argv[0]);
        return -1;
    }

    int port = atoi(argv[1]);

    int listenfd = socket(AF_INET, SOCK_STREAM, 0);

    if (listenfd < 0)
    {
        cmc_log_error("Error creating socket file descriptor.");
        perror("");
        return 1;
    }
    else
    {
        cmc_log_info("Opened socket successfully.");
    }

    struct sockaddr_in servaddr;
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_addr.s_addr = INADDR_ANY;
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(port);

    if (bind(listenfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0)
    {
        cmc_log_error("Could not bind to socket.");
        perror("");
        return 2;
    }
    else
    {
        cmc_log_info("Binded to socket successfully.");
    }

    if (listen(listenfd, 3) < 0)
    {
        cmc_log_error("Could not listen to socket.");
        perror("");
        return 3;
    }

    cmc_log_info("Listening to connections at %d...", port);

    struct sockaddr_in cliaddr;
    unsigned int clientfd, client_size = sizeof(cliaddr);

    struct dictionary *database = dict_new(1000, 0.6, &dict_methods, (struct dictionary_fval *)&dict_methods);
    char reply[2000];

    while (((clientfd = accept(listenfd, (struct sockaddr *)&cliaddr, &client_size)) >= 0))
    {
        bool shutdown = false;
        char *client_ip = inet_ntoa(cliaddr.sin_addr);
        int client_port = ntohs(cliaddr.sin_port);

        cmc_log_info("Connection Accepted from %s:%d.", client_ip, client_port);

        ssize_t length = recv(clientfd, reply, sizeof(reply) - 1, 0);

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
    close(listenfd); // Close file descriptor
}
