/********************************************************
* Author 	: Sachin Govind								*
* Date   	: Jan 30 2016								*
* Title		: sends signal to pid sigusr1				*
********************************************************/
// Info : ssends signal to pid given by server which on receiving the signal redirects o/p to p5.c
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
	kill(atoi(argv[1]),SIGUSR1);
  return 0;
}