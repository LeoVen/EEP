#include "netapi.h"
#include "macro_collections.h"

bool net_server(int *out_fd, struct sockaddr_in *out_server)
{
    *out_fd = socket(AF_INET, SOCK_STREAM, 0);

    if (*out_fd < 0)
    {
        cmc_log_error("Error creating socket file descriptor.");
        perror("");
        return false;
    }
    else
    {
        cmc_log_info("Opened socket successfully.");
    }

    memset(out_server, 0, sizeof(struct sockaddr_in));
    out_server->sin_addr.s_addr = INADDR_ANY;
    out_server->sin_family = AF_INET;
    out_server->sin_port = htons(NETAPI_SERVER_PORT);
    
    if (bind(*out_fd, (struct sockaddr *)out_server, sizeof(struct sockaddr_in)) < 0)
    {
        cmc_log_error("Could not bind to socket.");
        perror("");
        return false;
    }
    else
    {
        cmc_log_info("Binded to socket successfully.");
    }

    if (listen(*out_fd, 3) < 0)
    {
        cmc_log_error("Could not listen to socket.");
        perror("");
        return false;
    }

    cmc_log_info("Listening to connections at %d...", NETAPI_SERVER_PORT);

    return true;
}

bool net_client(int *out_fd, struct sockaddr_in *out_client)
{
    *out_fd = socket(AF_INET, SOCK_STREAM, 0);

    if (*out_fd < 0)
    {
        cmc_log_error("Error creating socket file descriptor.");
        perror("");
        return false;
    }
    else
    {
        cmc_log_info("Opened socket successfully.");
    }

    memset(out_client, 0, sizeof(struct sockaddr_in));
    out_client->sin_addr.s_addr = INADDR_ANY;
    out_client->sin_family = AF_INET;
    out_client->sin_port = htons(NETAPI_SERVER_PORT);

    if (connect(*out_fd, (struct sockaddr *)out_client, sizeof(struct sockaddr_in)) < 0)
    {
        cmc_log_error("Could not connect to socket: %d", NETAPI_SERVER_PORT);
        return false;
    }
    else
    {
        cmc_log_info("Connected to socket %d", NETAPI_SERVER_PORT);
    }

    return true;
}

bool net_accept(int server_fd, int *out_client_fd, struct sockaddr_in *out_client)
{
    socklen_t len = sizeof(struct sockaddr_in);

    int client_fd = accept(server_fd, (struct sockaddr *)out_client, &len);

    if (client_fd < 0)
        return false;

    *out_client_fd = client_fd;

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

    cmc_log_info("Sent %d bytes", len);

    return true;
}
