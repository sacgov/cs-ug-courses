/********************************************************
* Author 	: Sachin Govind
* Date   	: 20 February 2016 (Saturday)
* Title		: main server using TCP
********************************************************/
// Info : Implements an server(main) 
/*
it has a lit of services as an array service_t declared below
feel free to change names of them but then client has to connect appropriately
it sends the client the new port number of service it needs
if it is not execed it execed else only port is given else an error message is given
started[i] holds the info about service running or not
sets a limit on number of connections per service

//Important :now no mere limit i=only change is in lines 71 to 75
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


#define maxd 100 //max data length
#define MAX 3 //services are three
#define eerror(msg) { printf("%s\n", msg); exit(1); }
typedef struct service
{
    int port;
    char * s_name;
    int id;
    int limit;
    int count;
}service_t;
//our services
service_t serv[] = { {9501, "s0", 0,2,0}, {9502, "s1", 1,2,0}, {9503, "s2", 2,1,0} };

//get port from service name
int get_serv_port(char * serv_name,int *serid) 
{
    int i;
    for (i = 0; i < 3; i++){
        if(strcmp(serv_name, serv[i].s_name) == 0)
        {
        	*serid = serv[i].id;
        	/*if(serv[i].count < serv[i].limit)
        		serv[i].count ++;
        	else
        		break;*/

            return serv[i].port;
        }
    }
    return -1;
}
int started[5] = {0};
int *sigpid; //to send signal to parent on completion 
//reduces limit by one to service which sent signal
void handler(int sig)
{
	int i;
    printf("signal recieved %d\n", *sigpid);
	for (i=0; i<MAX; i++) 
	{
		if (serv[i].port == *sigpid) 
		{
			serv[i].count -- ;
            break;
		}
	}
	printf("client disconnected %d !!\n", *sigpid);
}
int main()
{
	//shared memory to see which client has sent signal
	int shmkey = shmget(0x1234, 4, 0666|IPC_CREAT);
    if(shmkey == -1 ) eerror("shmget() error");
	sigpid = (int *)shmat(shmkey, NULL, 0);
	if(sigpid == (int *)-1) eerror("shmat() error"); 
	signal(SIGUSR1,handler);

	//server_fd,conneted is client's fd,bytes_recv is count of bytes
	int sfd,nsfd,bytes_recv;
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
	server_addr.sin_port = htons(9123);
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
	//max people who can connect to this sfd is five max is SOMAXCONN
	if(listen(sfd,5) == -1)
	{
		perror("listen error");
		exit(1);
	}
	printf("Server is running on port 9123\n");
	fd_set rfds;
	start:
	{
		//poll on clients
		FD_ZERO(&rfds);
		FD_SET(sfd,&rfds);
		if(select(sfd+1,&rfds,NULL,NULL,NULL)>0)
		{
			if(!FD_ISSET(sfd,&rfds))
				goto start;



			//size of client
			int clisize = sizeof(struct sockaddr_in);
			//client is accepted into connected
			//note that connected is the new sockfd having all the same features of sfd passed
			//sfd has no connection as it is open to connection from other clients according to its listen function
			//this new sfd is the handle to the client that called connect function
			//client addr is set in client_addr 
			//we setup the inet_ntoa function and ntohs
			//they convert network byte order to nice decimal dotted form
			nsfd = accept(sfd,(struct sockaddr *)&client_addr,&clisize);
			printf("connected to %s %d\n",inet_ntoa(client_addr.sin_addr),ntohs(client_addr.sin_port) );
			read(nsfd,recv_data,maxd);
			printf("%s\n",recv_data );
			int serid = 0;
			//get port for service
			int port = get_serv_port(recv_data,&serid);
			printf("port :%d\n",port );
			//no port
			if(port == -1)
			{
				write(nsfd,"service not found or limit reached try later : Sorry :-( ",maxd);
			}
			else
			{
				//else send port info to client
				bzero(send_data,maxd);
				sprintf(send_data,"%d",port);
				if(started[serid] == 0) 
				{
                    started[serid] = 1;
                    if(fork() == 0) {
                        execl(serv[serid].s_name, serv[serid].s_name, send_data, NULL);
                        eerror("execl() error");
                    }
                }
				write(nsfd,send_data,maxd);
			}

		}
		//close connection to client
		close(nsfd);
	}
	goto start;
	return 0;	
}