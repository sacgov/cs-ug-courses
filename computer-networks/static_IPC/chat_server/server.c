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
int fd[2];
int i,n;
char buffer1[256];
int main(int argc,char *argv[])
{
	mkfifo("s1",0666);
	mkfifo("s2",0666);
	fd[0]=open("s1",O_RDWR);
	fd[1]=open("s2",O_RDWR);
	mkfifo("cs1",IPC_CREAT|0666);
	mkfifo("cs2",IPC_CREAT|0666);
	struct pollfd pfd[2];
	pfd[0].fd=open("cs1",O_RDWR);
	pfd[1].fd=open("cs2",O_RDWR);
	pfd[0].events=POLLIN;
	pfd[1].events=POLLIN;
	while(1)
	{
		while(poll(pfd,2,0)<=0){ }
		if(pfd[0].revents & POLLIN)
		{
			n=read(pfd[0].fd,buffer1,256);
			char b2[100];
			strcpy(b2,"c1:");
			strcat(b2,buffer1);
			write(fd[1],b2,strlen(b2));
		}
		else if(pfd[1].revents  & POLLIN)
		{
			n=read(pfd[1].fd,buffer1,256);
			char b2[100];
			strcpy(b2,"c2:");
			strcat(b2,buffer1);
			
			write(fd[0],b2,strlen(b2));

		}
	}
}

					
