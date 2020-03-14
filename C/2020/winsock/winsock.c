#include <stdio.h>
#include <winsock2.h>

// Create a TCP socket, send data and receive a reply
//
// Configure WSA
// Create socket
// Connect to remove server
// Sending data
// Receive reply from the server
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
    }

    printf("Socket Created\n");

    // Connect to remove server
    SOCKADDR_IN server;

    // Prepare sockaddr_in struct
    server.sin_addr.s_addr = inet_addr("172.217.29.14"); // Utility to transform address to integer
    server.sin_family = AF_INET; // IPV4
    server.sin_port = htons(80); // HTTP port

    if (connect(s, (PSOCKADDR)&server, sizeof(server)) < 0)
    {
        fprintf(stderr, "Connection Error\n");
        return 1;
    }

    printf("Connected to Server\n");

    // Sending data
    const char *message = "GET / HTTP/1.1\r\n\r\n"; // Request for the main page of the server
    if (send(s, message, strlen(message), 0) < 0)
    {
        fprintf(stderr, "Send Data Failed\n");
        return 1;
    }

    printf("Data Sent\n");

    // Receive reply from the server
    char server_reply[2001];
	int recv_size = recv(s, server_reply, 2000, 0);
    if (recv_size == SOCKET_ERROR)
    {
        fprintf(stderr, "Could not receive reply from server\n");
        return 1;
    }

    server_reply[recv_size] = '\0';
    printf("Server Reply:\n\n%s\n", server_reply);

    // Cleanup
    closesocket(s);
    WSACleanup();

    return 0;
}
