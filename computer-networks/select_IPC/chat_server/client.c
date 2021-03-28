/********************************************************
* Author 	: Sachin Govind
* Date   	: 04 February 2016 (Thursday)
* Title		: client for server
********************************************************/
// Info : needs an argument its name to start chatting
// it sends the name through famous fifo to server and created the fifos
// it then creates two threads to read from server and wite to server continously
//main program waits for threads to terminate
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <pthread.h>
#include <fcntl.h>
#include <sys/ipc.h>
#include <string.h>
int fd,n,fd1;
char *buffer;
char *buffer1;
#define max 100
//thread writer
void *thread1()
{
	while(1)
	{
		fgets (buffer, max, stdin); //take input from user
		write(fd,buffer,max);//write it to server
		usleep(1000);
	}

}
//thread reader
void *thread2()
{
	while(1)
	{
		read(fd1,buffer1,max); //read from server
		printf("%s",buffer1); //display the  message from server
		usleep(1000);
	}
}

int main(int argc,char *argv[])
{
	mkfifo("fmfifo",0666);
	int mfd=open("fmfifo",O_RDWR);
	//opens and writes name of fifo to server
	write(mfd,argv[1],max);
	char b[max];
	strcpy(b,argv[1]);
	buffer1 = malloc(max*sizeof(char));
	buffer = malloc(max*sizeof(char));
	strcat(b,"r");
	int f=mkfifo(b,0666);
	fd=open(b,O_RDWR);
	strcat(b,"w");
	int f1=mkfifo(b,0666);	
	fd1=open(b,O_RDWR);
	printf("%s is fifo\n",b );
	printf("You are in server created by Sachin\n");
	printf("Start Messaging \n");
	pthread_t p1,p2;//threads are created for reading and writing
	pthread_create(&p1,NULL,&thread1,NULL);
	pthread_create(&p2,NULL,&thread2,NULL);
	pthread_join(p1,NULL);
	pthread_join(p2,NULL);
}

	
	
