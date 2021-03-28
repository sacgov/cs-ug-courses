/********************************************************
* Author 	: Sachin Govind
* Date   	: 03 March 2016 (Thursday)
* Title		: client to group_mss.c
********************************************************/
// Info : Implements an client which requests for a joining a group
/*
services are s1 s2 s3 only
server returns a port of the group and client has to agin connect to it which provides it with group chat
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

#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <signal.h>

#include <arpa/inet.h>
#include <netdb.h>
#include <netinet/in.h>

#define BUFSIZE 1024
#define eerror(msg) { printf("%s\n", msg); exit(1); }

void * reader(void * args) 
{
    char buf[BUFSIZE];
    int sfd = *(int *) args;
    while(1) 
    {
        read(sfd, buf, BUFSIZE);
        printf("%s", buf);
    }
}

void * writer(void * args) 
{
    char buf[BUFSIZE];
    int n,sfd = *(int *) args;
    while(1) {
        fgets(buf, BUFSIZE, stdin);
        write(sfd, buf, BUFSIZE);
        if (atoi(buf) == -1) {
            eerror("Exiting...");
        }
    }
}

#define maxd 100 //max data length
int main(int argc,char * argv[])
{
	//sfd and bytes recieved
	int sfd,bytes_recv,port;
	//to send data to server
	char send_data[maxd],recv_data[maxd];
	struct sockaddr_in server_addr,client_addr,s_addr;
	//server is INADDR_ANY so what is written below as host doesn't matter as server listens to all
	//create sfd
	if((sfd = socket(AF_INET,SOCK_STREAM,0))==-1)
	{
		perror("Socket ready error");
		exit(1);
	}
	//setting up server info to connect
	server_addr.sin_family = AF_INET;
	//should know server port to connect
	server_addr.sin_port = htons(9123);

	server_addr.sin_addr.s_addr= inet_addr("127.0.0.1");
	bzero(&(server_addr.sin_zero),8);
	//clinet ifo is generated by the PC automatically an address is assigned and a port
	if(connect(sfd,(struct sockaddr *)&server_addr,sizeof(struct sockaddr)) == -1)
	{
		perror("connect Error");
		exit(1);
	}
	printf("Connected to Server :Starting to send and receive data\n");
	printf("ENTER service needed\n");
	scanf("%s",send_data);
	send(sfd,send_data,maxd,0);
	recv(sfd,recv_data,maxd,0);
	printf("Received data :%s\n", recv_data);
	close(sfd);
	int serv_no;
	if(recv_data[0] == 's') 
	{
        //printf("%s\n",recv_data );
        exit(1);
	}
    else
    {
        //get port no
    	serv_no = atoi(recv_data);
    }
    //printf("%s %d\n", recv_data, (int)strlen(recv_data));
    
    //connect to new server for service
    if((sfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
        eerror("socket() error");

    memset((char *) &s_addr, 0, sizeof(s_addr));
    s_addr.sin_family = AF_INET;
    s_addr.sin_port = htons((u_short) serv_no);
    s_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    sleep(2);
    //connect to server
    pthread_t r,w;
    if (connect(sfd, (struct sockaddr *) &s_addr, sizeof(s_addr)) < 0)
        eerror("connect() error");
    //enter data to be sent
    printf("Connected to Client\n");
    pthread_create(&r, NULL, * reader, (void *)&sfd);
    pthread_create(&w, NULL, * writer, (void *)&sfd);

    pthread_join(r, NULL);
    pthread_join(w, NULL);

    printf("\nExiting ...\n");
    close(sfd);
    return 0;	

}