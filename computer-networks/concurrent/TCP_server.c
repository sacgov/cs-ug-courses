#include <sys/types.h>
#include <netinet/in.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>

#define maxd 100
int main()
{
	int sfd,connected,bytes_recv;
	char send_data[maxd],recv_data[maxd];
	struct sockaddr_in server_addr,client_addr;
	if((sfd = socket(AF_INET,SOCK_STREAM,0))==-1)
	{
		perror("Socket ready error");
		exit(1);
	}

	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(5000);
	server_addr.sin_addr.s_addr = INADDR_ANY; //load with inet_ntoa();
	bzero(&(server_addr.sin_zero),8);

	if(bind(sfd,(struct sockaddr *)&server_addr,sizeof(server_addr)) == -1)
	{
		perror("bind error");
		exit(1);
	}
	if(listen(sfd,5) == -1)
	{
		perror("listen error");
		exit(1);
	}
	printf("Server is running on port 5000\n");

	while(1)
	{
		int clisize = sizeof(struct sockaddr_in);
		connected = accept(sfd,(struct sockaddr *)&client_addr,&clisize);
		printf("connected to %s %d\n",inet_ntoa(client_addr.sin_addr),ntohs(client_addr.sin_port) );
		pid_t c = fork();
		if(c==0)
		{
			while(1)
			{
				printf("ENTER Send data\n");
				fgets(send_data,maxd,stdin);
				send(connected,send_data,strlen(send_data),0);
				bytes_recv = recv(connected,recv_data,maxd,0);
				recv_data[bytes_recv] = '\0';
				printf("%s\n",recv_data );
				if(recv_data[0] == 'q')
					break;
			}
			exit(1);
		}
		close(connected);
		
	}
	return 0;
	
}