#include <stdlib.h>
#include <stdio.h>
#include <sys/type.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>

#define MAXLINE 4096 /*max text line length*/
#define SERV_PORT 3000

int main(int argc, char const *argv[])
{
	int sockfd;
	struct sockaddr_in servaddr;
	char sendline[MAXLINE], recvline[MAXLINE];

	
	if (argc !=2) {
		perror("Usage: TCPClient <IP address of the server"); 
		exit(1);
	}

	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if(sockfd < 0){
		perror("Problem in creating socket");
		exit(2);
	}

	



	return 0;
}