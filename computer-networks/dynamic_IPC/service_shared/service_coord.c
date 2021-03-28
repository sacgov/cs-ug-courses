/********************************************************
* Author 	: Sachin Govind
* Date   	: 30 January 2016 (Saturday)
* Title		: service_coordinator
********************************************************/
// Info : provides service coordination to client 
//requires no arguments though all fifos can be given as args and run in a loop
#include <stdio.h>
#include <bits/stdc++.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <poll.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#define nums 3
#define max 100
//nums = number of services s1 s1 
//containd info of processes
int i,n,mfd;
int numClients =1;//first fd is mfd
int wfd[max];
char name[max][max]; //names of clients and their fifos of same name
struct sdata
{
	int busy;
	int complt;
	int pid;//pid of process
	char msg[max]; //name of fifo of client while requesting a service
};
//initializes sdata - service data in shared memory
void initsdata(sdata *k,int num)
{
	int i;
	for(int i =0;i<nums;i++)
	{
		k[i].busy =0;
		k[i].complt = 1;
		k[i].pid = getpid();
		bzero(k[i].msg,sizeof(char)*max);
		strcat(k[i].msg,"msg");
	}
}
void print(sdata *k,int num)
{
	int i;
	for(int i =0;i<nums;i++)
	{
		printf("service %d : busy:%d complt:%d with msg:%s and pid:%d\n",i,k[i].busy,k[i].complt,k[i].msg,k[i].pid );
	}
}
//contains info about shared memory
key_t shmkey = 4234;
int shmid;
int main()
{
	//fmfifo for reading names of clients and creting fifos
	mkfifo("fmfifo",0666);
	mfd=open("fmfifo",O_RDWR);
	struct pollfd pfd[max];
	pfd[0].fd=mfd;
	for(i=0;i<max;i++)
		pfd[i].events=POLLIN;
	//inititate shared memory
	if((shmid=shmget(shmkey,sizeof(sdata)*(nums+1),IPC_CREAT|0666))<0)
		printf("error in shmget\n");;
	struct sdata *k;
	//atttach shared memory to the process
	if((k = (sdata*)shmat(shmid,(void *)0,0))<0)
		printf("error2\n");;
	initsdata(k,nums);//initializes the sdata
	print(k,nums);int j;
	int sfd[nums];//server fifos to write to them
	printf("enter the names of services to coodinate : \n");
	for(i=0;i<nums;i++)
	{
		char buf_fifo[max];
		bzero(buf_fifo,max*sizeof(char));
		printf("Name of Service %d :\n",i );
		scanf("%s",buf_fifo);
		mkfifo(buf_fifo,0666);
		sfd[i] = open(buf_fifo,O_RDWR);//set up fds to servers

	}
	//poll on clients
	while(1)
	{
		while(poll(pfd,numClients,1000)<=0){printf("pollin\n");};
		if(pfd[0].revents & POLLIN)
		{
			//create fifos according to child names and setup poll
			char buf[max];
			printf("read1\n");
			n=read(pfd[0].fd,buf,max);
			printf("%s is name of fifo\n",buf );
			strcat(buf,"r");
			mkfifo(buf,0666);
			pfd[numClients].fd = open(buf,O_RDWR);
			strcat(buf,"w");
			strcpy(name[numClients],buf); //save the name of fifo of children
			printf("fifos prepared\n");
			printf("%s is name of fifo %d\n ",name[numClients] ,numClients);
			numClients++;
		}
		//poll on clients
		for(i=1;i<numClients;i++)
		{
			if(pfd[i].revents & POLLIN)
			{
				printf("%d\n",i );
				char buf1[max];
				read(pfd[i].fd,buf1,max);//read from clinet
				printf("%s is from client %d\n",buf1,i );
				int flag =0;//checks if server is available or not
				//check for all the servers and write to free server
				for(int j=0;j<nums;j++)
				{
					if(k[j].complt == 1)
					{
						bzero(k[j].msg,max*sizeof(char));
						strcpy(k[j].msg,name[i]);
						write(sfd[j],buf1,max);
						print(k,nums );
						flag = 1;
						break;
					}
				}
				if(flag != 1)
				{
					print(k,nums);
					printf("all service providers are busy\n");
				}
			}
		}
	}



}
