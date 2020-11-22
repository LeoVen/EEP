#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#include "macro_collections.h"

#define TC_COLOR
#define MAX_CHARS 100

#include "mail.h"
#include "messages.h"
#include "netapi.h"
#include "terminal_color.h"

bool read_line(char *buffer, int max_len, char *message);

int main(void)
{
    int server_fd;
    struct sockaddr_in cliaddr;
    char id[MAX_CHARS];

    if (!read_line(id, MAX_CHARS, "ID"))
    {
        cmc_log_fatal("Invalid client ID.");
        return 1;
    }

    if (!net_client(&server_fd, &cliaddr, id))
        return 3;

    cmc_log_info("Connected to server...");

    while (true)
    {
        printf("\n%sCommands%s:\n", tc_green(), tc_reset());
        printf(" > %sq%s | %sQ%s     : Quit\n", tc_blue(), tc_reset(), tc_blue(), tc_reset());
        printf(" > %sSHUTDOWN%s  : Shuts down the server.\n", tc_blue(), tc_reset());
        printf(" > %sCREATE%s    : Creates a new key-value pair.\n", tc_blue(), tc_reset());
        printf(" > %sREAD%s      : Retrieves an existing key-value pair.\n", tc_blue(), tc_reset());
        printf(" > %sUPDATE%s    : Updates an existing key-value pair.\n", tc_blue(), tc_reset());
        printf(" > %sDELETE%s    : Deletes an existing key-value pair.\n", tc_blue(), tc_reset());
        printf(" > %sMAIL_SEND%s : Send an e-mail to another client.\n", tc_blue(), tc_reset());
        printf(" > %sMAIL_RECV%s : Receive all e-mails stored in the server.\n", tc_blue(), tc_reset());

        char command[MAX_CHARS] = { 0 };

        if (!read_line(command, 100, "Command"))
            continue;

        if (command[0] == 'q' || command[0] == 'Q')
        {
            cmc_log_info("Logging off.");
            break;
        }

        char key[MAX_CHARS], val[MAX_CHARS], *result;
        enum message_control ctrl = msg_string_to_ctrl(command);

        if (ctrl == MSG_CTRL_SHUTDOWN)
        {
            if (!read_line(key, sizeof(key), "Reason for shutdown"))
                continue;

            net_shutdown(server_fd, key);
            break;
        }
        else if (ctrl == MSG_CTRL_CREATE)
        {
            if (!read_line(key, sizeof(key), "Key"))
                continue;
            if (!read_line(val, sizeof(val), "Value"))
                continue;

            if (!net_create(server_fd, key, val))
                continue;
        }
        else if (ctrl == MSG_CTRL_READ)
        {
            if (!read_line(key, sizeof(key), "Key"))
                continue;

            if (!net_read(server_fd, key, &result))
                continue;

            printf("%s[%s Result %s]%s > %s%s%s\n", tc_red(), tc_reset(), tc_red(), tc_reset(), tc_yellow(), result, tc_reset());
            free(result);
        }
        else if (ctrl == MSG_CTRL_UPDATE)
        {
            if (!read_line(key, sizeof(key), "Key"))
                continue;
            if (!read_line(val, sizeof(val), "Value"))
                continue;

            if (!net_update(server_fd, key, val))
                continue;
        }
        else if (ctrl == MSG_CTRL_DELETE)
        {
            if (!read_line(key, sizeof(key), "Key"))
                continue;

            if (!net_delete(server_fd, key))
                continue;
        }
        else if (ctrl == MSG_CTRL_MAIL_SEND)
        {
            if (!read_line(key, sizeof(key), "ClientId"))
                continue;
            if (!read_line(val, sizeof(val), "Message"))
                continue;

            if (!net_mail_send(server_fd, key, val))
                continue;
        }
        else if (ctrl == MSG_CTRL_MAIL_RECV)
        {
            struct msglist *result;
            if (!net_mail_recv(server_fd, id, &result))
                continue;

            // TODO print emails
        }
        else
        {
            cmc_log_error("Unknown command");
        }
    }

    close(server_fd);

    return 0;
}

bool read_line(char *buffer, int max_len, char *message)
{
    printf("%s[%s %s %s]%s > ", tc_red(), tc_reset(), message, tc_red(), tc_reset());

    if (!fgets(buffer, max_len, stdin))
    {
        cmc_log_error("Couldn't read command.");
        return false;
    }

    int i = 0;
    for (; i < max_len; i++)
    {
        if (buffer[i] == '\n')
        {
            buffer[i] = '\0';
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
