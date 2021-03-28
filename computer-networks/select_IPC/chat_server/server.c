/********************************************************
* Author 	: Sachin Govind
* Date   	: 04 February 2016 (Thursday)
* Title		: chat_server
********************************************************/
// Info : it is the server redirecting and coordinating between the group chat
//it polls on clients and writed i/p accordingly to all other clients
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <pthread.h>
#include <poll.h>
#include <fcntl.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/select.h>
fd_set readset,writeset;
#define max 100
int i,n,mfd;
char buffer1[max];
int numClients =1;//first fd is mfd and remaining are clients
int wfd[max]; //to write to all clients
int rfd[max]; //to read from all clients
char name[max][max]; //names of clients
int main(int argc,char *argv[])
{
	
	FD_ZERO(&readset);
	//FD_ZERO(&writeset);
	//famous fifo where client announce their arrival by giving their names
	mkfifo("fmfifo",0666);
	//mkfifo("s2",0666);
	mfd=open("fmfifo",O_RDWR);
	FD_SET(mfd,&readset);
	//struct pollfd pfd[max];
	//pfd[0].fd=mfd;
	//for(i=0;i<max;i++)
		//pfd[i].events=POLLIN; //set event of all pfd to POLLIN
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
			//printf("inmain\n");
			char buf[max];
			n=read(mfd,buf,max);
			printf("%s is name of fifo\n",buf );
			strcpy(name[numClients],buf);
			//copy name of fifo into names
			strcat(buf,"r");
			mkfifo(buf,0666);
			rfd[numClients] = open(buf,O_RDWR);
			FD_SET(rfd[numClients],&readset);
			//poll for fifo of clinet setyp
			strcat(buf,"w");
			mkfifo(buf,0666);
			printf("fifos prepared\n");
			wfd[numClients] = open(buf,O_RDWR);
			//setup write fifo
			numClients++;
		}
		//printf("nowclients\n");
		//for clients if they write to server it is written to all other clients
		int v =select(FD_SETSIZE,&readset,NULL,NULL,&tvcl);
		if(v)
		for(i=1;i<numClients;i++)
		{
			//printf("%d",i );
			if(FD_ISSET(rfd[i],&readset))
			{
				//printf("%d\n",i );
				n=read(rfd[i],buffer1,max);
				//printf("cool\n");
				int j=0;
				//write to all other clients by appending the  name of client
				for(j= 1;j<numClients;j++)
				{
					char bufname[max];
					strcpy(bufname,name[i]);
					strcat(bufname," : ");
					strcat(bufname,buffer1);
					if(j!=i)
						write(wfd[j],bufname,max);
				}
			}
		}
	}
}

					
