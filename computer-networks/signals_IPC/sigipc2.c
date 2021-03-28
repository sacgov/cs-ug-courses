/********************************************************
* Author 	: Sachin Govind
* Date   	: 31 January 2016 (Sunday)
* Title		: IPC using signals
********************************************************/
// Info : sends the data to client 1 sig_ipc1.c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <pthread.h>
#include <fcntl.h>
#include <sys/ipc.h>
#include <signal.h>
#include <string.h>
int fd;
//handler for the signal sigusr1 when the other client sends the signal
void sighandler()
{
	char buf[100];    
	read(fd,buf,100);  //reads inti buffer
	strcat(buf," from c2"); 
	printf("%s\n",buf ); //display buffer
}
int main()
{
	mkfifo("sad",0666);    //fifo with other client 
	fd = open("sad",O_RDWR);
	signal(SIGUSR1,sighandler); //setup signal handler 
	char bug[100];
	printf("%d\n",getpid() ); //pid of other client
	
	while(1)
	{
		printf("Enter the message : ");
		scanf("%s",bug);
		write(fd,bug,100); //write to fifo
		int pid;
		printf("Enter Pid to send : ");
		scanf("%d",&pid); 
		kill(pid,SIGUSR1);
		
	}
}