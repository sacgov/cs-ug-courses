/********************************************************
* Author 	: Sachin Govind
* Date   	: 03 March 2016 (Thursday)
* Title		: Internet main server - client
********************************************************/
// Info : internet main server -client
/*
is a client to Internet main server
*/
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
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <netdb.h>

int main(int argc,char *argv[])
{
	//declare server addr in the client addr

	struct sockaddr_in client_addr;
	socklen_t client_len;
	bzero((char *)&client_addr , sizeof(client_addr));
	client_addr.sin_port = htons (atoi(argv[1]));
	client_addr.sin_addr.s_addr = INADDR_ANY;
	client_addr.sin_family  = AF_INET;
	client_len = sizeof(client_addr);
	//server setup over i advertantlu ued the name client for server addr above
	//client_len is length is legth of client adress in byte
	//setting to null by using memset 
	memset(client_addr.sin_zero , '\0' , sizeof(client_addr.sin_zero));
	int sfd = socket(AF_INET , SOCK_STREAM , 0);
	//coneect to server
	if(connect(sfd , (struct sockaddr *)&client_addr , client_len)==0)
		printf("TRYING TO CONNECT\n");
	sleep(2);
	char buffer[1024];
	while(1)
	{
		//read from user
		int byte_count  = read(0,buffer,sizeof(buffer));
		//sebd to server ie now the child created by server
		send(sfd ,buffer,byte_count, 0);
		sleep(2);
		//receive from server
		byte_count  = recv(sfd,buffer,sizeof(buffer),0);
		write(1,buffer,byte_count);
		//writing to buffer and completing 
		//byte_count is the count of addresses
		
	}
}