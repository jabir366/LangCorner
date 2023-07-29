#include <iostream>
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <cstring>
#include <unistd.h>

int main() {
    // Create a UDP socket for IPv4.
    int socketIPv4 = socket(AF_INET, SOCK_DGRAM, 0);
    if (socketIPv4 < 0) {
        std::cout << "Error creating IPv4 socket\n";
        return 1;
    }

    // Create a UDP socket for IPv6.
    int socketIPv6 = socket(AF_INET6, SOCK_DGRAM, 0);
    if (socketIPv6 < 0) {
        std::cout << "Error creating IPv6 socket\n";
        return 1;
    }

    // Configure the server address for IPv4.
    struct sockaddr_in serverAddressIPv4;
    serverAddressIPv4.sin_family = AF_INET;
    serverAddressIPv4.sin_port = htons(8080);
    if (inet_pton(AF_INET, "127.0.0.1", &(serverAddressIPv4.sin_addr)) <= 0) {
        std::cout << "Error configuring IPv4 server address\n";
        return 1;
    }

    // Configure the server address for IPv6.
    struct sockaddr_in6 serverAddressIPv6;
    serverAddressIPv6.sin6_family = AF_INET6;
    serverAddressIPv6.sin6_port = htons(8080);
    if (inet_pton(AF_INET6, "::1", &(serverAddressIPv6.sin6_addr)) <= 0) {
        std::cout << "Error configuring IPv6 server address\n";
        return 1;
    }

    // Send data using IPv4.
    const char* dataIPv4 = "Hello, IPv4 server!";
    int retIPv4 = sendto(socketIPv4, dataIPv4, strlen(dataIPv4), 0, (struct sockaddr*)&serverAddressIPv4,
                         sizeof(serverAddressIPv4));
    if (retIPv4 < 0) {
        std::cout << "Error sending data via IPv4\n";
        return 1;
    }

    // Send data using IPv6.
    const char* dataIPv6 = "Hello, IPv6 server!";
    int retIPv6 = sendto(socketIPv6, dataIPv6, strlen(dataIPv6), 0, (struct sockaddr*)&serverAddressIPv6,
                         sizeof(serverAddressIPv6));
    if (retIPv6 < 0) {
        std::cout << "Error sending data via IPv6\n";
        return 1;
    }

    // Close the sockets.
    close(socketIPv4);
    close(socketIPv6);

    return 0;
}

