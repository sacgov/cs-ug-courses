/********************************************************
* Author 	: Sachin Govind
* Date   	: 30 January 2016 (Saturday)
* Title		: service_mss
********************************************************/
// Info : provides service by request argv[2] to client
// sends the service in argv[2] fifo as stated by client
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
int main(int argc,char *argv[])
{
	if((shmid=shmget(shmkey,sizeof(sdata)*(nums+1),IPC_EXCL|0666))<0)
		printf("error in shmget\n");;
	struct sdata *k;
	if((k = (sdata*)shmat(shmid,(void *)0,0))<0)
		printf("error2\n");;
	print(k,nums);
	if((mkfifo(argv[1],0666))<0)printf("err\n");;
	struct pollfd pfd[2];
	pfd[0].fd = open(argv[1],0666);
	pfd[0].events = POLLIN;
	char buf[100];
	int ind = atoi(argv[2]);
	printf("%d\n",ind );
	while(1)
	{
		while((poll(pfd,2,1000))<=0){printf("inpoll\n");}
		read(pfd[0].fd,buf,100);
		printf("working on %s\n",buf );
		k[ind].busy = 1;
		k[ind].complt = 0;
		print(k,nums);
		sleep(5);
		mkfifo(k[ind].msg,0666);
		int fd = open(k[ind].msg,O_RDWR);
		strcat(buf," is processed");
		write(fd,buf,100);
		k[ind].busy = 0;;
		k[ind].complt = 1;
		print(k,nums);
	}
	//below four are for writing
	//printf("inexec\n");
	/*mkfifo(argv[1],0666);
	//printf("%s\n",argv[1] );
	int fd = open(argv[1],O_RDWR);
	strcat(argv[2]," is provided to you");
	write(fd,argv[2],100);*/



}
