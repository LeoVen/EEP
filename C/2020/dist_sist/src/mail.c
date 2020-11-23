#define TC_COLOR
#include "mail.h"
#include "terminal_color.h" // TODO Remove

bool net_mail_send(int server_fd, char *destination_id, char *message)
{
    char *key = destination_id;
    char *val = message;
    char *msg_send = msg_create(MSG_CTRL_MAIL_SEND, key, strlen(key), val, strlen(val));

    if (!msg_send)
    {
        cmc_log_error("Could not create mail message.");
        return false;
    }

    if (!net_send(server_fd, msg_send, strlen(msg_send)))
    {
        cmc_log_error("Could not send data to server.");
        free(msg_send);
        return false;
    }

    free(msg_send);

    netapi_recv_buffer reply;
    ssize_t reply_len;

    if (!net_recv(server_fd, reply, &reply_len))
    {
        cmc_log_error("Could not receive callback from server.");
    }

    struct msg_message msg_recv;

    if (!msg_parse(reply, strlen(reply), &msg_recv))
    {
        cmc_log_error("Could not parse callback from server");
        return false;
    }

    if (strcmp(msg_recv.val, "OK") != 0)
    {
        cmc_log_error("%s", msg_recv.val);
        msg_message_destroy(&msg_recv);
        return false;
    }

    cmc_log_info("Operation successfull.");

    msg_message_destroy(&msg_recv);

    return true;
}

bool net_mail_recv(int server_fd, char *client_id, struct msglist **result)
{
    char *key = "ClientId";
    char *val = client_id;
    char *msg_send = msg_create(MSG_CTRL_MAIL_RECV, key, strlen(key), val, strlen(val));

    if (!msg_send)
    {
        cmc_log_error("Could not create mail message.");
        return false;
    }

    if (!net_send(server_fd, msg_send, strlen(msg_send)))
    {
        cmc_log_error("Could not send data to server.");
        free(msg_send);
        return false;
    }

    free(msg_send);

    netapi_recv_buffer reply;
    ssize_t reply_len;

    if (!net_recv(server_fd, reply, &reply_len))
    {
        cmc_log_error("Could not receive callback from server.");
    }

    struct msg_message msg_recv;

    if (!msg_parse(reply, strlen(reply), &msg_recv))
    {
        cmc_log_error("Could not parse callback from server");
        return false;
    }

    if (strcmp(msg_recv.key, "OK") != 0)
    {
        cmc_log_error("%s", msg_recv.key);
        msg_message_destroy(&msg_recv);
        return false;
    }

    cmc_log_info("Operation successfull.");

    // TODO
    // Parse this and add to result
    printf("\n%s[%s Received Emails %s]%s\n%s%s%s", tc_red(), tc_reset(), tc_red(), tc_reset(), tc_yellow(), msg_recv.val, tc_reset());

    msg_message_destroy(&msg_recv);

    return true;
}
