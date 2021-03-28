/********************************************************
* Author 	: Sachin Govind								*
* Date   	:											*
* Title		:											*
********************************************************/
// Info : 
#include <stdio.h>
#include <stdlib.h>
#include <poll.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <string.h>
#include <fcntl.h>
int main()
{
	mkfifo("ser0",O_RDWR);
	mkfifo("ser1",O_RDWR);
	mkfifo("c0",O_RDWR);
	mkfifo("c1",O_RDWR);
	int cliwritefd[2];
	cliwritefd[0] = open("ser0",O_RDWR);
	cliwritefd[1] = open("ser1",O_RDWR);
	struct pollfd pfd[2];
	pfd[0].fd = open("c0",O_RDWR);
	pfd[1].fd = open("c1",O_RDWR);
	pfd[0].events = POLLIN;
	pfd[1].events = POLLIN;
	while(1)
	{
		while(poll(pfd,2,0)<=0){}
		if(pfd[0].revents & POLLIN)
		{
			char buf[100];
			read(pfd[0].fd,buf,100);
			strcat(buf,"from client 1 to you");
			write(cliwritefd[1],buf,100);
		}
		else
		{
			char buf[100];
			read(pfd[1].fd,buf,100);
			strcat(buf,"from client 2 to you");
			write(cliwritefd[0],buf,100);

		}
	}
}