/********************************************************
* Author 	: Sachin Govind
* Date   	: 30 January 2016 (Saturday)
* Title		: client
********************************************************/
// Info : requests service from service coordinator 
// args : fifo of c0 and cw0(number 0 to 3 according to client number) for sending to mss and reading from server respectively
// enter the service required to get it
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <poll.h>
int main(int argc,char *argv[])
{
	mkfifo(argv[1],0666);
	mkfifo(argv[2],0666);
	int fd = open(argv[1],O_RDWR);
	int fdw = open(argv[2],O_RDWR);//from service
	
	while(1)
	{
		char *buf = malloc(100*sizeof(char));
		printf("enter the service required\n");
		scanf("%s",buf);
		//printf("%d\n",(int)strlen(buf) );
		write(fd,buf,100);
		sleep(3);
		//printf("the value is :\n");
		char *buf2= malloc(100*sizeof(char));
		read(fdw,buf2,100);
		printf("%s\n",buf2 );
	}
	
}
