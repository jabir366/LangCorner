/* #include <unistd.h> */
/*
Demonstate the inet pton, which converts a string address to socket address
*/
#include <iostream>
#include <arpa/inet.h>

int main() {
    const char* ipv4Address = "192.168.0.1";
    const char* ipv6Address = "2001:0db8:85a3:0000:0000:8a2e:0370:7334";

    // Convert IPv4 address from text to binary form
    struct in_addr ipv4BinAddress;
    if (inet_pton(AF_INET, ipv4Address, &(ipv4BinAddress.s_addr)) <= 0) {
        std::cout << "Error converting IPv4 address\n";
        return 1;
    }

    // Convert IPv6 address from text to binary form
    struct in6_addr ipv6BinAddress;
    if (inet_pton(AF_INET6, ipv6Address, &(ipv6BinAddress.s6_addr)) <= 0) {
        std::cout << "Error converting IPv6 address\n";
        return 1;
    }

    // Print the binary representation of the addresses
    std::cout << "IPv4 Address (binary): " << ipv4BinAddress.s_addr << std::endl;
    std::cout << "IPv6 Address (binary): ";
    for (int i = 0; i < 16; i++) {
        std::cout << std::hex << (int)ipv6BinAddress.s6_addr[i];
        if (i < 15) {
            std::cout << ":";
        }
    }
    std::cout << std::dec << std::endl;

    return 0;
}
