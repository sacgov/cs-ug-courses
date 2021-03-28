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
int i,n,mfd;//famous fifo for clinet names
int numClients =1;//first fd is mfd
int wfd[max];
char name[max][max]; //names of clients
int main()
{
	mkfifo("fmfifo",0666);
	mfd=open("fmfifo",O_RDWR);
	struct pollfd pfd[max];
	pfd[0].fd=mfd;
	for(i=0;i<max;i++)
		pfd[i].events=POLLIN;//set all events to POLLIN
	while(1)
	{
		while(poll(pfd,numClients,1000)<=0){printf("pollin\n");};
		if(pfd[0].revents & POLLIN)
		{
			//reads names of fifo from clients and creates fifos
			char buf[max];
			n=read(pfd[0].fd,buf,max);
			printf("%s is name of fifo\n",buf );
			strcpy(name[numClients],buf);
			strcat(buf,"r");
			mkfifo(buf,0666);
			pfd[numClients].fd = open(buf,O_RDWR); //opens the fifo for poll
			strcat(buf,"w");
			strcpy(name[numClients],buf); //stores name of fiofo to write and send to service as argument
			printf("fifos prepared\n");
			printf("%s is name of fifo %d\n ",buf ,numClients);
			numClients++;
		}
		//polls clients for input
		for(i=1;i<numClients;i++)
		{
			if(pfd[i].revents & POLLIN)
			{
				char buf1[200];
				read(pfd[i].fd,buf1,100);
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
