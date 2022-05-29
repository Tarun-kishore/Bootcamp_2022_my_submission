/* run using /server <port> */

#include <bits/stdc++.h>
#include <stdio.h>
#include <unistd.h>

#include <netinet/in.h>

#include <pthread.h>

using namespace std;

void error(string msg) {
  perror(msg.c_str());
  exit(1);
}

int main(int argc, char *argv[]) {
  int sockfd, newsockfd, portno;
  socklen_t clilen;
  char buffer[256];
  struct sockaddr_in serv_addr, cli_addr;
  int n;

  if (argc < 2) {
    cerr<< "ERROR, no port provided\n";
    exit(1);
  }

  /* create socket */

  // AF_INET means the communication is IPV4
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  // If error occurs sockfd = -1
  if (sockfd < 0)
    error("ERROR opening socket");

  /* fill in port number to listen on. IP address can be anything (INADDR_ANY)
   */

  // memset will set complete memory as 0 or -1 depending on function call
  // bzero was used initally but I have replaced it with memset because 
  // bzero is not ISO C
  memset((char *)&serv_addr,0, sizeof(serv_addr));
  portno = atoi(argv[1]);
  serv_addr.sin_family = AF_INET;

  //INADDR_ANY means ip address can be anything
  serv_addr.sin_addr.s_addr = INADDR_ANY;

  //htons convert short integer from host byte order to network byte order
  serv_addr.sin_port = htons(portno);

  /* bind socket to this port number on this machine */

  if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    error("ERROR on binding");

  /* listen for incoming connection requests */

  listen(sockfd, 5);
  clilen = sizeof(cli_addr);

  /* accept a new request, create a newsockfd */

  cout<< "Server running successfully. Press Ctrl-C to close the server\n";
  while(true){
  newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, &clilen);
  if (newsockfd < 0)
    error("ERROR on accept");

  /* read message from client */

  bzero(buffer, 256);
  n = read(newsockfd, buffer, 255);
  if (n < 0)
    error("ERROR reading from socket");
  cout<< "Here is the message: "<< buffer<< "\n";

  /* send reply to client */

  n = write(newsockfd,buffer, 18);
  if (n < 0)
    error("ERROR writing to socket");
}
  return 0;
}
