/********************************************************
* Author 	: Sachin Govind								*
* Date   	: 04 February 2016 (Thursday)								*
* Title		: sends signal to pid sigusr1				*
********************************************************/
// Info : sends signal to pid given by server which on receiving the signal server redirects o/p to p5.c
//argv[1] is signal
#include <stdio.h>
#include <signal.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <poll.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(int argc,char *argv[])
{
	sleep(5);
	kill(atoi(argv[1]),SIGUSR1);//sends signal to server
  return 0;
}