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


int main()
{

int status;
char path[100];
FILE *fp;
//run any program to test
fp = popen("./pp","r");;
printf("hi\n");
if (fp == NULL)
    printf("err\n");;
struct pollfd pfd[2];
pfd[0].fd = fileno(fp);
pfd[0].events = POLLIN;
char buf[100];
while(1)
{
	//printf("kill\n");
	while(poll(pfd,3,3000)<=0)
			{printf("inpoll\n");}
	if(pfd[0].revents & POLLIN)
			{	
				read(pfd[0].fd,buf,100);

					printf("%s\n",buf);
			}

}
}