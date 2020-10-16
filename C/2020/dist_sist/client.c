#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#include "macro_collections.h"
#include "messages.h"
#include "netapi.h"

bool read_line(char *buffer, int max_len, char *message);

int main(int argc, char const *argv[])
{
    int server_fd;
    struct sockaddr_in cliaddr;

    if (!net_client(&server_fd, &cliaddr))
        return 2;

    cmc_log_info("Connected to server...");

    while (true)
    {
        printf("Commands:\n");
        printf(" > q | Q    : Quit\n");
        printf(" > SHUTDOWN : Shuts down the server.\n");
        printf(" > CREATE   : Creates a new key-value pair.\n");
        printf(" > READ     : Retrieves an existing key-value pair.\n");

        char command[NETAPI_RECV_BUFFER_SIZE] = { 0 };

        if (!read_line(command, NETAPI_RECV_BUFFER_SIZE, "Command"))
            continue;

        if (command[0] == 'q' || command[0] == 'Q')
        {
            cmc_log_info("Logging off.");
            break;
        }

        char key[100], val[100], *result;
        enum message_control ctrl = msg_string_to_ctrl(command);

        if (ctrl == MSG_CTRL_SHUTDOWN)
        {
            if (!read_line(key, sizeof(key), "Reason for shutdown"))
                continue;

            if (!net_shutdown(server_fd, key))
                break;
        }
        else if (ctrl == MSG_CTRL_CREATE)
        {
            if (!read_line(key, sizeof(key), "Key"))
                continue;
            if (!read_line(val, sizeof(val), "Value"))
                continue;

            if (!net_create(server_fd, key, val))
                break;
        }
        else if (ctrl == MSG_CTRL_READ)
        {
            if (!read_line(key, sizeof(key), "Key"))
                continue;

            if (!net_read(server_fd, key, &result))
                break;

            printf("[ Result ] > %s\n", result);
            free(result);
        }
    }

    close(server_fd);

    return 0;
}

bool read_line(char *buffer, int max_len, char *message)
{
    printf("[ %s ] > ", message);

    if (!fgets(buffer, max_len, stdin))
    {
        cmc_log_error("Couldn't read command.");
        return false;
    }

    int i = NETAPI_RECV_BUFFER_SIZE - 1;
    for (; i > 0; i--)
    {
        if (buffer[i] == '\n')
        {
            buffer[i] = 0;
            break;
        }
    }

    if (i == 0)
    {
        cmc_log_error("Couldn't read command.");
        return false;
    }

    return true;
}
