#include <stdio.h>
#include <winsock2.h>

// Get IP address from domain name
//
// Configure WSA
// Get Hostname
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

    // Get Hostname
    char *hostname = "www.google.com";
    struct hostent *he = gethostbyname(hostname);

    if (he == NULL)
    {
        fprintf(stderr, "Could not get hostname (%s) : %d\n", hostname, WSAGetLastError());
        return 1;
    }

    printf("Acquired IP Addresses\n");

    // Get the IP address
    struct in_addr **addr_list = (struct in_addr **)he->h_addr_list;

    char ip[100];
    strcpy(ip, inet_ntoa(*addr_list[0])); // Get the first address

    printf("Host (%s) Address is:\n\n%s\n", hostname, ip);

    // Cleanup
    WSACleanup();

    return 0;
}
