/**
 * A higher level API with a the standard communication
 */

#ifndef NETAPI_H
#define NETAPI_H

#include <errno.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

/**
 * net_server           -> Creates a server connection
 *      net_accept      -> Accepts connections from clients
 *      net_callback    -> Sends data back to client
 * net_client           -> Creates a client connection
 *      net_receive     -> Receives message error from server
 *      net_shutdown    -> Shutdowns the server
 *      net_ping        -> Pings the server
 *      net_create      -> Creates an entry
 *      net_read        -> Reads an entry
 *      net_update      -> Updates an entry
 *      net_delete      -> Deletes an entry
 *      net_save        -> Saves a backup
 * Client/Server
 *      net_recv     -> Receive message from socket
 *      net_send     -> Send message to socket
 */

#define NETAPI_SERVER_PORT 1234

typedef char netapi_recv_buffer[2000];

bool net_server(int *out_fd, struct sockaddr_in *out_server);
bool net_client(int *out_fd, struct sockaddr_in *out_client);

bool net_accept(int server_fd, int *out_client_fd, struct sockaddr_in *out_client);

bool net_send(int fd, void *data, size_t data_len);

#endif /* NETAPI_H */
