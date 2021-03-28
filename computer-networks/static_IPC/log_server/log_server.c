/********************************************************
* Author 	: Sachin Govind
* Date   	: 30 January 2016 (Saturday)
* Title		: log_server
********************************************************/
// Info : provides service coordination to client 
//requires no arguments though all fifos can be given as args and run in a loop
//writes everything to a log.txt
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <sys/types.h>
#include <poll.h>
#include <sys/ipc.h>
int main()
{
	//below four are for reading requsests from client
	mkfifo("c1",0666);
	mkfifo("c2",0666);
	mkfifo("c3",0666);
	mkfifo("c0",0666);
	struct pollfd pfd[4];
	int i;
	//to poll for clients
	int infd = open("log",O_RDWR);
	pfd[0].fd = open("c0",O_RDWR);
	pfd[1].fd = open("c1",O_RDWR);
	pfd[2].fd = open("c2",O_RDWR);
	pfd[3].fd = open("c3",O_RDWR);
	for(i=0;i<4;i++)
		pfd[i].events = POLLIN;
	while(1)
	{
		while(poll(pfd,4,2000)<=0){printf("Inpoll\n");}
		if(pfd[0].revents & POLLIN)
		{
			char buf[200];
			//fflush(stdin);
			read(pfd[0].fd,buf,100);
			printf("%s is from client 0\n",buf );
			
			int pid = fork();
			//creates a child and executes the service and exits cw0 is for service to write in client
			if(pid ==0)
			{
				execl("./s1","./s1","cw0",buf,(char*)0);
				exit(0);
			}
			strcat(buf," is from client 0\n");
			//infd = open("log",O_APPEND);
			write(infd,buf,strlen(buf));
			//close(infd);
			sleep(0.5);
		}
		if(pfd[1].revents & POLLIN)
		{
			char buf1[200];
			read(pfd[1].fd,buf1,100);
			printf("%s is from client 1\n",buf1 );
			
			int pid = fork();
			//creates a child and executes the service and exits
			if(pid ==0)
			{
				execl("./s1","./s1","cw1",buf1,(char*)0);
				exit(0);
			}
			strcat(buf1," is from client 1\n");
			//printf("%s is from client 0\n",buf );
			//infd = open("log",O_APPEND);
			write(infd,buf1,strlen(buf1));
			//close(infd);
			sleep(0.5);
		}
		if(pfd[2].revents & POLLIN)
		{
			char buf2[200];
			fflush(stdin);
			read(pfd[2].fd,buf2,200);
			printf("%s is from client 2\n",buf2 );
			
			//creates a child and executes the service and exits
			int pid = fork();
			if(pid ==0)
			{
				execl("./s1","./s1","cw2",buf2,(char*)0);
				exit(0);
			}
			strcat(buf2," is from client 2\n");
			//printf("%s is from client 0\n",buf );
			//infd = open("log",O_APPEND);
			write(infd,buf2,strlen(buf2));
			//close(infd);
			sleep(0.5);
		}
		if(pfd[3].revents & POLLIN)
		{
			char buf3[200];
			read(pfd[3].fd,buf3,200);
			printf("%s is from client 3\n",buf3 );
			
			int pid = fork();
			if(pid ==0)
			{
				execl("./s1","./s1","cw3",buf3,(char*)0);
				exit(0);
			}
			strcat(buf3," is from client 3\n");
			//printf("%s is from client 0\n",buf );
			//infd = open("log",O_APPEND);
			write(infd,buf3,strlen(buf3));
			//close(infd);
			sleep(0.5);
		}
	}

}
