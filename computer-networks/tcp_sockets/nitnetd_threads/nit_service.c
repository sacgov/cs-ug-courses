/********************************************************
* Author 	: Sachin Govind
* Date   	: 03 March 2016 (Thursday)
* Title		: implementing inetd as nitnetd(this is a service to nit_client.c) using threads
********************************************************/
//Info :
/*
This is a service maintained by nit_mss.c
this is "exec"ed by nit_mss.c  on the first instance
its s1 s2 or s3 based on portno to it
from then on next times this program is threaded to provide service to clients
it gives toupper os string gien by child
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
#include <ctype.h>
#include <string.h>

#include <pthread.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>

#include <sys/shm.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <signal.h>

#include <arpa/inet.h>
#include <netdb.h>
#include <netinet/in.h>


#define maxd 100 //max data length
#define eerror(msg) { printf("%s\n", msg); exit(1); } //prints error message and exits



void * runner (void * args) 
{
    int i,sfd = *(int *) args; char buf[maxd];
    while(1) {
        memset(buf, '\0', maxd);
        read(sfd, buf, maxd);
        if(strcmp(buf, "exit") == 0)
            break;
        for (i = 0; i < strlen(buf); ++i) {
            if(islower(buf[i]))
                buf[i] = buf[i]-32;
        }
        write(sfd, buf, strlen(buf));
    }
}




int main(int argc,char* argv[])
{
	//shared memory to put its pid to parent
	int shmkey = shmget(0x1234, 4, 0666|IPC_CREAT);
	
    if(shmkey == -1 ) eerror("shmget() error");
	
    int * sigpid = (int*) shmat(shmkey, NULL, 0);
	
    if(sigpid == (int *)-1) 
        eerror("shmat() error");
	//server_fd,nsfd is client's fd,bytes_recv is count of bytes
	int sfd,nsfd,bytes_recv;
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
	char send_data[maxd],recv_data[maxd];
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
	printf("Server is running on port %d\n",port);
	pthread_t pid;
	//pthread to run the service
	while(1)
	{
			//size of client
			int clisize = sizeof(struct sockaddr_in);
			//client is accepted into connected
			//note that nsfd is the new sockfd having all the same features of sfd passed
			//sfd has no connection as it is open to connection from other clients according to its listen function
			//this new sfd is the handle to the client that called connect function
			//client addr is set in client_addr 
			//we setup the inet_ntoa function and ntohs
			//they convert network byte order to nice decimal dotted form
			nsfd = accept(sfd,(struct sockaddr *)&client_addr,&clisize);
			//Announce connection details
			printf("connected to %s %d\n",inet_ntoa(client_addr.sin_addr),ntohs(client_addr.sin_port) );
			//get parents ppid intended to be used to send signals code not yet implemented
			int ppid = getppid();
			printf("Parent pid : %d\n",ppid );
			pthread_create(&pid, NULL, &runner, (void *) &nsfd);
			//child to service clients

	}
	return 0;	
}
//thread runner

/*
see my previous version of nitnted there ihave implmented this now no limits as threads are used"
//changed in mss as well
			if(pid == 0)
			{
				close (sfd);
				dup2(nsfd,0);
				dup2(nsfd,1);
				read(0,recv_data,maxd);
				printf("Recieved Data : %s\n",recv_data );

            	printf("Final Data : " );
            	int i =0;
            	while(recv_data[i])
   				{
      				printf("%c",toupper(recv_data[i]) );
      				i++;
   				}
            	exit(1);

			}
			else
			{
				wait();
				//send signal reduce limit in server main
				* sigpid = port;
           		if(kill(ppid, SIGUSR1) == -1)
                eerror("kill() error");
			}

		//close connection to client
		close(nsfd);
		*/