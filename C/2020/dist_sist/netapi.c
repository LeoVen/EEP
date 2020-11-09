#include "messages.h"
#include "macro_collections.h"
#include "netapi.h"

// Sets default socket options
bool net_sockopt(int socket_fd, int seconds)
{
    struct timeval tv;
    tv.tv_sec = seconds;
    tv.tv_usec = 0;
    if (setsockopt(socket_fd, SOL_SOCKET, SO_RCVTIMEO, (const char *)&tv, sizeof(struct timeval)) < 0)
    {
        cmc_log_fatal("Could not set default socket options.");
        perror("");
        return false;
    }
    return true;
}

bool net_server(int *out_fd, struct sockaddr_in *out_server)
{
    *out_fd = socket(AF_INET, SOCK_STREAM, 0);

    if (*out_fd < 0)
    {
        cmc_log_error("Error creating server socket file descriptor.");
        perror("");
        return false;
    }
    else
    {
        cmc_log_debug("Opened server socket successfully.");
    }

    if (!net_sockopt(*out_fd, NETAPI_SERVER_TIMEOUT))
        return false;

    memset(out_server, 0, sizeof(struct sockaddr_in));
    out_server->sin_addr.s_addr = INADDR_ANY;
    out_server->sin_family = AF_INET;
    out_server->sin_port = htons(NETAPI_SERVER_PORT);

    if (bind(*out_fd, (struct sockaddr *)out_server, sizeof(struct sockaddr_in)) < 0)
    {
        cmc_log_error("Could not bind to server socket.");
        perror("");
        return false;
    }
    else
    {
        cmc_log_debug("Binded to server socket successfully.");
    }

    if (listen(*out_fd, 3) < 0)
    {
        cmc_log_error("Could not listen to server socket.");
        perror("");
        return false;
    }

    cmc_log_info("Listening to connections at %d...", NETAPI_SERVER_PORT);

    return true;
}

bool net_client(int *out_fd, struct sockaddr_in *out_client, char *client_id)
{
    /* Connection to server */
    *out_fd = socket(AF_INET, SOCK_STREAM, 0);

    if (*out_fd < 0)
    {
        cmc_log_error("Error creating client socket file descriptor.");
        perror("");
        return false;
    }
    else
    {
        cmc_log_debug("Opened client socket successfully.");
    }

    if (!net_sockopt(*out_fd, NETAPI_CLIENT_TIMEOUT))
        return false;

    memset(out_client, 0, sizeof(struct sockaddr_in));
    out_client->sin_addr.s_addr = INADDR_ANY;
    out_client->sin_family = AF_INET;
    out_client->sin_port = htons(NETAPI_SERVER_PORT);

    if (connect(*out_fd, (struct sockaddr *)out_client, sizeof(struct sockaddr_in)) < 0)
    {
        cmc_log_error("Could not connect to client socket: %d", NETAPI_SERVER_PORT);
        perror("");
        return false;
    }
    else
    {
        cmc_log_debug("Connected to socket %d", NETAPI_SERVER_PORT);
    }

    /**/

    if (!net_send(*out_fd, client_id, strlen(client_id)))
    {
        cmc_log_fatal("Could not send client's ID to server.");
        return false;
    }

    return true;
}

bool net_accept(int server_fd, int *out_client_fd, struct sockaddr_in *out_client, int *out_mail_fd)
{
    socklen_t len = sizeof(struct sockaddr_in);

    int client_fd = accept(server_fd, (struct sockaddr *)out_client, &len);

    if (client_fd < 0)
        return false;

    *out_client_fd = client_fd;

    return true;
}

bool net_callback(int client_fd, char *error_message)
{
    static char *key = "RESULT";
    char *msg = msg_create(MSG_CTRL_CALLBACK, key, strlen(key), error_message, strlen(error_message));

    if (!msg)
    {
        cmc_log_error("Could not create key-value pair: %s.", error_message);
        return false;
    }

    if (!net_send(client_fd, msg, strlen(msg)))
    {
        cmc_log_error("Could not send callback to client.");
        free(msg);
        return false;
    }

    free(msg);
    return true;
}

bool net_shutdown(int server_fd, char *reason)
{
    char *msg_send = msg_create(MSG_CTRL_SHUTDOWN, reason, strlen(reason), "", 0);

    if (!msg_send)
    {
        cmc_log_error("Could not shutdown server.");
        return false;
    }

    if (!net_send(server_fd, msg_send, strlen(msg_send)))
    {
        cmc_log_error("Could not send shutdown data to server.");
        free(msg_send);
        return false;
    }

    free(msg_send);

    // Dummy client to trigger server shutdown
    int dummy;
    struct sockaddr_in dummyaddr;

    if (!net_client(&dummy, &dummyaddr, "Dummy Connection for Shutdown"))
    {
        cmc_log_error("Failed to shutdown server.");
        return false;
    }

    close(dummy);

    return true;
}

bool net_create(int server_fd, char *key, char *val)
{
    char *msg_send = msg_create(MSG_CTRL_CREATE, key, strlen(key), val, strlen(val));

    if (!msg_send)
    {
        cmc_log_error("Could not create key-value pair.");
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

bool net_read(int server_fd, char *key, char **out_val)
{
    char *msg_send = msg_create(MSG_CTRL_READ, key, strlen(key), "", 0);

    if (!msg_send)
    {
        cmc_log_error("Could not create key-value pair.");
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
        cmc_log_error("Could not receive callback from server");
    }

    struct msg_message msg_recv;

    if (!msg_parse(reply, strlen(reply), &msg_recv))
    {
        cmc_log_error("Could not parse callback from server.");
        return false;
    }

    if (strcmp(msg_recv.key, "OK") != 0)
    {
        cmc_log_error("%s", msg_recv.key);
        msg_message_destroy(&msg_recv);
        return false;
    }

    *out_val = msg_recv.val;
    free(msg_recv.key);

    return true;
}

bool net_update(int server_fd, char *key, char *val)
{
    char *msg_send = msg_create(MSG_CTRL_UPDATE, key, strlen(key), val, strlen(val));

    if (!msg_send)
    {
        cmc_log_error("Could not update key-value pair.");
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

bool net_send(int fd, void *data, size_t data_len)
{
    ssize_t len = send(fd, data, data_len, 0);

    if (len < 0)
    {
        cmc_log_error("Could not send message to socket at %d", NETAPI_SERVER_PORT);
        return false;
    }
    else if (len == 0)
    {
        cmc_log_warn("Message sent to %d was 0 bytes long.", NETAPI_SERVER_PORT);
    }

    cmc_log_trace("Sent %d bytes", len);

    return true;
}

bool net_recv(int fd, netapi_recv_buffer out_buffer, ssize_t *out_len)
{
    *out_len = recv(fd, out_buffer, sizeof(netapi_recv_buffer) - 1, 0);

    if (*out_len < 0)
    {
        cmc_log_warn("Data received was not valid.");
        perror("");
        return false;
    }
    else if (*out_len == 0)
    {
        cmc_log_warn("Received empty message.");
    }

    out_buffer[*out_len] = '\0';

    return true;
}
