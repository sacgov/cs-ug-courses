/********************************************************
* Author 	: Sachin Govind
* Date   	: 04 February 2016 (Thursday)
* Title		: client
********************************************************/
// Info : requests service from service coordinator 
// args : name od client it sends it to server through fmfifo for sending to mss and reading from server respectively
// enter the service required to get it
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <poll.h>
#define max 100
int fd,n,fd1;
int main(int argc,char *argv[])
{
	sleep(3);
	mkfifo("fmfifo",0666);
	//write name to fmfifo and create fifos
	int mfd=open("fmfifo",O_RDWR);
	write(mfd,argv[1],max);
	char b[max];
	strcpy(b,argv[1]);
	strcat(b,"r");
	int f=mkfifo(b,0666);
	printf("fifos are done\n");
	fd=open(b,O_RDWR);//wrtiting service reads
	strcat(b,"w");
	int f1=mkfifo(b,0666);
	fd1=open(b,O_RDWR);//reading requested service writes

	
	while(1)
	{
		//sends the service and print the o/p received by it
		char *buf = malloc(max*sizeof(char));
		printf("enter the service required\n");
		scanf("%s",buf);
		write(fd,buf,max);
		sleep(0.5);
		char *buf2= malloc(max*sizeof(char));
		read(fd1,buf2,max);
		printf("%s\n",buf2 );
	}
	
}
