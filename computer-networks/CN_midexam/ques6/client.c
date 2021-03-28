#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <netinet/in.h>
#define arrsize 1024

int main(int argc, char * argv[]) {
	if(argc < 2)
		perror("Usage: ./client <port>");

	struct sockaddr_in s_addr; char buf[arrsize];
	int sfd = socket(AF_INET, SOCK_STREAM, 0);
	if(sfd == -1) perror("socket() error")
	memset((char *)&s_addr, 0, sizeof(s_addr));
	s_addr.sin_family = AF_INET;
	s_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	s_addr.sin_port = htons((u_short)atoi(argv[1]));
	if((connect(sfd, (struct sockaddr *)&s_addr, sizeof(s_addr))) < 0)
		perror("connect() error");
	fd_set rfds;
	while(1) {
		FD_ZERO(&rfds);
		FD_SET(sfd, &rfds);
		if((select(sfd+1, &rfds, NULL, NULL, NULL)) < 0) 
		{
			sleep(0.2);
			continue;
		}
		if(FD_ISSET(sfd, &rfds)) 
		{
			read(sfd, buf, arrsize);
			printf("%s\n", buf);
		}
	}
	return 0;
}
