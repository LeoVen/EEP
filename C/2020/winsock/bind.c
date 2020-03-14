#include <stdio.h>
#include <winsock2.h>

// Bind socket to 8888 on localhost
//
// Configure WSA
// Bind socket
// Listen to connections
// Cleanup

int main(void)
{
    // Configure WSA
    WSADATA wsa;

    if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0)
    {
        fprintf(stderr, "Could not initialize winsock. Error Code : %d\n", WSAGetLastError());
        return 1;
    }

    printf("Initialized Winsock\n");

    // Create socket
    // AF_INET - IPV4
    // SOCK_STREAM - TCP
    SOCKET s = socket(AF_INET, SOCK_STREAM, 0);
    if (s == INVALID_SOCKET)
    {
        fprintf(stderr, "Could not create socket : %d\n", WSAGetLastError());
        return 1;
    }

    printf("Socket Created\n");

    // Prepare sockaddr_in struct
    SOCKADDR_IN server;

    server.sin_family = AF_INET; // IPV4
    server.sin_addr.s_addr = INADDR_ANY; // Bind socket to all available interfaces
    server.sin_port = htons(8888); // Port 8888

    // Bind socket
    if (bind(s, (struct sockaddr *)&server, sizeof(server)) == SOCKET_ERROR)
    {
        fprintf(stderr, "Bind failed : %d\n", WSAGetLastError());
        return 1;
    }

    printf("Bind Created\n");

    // Listen to connections
    listen(s, 3);

    printf("Waiting for connections...\n");

    // Extract first pending connection from the queue
    struct sockaddr_in client;
    int addrlen = sizeof(struct sockaddr_in);
    SOCKET new_socket = accept(s, (struct sockaddr *)&client, &addrlen);

    if (new_socket == INVALID_SOCKET)
    {
        fprintf(stderr, "Accept failed : %d\n", WSAGetLastError());
        return 1;
    }

    printf("Connection Accepted\n");

    // Get client IP and Port
    char *client_ip = inet_ntoa(client.sin_addr);
    int client_port = ntohs(client.sin_port);

    printf("Hello %s:%d\n", client_ip, client_port);

    // Cleanup
    closesocket(s);
    WSACleanup();

    return 0;
}
