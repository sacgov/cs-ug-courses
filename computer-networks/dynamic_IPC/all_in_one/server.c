/********************************************************
* Author 	: Sachin Govind
* Date   	: 04 February 2016 (Thursday)
* Title		: server for all in one
********************************************************/
// Info : takes no arguments
// gets input from pipe a popen
//gets input from fifo.c as entered by user
// redirects input to p5 if signal SIGUSR! is received
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <poll.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <signal.h>
int sigrcv = 0; //flag to check if signal is  received
//sighandler assigns the above flag to 1 if signal is received
void sig_handler(int signo)
{
	printf("received signal\n");
	sigrcv =1;

}
//prints pid to give as a argv[1] to sigsend.c (./sigs ) and sets up handler
void make_signal()
{
	int a = getpid();
	printf("to send a signal send to my pid %d\n",a);
	signal(SIGUSR1,sig_handler);

}
int main(int argc,char *argv[])
{
	//creating a pipe
	int pipefd[2];
	pipe(pipefd);
	int pid = fork(); //creating a child
	if(pid > 0) //it is parent
	{
		//creating a fifo coordinating with fifo.c
		mkfifo("all",0666);
		int fd = open("all",O_RDWR);
		char *buf=new char[100];
		struct pollfd pfd[4];
		pfd[0].fd = fd;    //fifo polling
		pfd[0].events = POLLIN;
		pfd[1].fd = pipefd[0];  //pipe polling 
		pfd[1].events = POLLIN;
		close(pipefd[1]);
		printf("hello\n" ); //message to user
		FILE *fp;
		fp = popen("./pp","r");; //popening a pp object file
		pfd[2].fd = fileno(fp);
		pfd[2].events = POLLIN;
		make_signal();  //setup signal
		mkfifo("redirect",0666);   //fifo for redirecting o/p
		int redir = open("redirect",O_RDWR);
		while(1)
		{
			while(poll(pfd,4,200)<=0)
			{printf("inpoll\n");} //says it is in poll means no input yet
			if(pfd[0].revents & POLLIN)
			{	
				read(pfd[0].fd,buf,100);
				if(sigrcv==1)
				{
					printf("sig is 1 redirecting fifo\n");
					write(redir,buf,strlen(buf));
				}
				else
				{
					printf("From fifo : ");
					printf("%s\n",buf);
				}
			}
			if(pfd[1].revents & POLLIN)
			{
				char *buf2 = new char[100];
				read(pfd[1].fd,buf2,100);
				if(sigrcv==1)
				{
					printf("sig is 1 redirecting pipe msg\n");
					write(redir,buf2,strlen(buf2));
				}
				else
				{
					printf("From pipe : ");
					printf("%s\n",buf2);
				}
			}
			if(pfd[2].revents & POLLIN)
			{
				char *buf3 = new char[100];
				read(pfd[2].fd,buf3,100);
				if(sigrcv==1)
				{
					printf("sig is 1 redirecting popen o/p\n");
					write(redir,buf3,strlen(buf3));
				}
				else
				{
					printf("Popen output :\n");
					printf("%s\n",buf3);	
				}
			}
		}
	}
	else //it is child
	{
		while(1)
		{
			sleep(3);
			//printf("dsfsdf\n");
			close(pipefd[0]);
			char buf[] = "PipeMsg";//writes this message continously to server
			write(pipefd[1],buf,strlen(buf));
		}
	}
}