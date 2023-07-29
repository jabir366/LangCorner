#include <iostream>
#include <stdio.h>
#include <string.h>
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
  sockaddr.sin_port = htons(1111);
  sockaddr.sin_addr.s_addr = INADDR_ANY;
  if (bind(socketfd, (struct sockaddr *)&sockaddr, sizeof(sockaddr)) < 0) {
    std::cout << "Error binding socket\n";
    return 1;
  }

  // Send the data.
  char data[] = "Hello, world!";
  int ret = sendto(socketfd, data, strlen(data), 0, (struct sockaddr *)&sockaddr, sizeof(sockaddr));
  if (ret < 0) {
    std::cout << "Error sending data\n";
    return 1;
  }

  // Close the socket.
  close(socketfd);

  return 0;
}
