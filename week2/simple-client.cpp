/* run client using: ./client localhost <server_port> */

#include <bits/stdc++.h>
#include<stdio.h>
#include <unistd.h>

#include <netdb.h>

using namespace std;

void error(string msg) {
  perror(msg.c_str());
  exit(0);
}

int main(int argc, char *argv[]) {
  int sockfd, portno, n;

  // These structures are already defined in header files
  struct sockaddr_in serv_addr;
  struct hostent *server;

  // Buffer is character stream which will be used to store and transfer data
  char buffer[256];
  if (argc < 3) {
    cerr<< "usage "<< argv[0]<< " hostname port\n";
    exit(0);
  }

  /* create socket, get sockfd handle */

  portno = atoi(argv[2]);
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  // If socket does not exist it will return -1
  if (sockfd < 0)
    error("ERROR opening socket");

  /* fill in server address in sockaddr_in datastructure */

  server = gethostbyname(argv[1]);
  if (server == NULL) {
    cerr<< "Error, no such host\n";
    exit(0);
  }

  // memset will set complete memory as 0 or -1 depending on function call
  // bzero was used initally but I have replaced it with memset because 
  // bzero is not ISO C
  memset((char *)&serv_addr,0, sizeof(serv_addr));
  
  // AF_NET means the communication is IPV4
  serv_addr.sin_family = AF_INET;

  //memcpy will copy n bytes from source to destination
  //bcopy was used and removed for similar reasons as bzero
  memcpy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr,
        server->h_length);

  //htons convert short integer from host byte order to network byte order
  serv_addr.sin_port = htons(portno);

  /* connect to server */

  if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    error("ERROR connecting");

  /* ask user for input */

  cout<< "Please enter the message: ";
  memset(buffer,0, 256);
  fgets(buffer, 255, stdin);

  /* send user message to server */

  n = write(sockfd, buffer, strlen(buffer));
  if (n < 0)
    error("ERROR writing to socket");
  bzero(buffer, 256);

  /* read reply from server */

  n = read(sockfd, buffer, 255);
  if (n < 0)
    error("ERROR reading from socket");
  cout<< "Server response: "<<  buffer<< "\n";

  return 0;
}
