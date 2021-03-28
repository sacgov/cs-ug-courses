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
#define nums 2
#define max 100
//nums = number of services s1 s1 
//containd info of processes
struct sdata
{
	int busy;
	int complt;
	int pid;//pid of process
	char msg[max];
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
	//below four are for reading requsests from client
	mkfifo("c1",0666);
	mkfifo("c2",0666);
	mkfifo("c3",0666);
	mkfifo("c0",0666);
	//these fifos are for service instances
	mkfifo("s0",0666);
	mkfifo("s1",0666);
	int sfd[2];//for server 1 or 0
	sfd[0] = open("s0",O_RDWR);
	sfd[1] = open("s1",O_RDWR);
	struct pollfd pfd[4];
	int i;
	//to poll for clients
	pfd[0].fd = open("c0",O_RDWR);
	pfd[1].fd = open("c1",O_RDWR);
	pfd[2].fd = open("c2",O_RDWR);
	pfd[3].fd = open("c3",O_RDWR);
	for(i=0;i<4;i++)
		pfd[i].events = POLLIN;
	if((shmid=shmget(shmkey,sizeof(sdata)*(nums+1),IPC_CREAT|0666))<0)
		printf("error in shmget\n");;
	struct sdata *k;
	if((k = (sdata*)shmat(shmid,(void *)0,0))<0)
		printf("error2\n");;
	initsdata(k,nums);//initializes the sdata
	print(k,nums);
	while(1)
	{
		while(poll(pfd,4,2000)<=0){printf("Inpoll\n");}
		if(pfd[0].revents & POLLIN)
		{
			char buf[200];
			//fflush(stdin);
			read(pfd[0].fd,buf,100);
			printf("%s is from client 0\n",buf );
			int flag =0;//checks if server is available or not
			for(int i=0;i<nums;i++)
			{
				if(k[i].complt == 1)
				{
					print(k,nums);
					printf("service %d is free\n",i );
					bzero(k[i].msg,100*sizeof(char));
					strcat(k[i].msg,"cw0");
					write(sfd[i],buf,max);
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
		if(pfd[1].revents & POLLIN)
		{
			char buf1[200];
			read(pfd[1].fd,buf1,100);
			printf("%s is from client 1\n",buf1 );
			int flag =0;//checks if server is available or not
			for(int i=0;i<nums;i++)
			{
				if(k[i].complt == 1)
				{
					bzero(k[i].msg,100*sizeof(char));
					strcat(k[i].msg,"cw1");
					write(sfd[i],buf1,max);
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
		if(pfd[2].revents & POLLIN)
		{
			char buf2[200];
			fflush(stdin);
			read(pfd[2].fd,buf2,200);
			printf("%s is from client 2\n",buf2 );
			int flag =0;//checks if server is available or not
			for(int i=0;i<nums;i++)
			{
				if(k[i].complt == 1)
				{
					bzero(k[i].msg,100*sizeof(char));
					strcat(k[i].msg,"cw2");
					write(sfd[i],buf2,max);
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
		if(pfd[3].revents & POLLIN)
		{
			char buf3[200];
			read(pfd[3].fd,buf3,200);
			printf("%s is from client 3\n",buf3 );
			int flag =0;//checks if server is available or not
			for(int i=0;i<nums;i++)
			{
				if(k[i].complt == 1)
				{
					bzero(k[i].msg,100*sizeof(char));
					strcat(k[i].msg,"cw3");
					write(sfd[i],buf3,max);
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
