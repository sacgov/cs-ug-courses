/********************************************************
* Author 	: Sachin Govind
* Date   	: 04 February 2016 (Thursday)
* Title		: service_coordinator
********************************************************/
// Info : provides service coordination to clients by offering services to them 
// gets names of fiofos of clients famous fifo and created them and then poll on them
// once a client request a service it is execed with approiriate args
// the service sends info to client
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <poll.h>
#include <sys/ipc.h>
#include <string.h>
#define max 100
int rfd[max]; //to read from all clients
fd_set readset,writeset;
int i,n,mfd;//famous fifo for clinet names
int numClients =1;//first fd is mfd
int wfd[max];
char name[max][max]; //names of clients
int main()
{
	FD_ZERO(&readset);
	//FD_ZERO(&writeset);
	//famous fifo where client announce their arrival by giving their names
	mkfifo("fmfifo",0666);
	//mkfifo("s2",0666);
	mfd=open("fmfifo",O_RDWR);
	FD_SET(mfd,&readset);
	while(1)
	{
		struct timeval tvm;
		tvm.tv_sec =1;
		tvm.tv_usec = 200;
		struct timeval tvcl;
		tvcl.tv_sec =1;
		tvcl.tv_usec = 300;
		FD_ZERO(&readset);
		
		for(i=1;i<numClients;i++)
		{
			FD_SET(rfd[i],&readset);
		}
		FD_SET(mfd,&readset);
		int  k = select(FD_SETSIZE,&readset,NULL,NULL,&tvm);

		//this is mfd
		if(k)
		if(FD_ISSET(mfd,&readset))
		{
			//reads names of fifo from clients and creates fifos
			char buf[max];
			n=read(mfd,buf,max);
			printf("%s is name of fifo\n",buf );
			strcpy(name[numClients],buf);
			strcat(buf,"r");
			mkfifo(buf,0666);
			rfd[numClients] = open(buf,O_RDWR); //opens the fifo for poll
			strcat(buf,"w");
			strcpy(name[numClients],buf); //stores name of fiofo to write and send to service as argument
			printf("fifos prepared\n");
			printf("%s is name of fifo %d\n ",buf ,numClients);
			numClients++;
		}
		//polls clients for input
		int v =select(FD_SETSIZE,&readset,NULL,NULL,&tvcl);
		if(v)
		for(i=1;i<numClients;i++)
		{
			if(FD_ISSET(rfd[i],&readset))
			{
				char buf1[200];
				read(rfd[i],buf1,100);
				printf("%s is service request from client 1\n",buf1 );
				int pid = fork();
			//creates a child and executes the service and exits
				if(pid ==0)
				{
					printf("%s\n",name[i] );
					execl(buf1,buf1,name[i],buf1,(char*)0); //name[i] is fifo to write to client and buf is message to be processed
					exit(0);
				}
			}
		}
	}

}
