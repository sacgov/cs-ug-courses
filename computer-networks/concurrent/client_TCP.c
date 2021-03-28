#include <sys/types.h>
#include <netinet/in.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <string.h>
#include <errno.h>
#include <netdb.h>
#include <sys/socket.h>

#define maxd 100
int main()
{
	int sfd,bytes_recv;
	char send_data[maxd],recv_data[maxd];
	struct sockaddr_in server_addr,client_addr;
	struct hostent * host;
	host = gethostbyname("127.0.0.1");
	if((sfd = socket(AF_INET,SOCK_STREAM,0))==-1)
	{
		perror("Socket ready error");
		exit(1);
	}

	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(5000);
	server_addr.sin_addr= *((struct in_addr *)host->h_addr); //load with inet_ntoa();
	bzero(&(server_addr.sin_zero),8);
	if(connect(sfd,(struct sockaddr *)&server_addr,sizeof(struct sockaddr)) == -1)
	{
		perror("connect Error");
	}
	printf("lololl\n");
	while(1)
	{
		bytes_recv = recv(sfd,recv_data,maxd,0);
		recv_data[bytes_recv] = '\0';
		printf("%s\n",recv_data );
		printf("ENTER Send data\n");
		fgets(send_data,maxd,stdin);
		send(sfd,send_data,strlen(send_data),0);
		if(send_data[0] == 'q')
		{
			close(sfd);
			break;

		}		
	}
}