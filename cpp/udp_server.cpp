#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main() {
  // Create a UDP socket.
  int socketfd = socket(AF_INET, SOCK_DGRAM, 0);
  if (socketfd < 0) {
    std::cout << "Error creating socket\n";
    return 1;
  }

  // Bind the socket to the socket address.
  struct sockaddr_in sockaddr;
  sockaddr.sin_family = AF_INET;
  sockaddr.sin_port = htons(8080);
  sockaddr.sin_addr.s_addr = INADDR_ANY;
  if (bind(socketfd, (struct sockaddr *)&sockaddr, sizeof(sockaddr)) < 0) {
    std::cout << "Error binding socket\n";
    return 1;
  }

  // Receive the data.
  char data[1024];
  socklen_t sockaddr_len = sizeof(sockaddr);
  int ret = recvfrom(socketfd, data, sizeof(data), 0, (struct sockaddr *)&sockaddr, &sockaddr_len);
  if (ret < 0) {
    std::cout << "Error receiving data\n";
    return 1;
  }

  // Print the data.
  std::cout << "Received: " << data << std::endl;

  // Close the socket.
  close(socketfd);

  return 0;
}
