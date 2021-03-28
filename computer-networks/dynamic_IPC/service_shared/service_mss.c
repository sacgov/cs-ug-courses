/********************************************************
* Author 	: Sachin Govind
* Date   	: 04 February 2016 (Thursday)
* Title		: service_mss
********************************************************/
// Info : provides service by request written by server to it
// arg1 is name of service ie same name fio and its index for sdata
// sends the service in shared msg property of sdata fifo as stated by client
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
struct sdata
{
	int busy;
	int complt;
	int pid;//pid of process
	char msg[max]; //fifo to write the service o/p
};
//prints shared data
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
	int ind = atoi(argv[2]); //service index in sdata
	printf("I'm service %s %d\n",argv[1],ind );
	//get shared memory excl means if already present return it to me
	if((shmid=shmget(shmkey,sizeof(sdata)*(nums+1),IPC_EXCL|0666))<0)
		printf("error in shmget\n");;
	struct sdata *k;
	//attach shared memory to process
	if((k = (sdata*)shmat(shmid,(void *)0,0))<0)
		printf("error2\n");;
	print(k,nums);//print info
	//arg with service name same name fifo service names have to be different
	mkfifo(argv[1],0666);
	struct pollfd pfd[2];
	pfd[0].fd = open(argv[1],0666);
	pfd[0].events = POLLIN;
	char buf[max];
	while(1)
	{
		//poll on i/p from server
		while((poll(pfd,2,2000))<=0){printf("inpoll\n");}
		read(pfd[0].fd,buf,100);
		printf("working on %s\n",buf );
		k[ind].busy = 1;//set flags
		k[ind].complt = 0;
		print(k,nums);
		sleep(5);
		printf("%s\n",k[ind].msg );
		//create fifo from shared memory written in sdata
		mkfifo(k[ind].msg,0666);
		int fd = open(k[ind].msg,O_RDWR);
		strcat(buf," is processed");
		printf("is completed\n");
		write(fd,buf,max); //write back service o/p
		k[ind].busy = 0;;
		k[ind].complt = 1;//unset flags
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
