#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#include "macro_collections.h"
#include "messages.h"
#include "netapi.h"

int main(int argc, char const *argv[])
{
    if (argc != 4)
    {
        cmc_log_fatal("Usage: %s <ctrl> <key> <value>", argv[0]);
        return 1;
    }

    int client_fd;
    struct sockaddr_in cliaddr;

    if (!net_client(&client_fd, &cliaddr))
        return 2;

    cmc_log_info("Sending message to %d", NETAPI_SERVER_PORT);

    char *msg = msg_create_str((char *)argv[1], (char *)argv[2], strlen(argv[2]), (char *)argv[3], strlen(argv[3]));

    if (!msg)
    {
        cmc_log_error("Could not create a valid message from given parameters.");
        return 4;
    }

    if (!net_send(client_fd, msg, strlen(msg)))
        return 5;

    free(msg);
    close(client_fd); // Close file descriptor

    return 0;
}
