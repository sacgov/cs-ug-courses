/********************************************************
* Author 	: Sachin Govind
* Date   	: 03 March 2016 (Thursday)
* Title		: Group runner
********************************************************/
//Info :
/*
it runs groups on directed ny group_mss.c
This is a group maintained by groupnit_mss.c
this is "exec"ed by group_mss.c  on the first instance
its s1 s2 or s0 based on portno to it
from then on next times this program is forked to provide service to clients
it broadcasts messages from each of the peer to all other peers
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
#include <stdlib.h>
#include <string.h>

#include <sys/shm.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <signal.h>
#include <sys/socket.h>
#include <unistd.h>
#include <signal.h>

#include <arpa/inet.h>
#include <netdb.h>
#include <netinet/in.h>
#include <ctype.h>

#define BUFSIZE 1024
#define maxClients 100
#define eerror(msg) { printf("%s\n", msg); exit(1); } //prints error message and exits
int main(int argc,char* argv[])
{
	//server_fd,nsfd is client's fd,bytes_recv is count of bytes
	int sfd,bytes_recv;
	//port of service (port is given to clients by nit_mss)
	int port;
	if (argc == 1)
	{
        eerror("Port not given to service");
    }
    else
    {
        port = atoi(argv[1]);
        //s1 or s2 or s3 according to port no by server
        if(port < 1024 || port > 65535) 
            eerror("Port must between 1024 to 65535");
    }
	//data to send and receive
	char send_data[BUFSIZE],recv_data[BUFSIZE];
	//look above for its description
	struct sockaddr_in server_addr,client_addr;
	//sock stream af_inet is ipv4 domain
	if((sfd = socket(AF_INET,SOCK_STREAM,0))==-1)
	{
		perror("Socket ready error");
		exit(1);
	}


	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons((u_short)port);
	server_addr.sin_addr.s_addr = inet_addr("127.0.0.1"); //load with inet_ntoa();
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
	//max people who can connect to this sfd is five max is 5
	if(listen(sfd,5) == -1)
	{
		perror("listen error");
		exit(1);
	}
	//Announce ruuning of server and that it is ready to accept
	printf("Group is running on port %d\n",port);
	fd_set rfds;
	//read set o is main server or server sfd to which clients connect
	int nsfd[maxClients];
	int numClients = 0;//oth as stated above
	nsfd[numClients++] = sfd;
	int maxfd = 0;//set maxfd in select
	while(1)
	{
		FD_ZERO(&rfds);
		int i;
		for(i=0;i<numClients;i++)
		{
			FD_SET(nsfd[i],&rfds);
			if(maxfd < nsfd[i]) maxfd = nsfd[i] +1;
		}
		int resume = select(FD_SETSIZE,&rfds,NULL,NULL,NULL);//wait on input
		if(resume <= 0)
			continue;
		//size of client
		int clisize = sizeof(struct sockaddr_in);
		for(i=0;i<numClients;i++)
		{
			if(FD_ISSET(nsfd[i],&rfds))
			{
				if(i==0)
				{
					//add client to roup array of nsfds
					nsfd[numClients] = accept(sfd,(struct sockaddr *)&client_addr,&clisize);
					//Announce connection details
					printf("connected to %s %d %d\n",inet_ntoa(client_addr.sin_addr),ntohs(client_addr.sin_port),numClients );
					numClients++;
					break;
				}
				else
				{
					//read message grom a peer
					printf("message from %d \n", i );
					char buf[BUFSIZE];
					memset(buf, 0, BUFSIZE);
                    int n = read(nsfd[i], buf, BUFSIZE);
                    if(strlen(buf) <= 1) continue;
                    /*if(atoi(buf) == -1) 
                    {
                        close(nsfd[i]);
                        nsfd[i] = -1;
                        continue;
                    }*/
                    char buffer[BUFSIZE];
                    memset(buffer, 0, BUFSIZE);
                    //append peer number to message
                    sprintf(buffer, "P%d: %s", i, buf);
                    int j;
                    //broadcast to all others
                    for(j=1; j < numClients; j++) 
                    {
                        if(i!=j)
                            write(nsfd[j], buffer, BUFSIZE);
                    }

				}

			}

		}
		
		
	}
	return 0;	
}