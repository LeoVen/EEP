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

    int server_fd;
    struct sockaddr_in cliaddr;

    if (!net_client(&server_fd, &cliaddr))
        return 2;

    char *msg_str = msg_create_str((char *)argv[1], (char *)argv[2], strlen(argv[2]), (char *)argv[3], strlen(argv[3]));

    if (!msg_str)
    {
        cmc_log_fatal("Could not create a valid message from given parameters.");
        close(server_fd);
        return 3;
    }

    struct msg_message msg;

    if (!msg_parse(msg_str, strlen(msg_str), &msg))
    {
        cmc_log_fatal("Could not parse back the message created from the parameters.");
        close(server_fd);
        free(msg_str);
        return 4;
    }

    free(msg_str);

    if (msg.ctrl == MSG_CTRL_SHUTDOWN)
    {
        net_shutdown(server_fd, msg.key);
    }
    else if (msg.ctrl == MSG_CTRL_CREATE)
    {
        net_create(server_fd, msg.key, msg.val);
    }
    else if (msg.ctrl == MSG_CTRL_READ)
    {
        char *result;
        if (net_read(server_fd, msg.key, &result))
        {
            cmc_log_info("Got value from server: %s", result);
        }
    }

    msg_message_destroy(&msg);
    close(server_fd);

    return 0;
}
