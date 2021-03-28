/********************************************************
* Author 	: Sachin Govind
* Date   	: 03 March 2016 (Thursday)
* Title		: Internet main server
********************************************************/
// Info : internet main server
/*
runs pollserver to poll on clients nad report back to server
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
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <string.h>
#include <netdb.h>
#include <unistd.h>
int main(int argc,char *argv[])
{
	//forks a child to create a pollserver common to all services and pollserver
	int p = fork();
	//run pollserver as a child
	if(p==0)
	{
		execlp("./pollserver","./pollserver",NULL);
	}
	else
	{
		//declare server addresses
		struct sockaddr_in server_addr[3];
		//client address
		struct sockaddr_storage client_addr;
		//length of client
		socklen_t client_len = sizeof(client_addr);

		client_len = sizeof(client_addr);
		char buffer[1024];
		//Creates a socket....
		//define sfd and ports for three sfds and nsfd for client
		int sfd[3] , port[3] , max = 0 , nsfd ,i;
		for(i=0;i<3;i++)
		{
			//af_inet and sockstream of pv4 domain
			sfd[i] = socket(AF_INET , SOCK_STREAM , 0);
			if(sfd[i] > max)
				max = sfd[i];
		}
		//assigning arbitrary ports to three services whose object files are creted already
		port[0] = 6666;
		port[1] = 7777;
		port[2] = 8888;
		//initializing server addresses
		for(i=0;i<3;i++)
		{
			server_addr[i].sin_addr.s_addr = INADDR_ANY;
			server_addr[i].sin_port = htons(port[i]); //to get network byte order
			server_addr[i].sin_family = AF_INET;
			memset(server_addr[i].sin_zero,'\0',sizeof(server_addr[i].sin_zero));
			bind(sfd[i] ,(struct sockaddr *) &server_addr[i] , sizeof(server_addr[i]));
			listen(sfd[i] , 5); //max listen on 5
		}


		while(1){
			//fd set for reading in lect call
			fd_set read_fds;
			//clear fdset
			FD_ZERO(&read_fds);
			for(i=0;i<3;i++)
				FD_SET(sfd[i],&read_fds);

			select( max+1 , &read_fds ,NULL,NULL,NULL);
			//select ie poll on readfds and wait

			for(i=0;i<3;i++)
			{
				//if any fd is et on return for select
				if(FD_ISSET(sfd[i],&read_fds))
				{
					//accept client
					//its info is  stored in client addr and client len
					nsfd = accept(sfd[i] , (struct sockaddr *)&client_addr , &client_len);
					printf("CONNECTION ESTABLISHED \n");
					int pid = fork();

					//Child process
					if(pid==0)
					{
						close(sfd[i]);
						printf("SERVICE REQUESTED %s\n",buffer);
						//dup and exec as child woulf take input from nsfd
						dup2(nsfd,0);
						dup2(nsfd,1);
						switch(i)
						{
							case 0:
								execlp("./s1","./s1",NULL);
								break;
							case 1:
								execlp("./s2","./s2",NULL);
								break;
							case 3:
								execlp("./s3","./s3",NULL);
								break;
						}
					}
					else
						close(nsfd);
				}
			}
		}
	}
}
