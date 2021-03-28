/********************************************************
* Author 	: Sachin Govind
* Date   	: 30 January 2016 (Saturday)
* Title		: service_mss
********************************************************/
// Info : provides service by request argv[2] to client
// sends the service in argv[2] fifo as stated by client
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <poll.h>
#include <sys/ipc.h>
#include <string.h>
int main(int argc,char *argv[])
{
	//below four are for writing
	//printf("inexec\n");
	mkfifo(argv[1],0666);
	//printf("%s\n",argv[1] );
	int fd = open(argv[1],O_RDWR);
	strcat(argv[2]," is provided to you");
	write(fd,argv[2],100);

}
