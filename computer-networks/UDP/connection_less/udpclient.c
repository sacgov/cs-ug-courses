/********************************************************
* Author 	: Sachin Govind
* Date   	: 21 March 2016 (Monday)
* Title		: UDP Client
********************************************************/
// Info : using SOCK_DGRAM connection less 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <pthread.h>

#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <netinet/in.h>

#define BUFSIZE 1024
#define eerror(msg) printf("%s\n", msg),exit(1);


int main(int argc, char * argv[]) {
	int port;
	if(argc == 1) {
		port = 9500;
	} else {
		port = atoi(argv[1]);
	}
	struct sockaddr_in s_addr; int cli_len, sfd, nsfd, i; char buf[BUFSIZE];
	memset((char *)&s_addr, 0, sizeof(s_addr));
	sfd = socket(AF_INET, SOCK_DGRAM, 0);
	if(sfd == -1) {
		eerror("socket() error");
	}
	s_addr.sin_family = AF_INET;
	s_addr.sin_port = htons((u_short) port);
	s_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	while(1)
	{
		memset(buf, 0, BUFSIZE);
		scanf("%s",buf);
		if(sendto(sfd, buf, strlen(buf), 0, (struct sockaddr *)&s_addr, sizeof(s_addr)) < 0) {
			eerror("sendto() error");
		}
		//printf("%s\n", buf);
		cli_len = sizeof(s_addr);
		memset(buf, 0, BUFSIZE);
		if(recvfrom(sfd, buf, BUFSIZE, 0, (struct sockaddr *)&s_addr, &cli_len) < 0) {
			eerror("recvfrom() error");
		}
		printf("%s\n", buf);
	}
	close(sfd);
	return 0;
}
