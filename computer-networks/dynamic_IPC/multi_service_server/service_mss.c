/********************************************************
* Author 	: Sachin Govind
* Date   	: 04 February 2016 (Thursday)
* Title		: service_mss
********************************************************/
// Info : provides service by request argv[2] to client
// sends the service in argv[1] fifo as stated by client
//three instances are created by run.sh
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
	printf("inexec\n");
	mkfifo(argv[1],0666);
	//writes to client by opening a fifo to it
	int fd = open(argv[1],O_RDWR);
	strcat(argv[2]," is provided to you");
	write(fd,argv[2],100);
	printf("complted\n");

}
