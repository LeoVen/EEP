/**
 * A higher level API with a the standard communication
 */

#ifndef NETAPI_H
#define NETAPI_H

#include <errno.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/socket.h>
#include <arpa/inet.h>

/**
 * net_server           -> Creates a server connection
 *      net_accept      -> Accepts connections from clients
 *      net_callback    -> Sends data back to client
 * net_client           -> Creates a client connection
 *      net_shutdown    -> Shutdowns the server
 *      net_create      -> Creates an entry
 *      net_read        -> Reads an entry
 *      net_update      -> Updates an entry
 *      net_delete      -> Deletes an entry
 *      net_save        -> Saves a backup
 * Client/Server
 *      net_sockopt     -> Some default socket options
 *      net_recv        -> Receive message from socket
 *      net_send        -> Send message to socket
 */

#ifndef NETAPI_SERVER_PORT
#define NETAPI_SERVER_PORT 1234
#endif

#ifndef NETAPI_RECV_BUFFER_SIZE
#define NETAPI_RECV_BUFFER_SIZE 2000
#endif

#ifndef NETAPI_TIMEOUT
#define NETAPI_SERVER_TIMEOUT 300 // In seconds
#endif

#ifndef NETAPI_CLIENT_TIMEOUT
#define NETAPI_CLIENT_TIMEOUT 2 // In seconds
#endif

typedef char netapi_recv_buffer[NETAPI_RECV_BUFFER_SIZE];

/* Connections */
/**
 * Creates a server connection
 */
bool net_server(int *out_fd, struct sockaddr_in *out_server);

/**
 * Creates a client connection
 */
bool net_client(int *out_fd, struct sockaddr_in *out_client, char *client_id);

/* Server-only */
bool net_accept(int server_fd, int *out_client_fd, struct sockaddr_in *out_client);
bool net_callback(int client_fd, char *error_message);

/* Client-only */
bool net_shutdown(int server_fd, char *reason);
bool net_create(int server_fd, char *key, char *val);
bool net_read(int server_fd, char *key, char **out_val);
bool net_update(int server_fd, char *key, char *val);

/* Lower level */
bool net_sockopt(int socket_fd, int seconds);
bool net_send(int fd, void *data, size_t data_len);
bool net_recv(int fd, netapi_recv_buffer out_buffer, ssize_t *out_len);

#endif /* NETAPI_H */
