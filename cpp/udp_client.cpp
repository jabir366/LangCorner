#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main() {
  // Create a UDP socket.
  int socketfd = socket(AF_INET, SOCK_DGRAM, 0);
  if (socketfd < 0) {
    std::cout << "Error creating socket\n";
    return 1;
  }

  // Configure the server address.
  struct sockaddr_in serverAddress;
  serverAddress.sin_family = AF_INET;
  serverAddress.sin_port = htons(8080);
  serverAddress.sin_addr.s_addr = INADDR_ANY;

  // Send the data to the server.
  char data[] = "Hello, server!";
  int ret = sendto(socketfd, data, strlen(data), 0, (struct sockaddr *)&serverAddress, sizeof(serverAddress));
  if (ret < 0) {
    std::cout << "Error sending data\n";
    return 1;
  }

  // Receive the response from the server.
  char buffer[1024];
  socklen_t serverAddressLength = sizeof(serverAddress);
  ret = recvfrom(socketfd, buffer, sizeof(buffer), 0, (struct sockaddr *)&serverAddress, &serverAddressLength);
  if (ret < 0) {
    std::cout << "Error receiving data\n";
    return 1;
  }

  // Print the received response.
  std::cout << "Server response: " << buffer << std::endl;

  // Close the socket.
  close(socketfd);

  return 0;
}

