/********************************************************
* Author 	: Sachin Govind
* Date   	: 20 February 2016 (Saturday)
* Title		: server using TCP
********************************************************/
// Info : Implements an echo server what is written in server is displayed in client
// and what is written in client is displayed in server connects to Echo_Client.c
//Basic structures :
/*
#include <netinet/in.h>

struct sockaddr_in {
    short            sin_family;   // e.g. AF_INET
    unsigned short   sin_port;     // e.g. htons(3490)
    struct in_addr   sin_addr;     // see struct in_addr, below
    char             sin_zero[8];  // zero this if you want to
};

struct in_addr {
    unsigned long s_addr;  // load with inet_aton()
    inet_aton() returns non-zero if the address is a valid one, and it returns zero if the address is invalid.
};
*/

#include <sys/types.h>
#include <netinet/in.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <arpa/inet.h> //for big-endian ordering of number htonl number
#include <string.h>
#include <errno.h>
#include <sys/socket.h>

#define maxd 100 //max data length
int main()
{
	//server_fd,conneted is client's fd,bytes_recv is count of bytes
	int sfd,connected,bytes_recv;
	//data to send and receive
	char send_data[maxd],recv_data[maxd];
	//look above for its description
	struct sockaddr_in server_addr,client_addr;
	//sock streamaf_inet is ipv4 domain
	if((sfd = socket(AF_INET,SOCK_STREAM,0))==-1)
	{
		perror("Socket ready error");
		exit(1);
	}

	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(5000);
	server_addr.sin_addr.s_addr = INADDR_ANY; //load with inet_ntoa();
	//sock_addrin has less info than sockaddr so prevent error in typecast in some architectures
	//the zero padding is added to remove bugs and errors
	//its size is 8 
	bzero(&(server_addr.sin_zero),8);
	//binds address to the serverfd
	if(bind(sfd,(struct sockaddr *)&server_addr,sizeof(server_addr)) == -1)
	{
		perror("bind error");
		exit(1);
	}
	//max people who can connect to this sfd is five max is SOMAXCONN
	if(listen(sfd,5) == -1)
	{
		perror("listen error");
		exit(1);
	}
	printf("Server is running on port 5000\n");

	while(1)
	{
		//size of client
		int clisize = sizeof(struct sockaddr_in);
		//client is accepted into connected
		//note that connected is the new sockfd having all the same features of sfd passed
		//sfd has no connection as it is open to connection from other clients according to its listen function
		//this new sfd is the handle to the client that called connect function
		//client addr is set in client_addr 
		//we setup the inet_ntoa function and ntohs
		//they convert network byte order to nice decimal dotted form
		connected = accept(sfd,(struct sockaddr *)&client_addr,&clisize);
		printf("connected to %s %d\n",inet_ntoa(client_addr.sin_addr),ntohs(client_addr.sin_port) );
		while(1)
		{
			printf("ENTER Send data\n");
			fgets(send_data,maxd,stdin);
			//send data to clinet
			send(connected,send_data,strlen(send_data),0);
			bytes_recv = recv(connected,recv_data,maxd,0);
			recv_data[bytes_recv] = '\0';
			printf("Client : %s\n",recv_data );
			if(recv_data[0] == 'q')
				break;
			//connection closes on encountering q as the start letter
		}
		//close connection to client
		close(connected);
		
	}
	return 0;
	
}