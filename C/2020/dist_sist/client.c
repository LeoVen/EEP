#define CMC_LOG_COLOR

#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#include "macro_collections.h"
#include "messages.h"

int main(int argc, char const *argv[])
{
    if (argc != 3)
    {
        cmc_log_fatal("Usage: %s <port_number> <message>", argv[0]);
        return -1;
    }

    int port = atoi(argv[1]);

    int sock_desc = socket(AF_INET, SOCK_STREAM, 0);

    if (sock_desc == -1)
    {
        cmc_log_error("Error creating socket file descriptor");
        return 1;
    }

    struct sockaddr_in targetaddr;
    memset(&targetaddr, 0, sizeof(targetaddr));
    targetaddr.sin_addr.s_addr = INADDR_ANY;
    targetaddr.sin_family = AF_INET;
    targetaddr.sin_port = htons(port);

    if (connect(sock_desc, (struct sockaddr *)&targetaddr, sizeof(targetaddr)) < 0)
    {
        cmc_log_error("Could not connect to socket: %d", port);
        return 2;
    }
    else
    {
        cmc_log_info("Connected to socket %d", port);
    }

    cmc_log_info("Sending message to %d", port);

    if (send(sock_desc, argv[2], strlen(argv[2]), 0) < 0)
    {
        cmc_log_error("Could not send message to socket");
    }
    else
    {
        cmc_log_info("Sent %d bytes", strlen(argv[2]));
    }

    sleep(2);

    close(sock_desc); // Close file descriptor
}
