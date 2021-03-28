/********************************************************
* Author 	: Sachin Govind								*
* Date   	: 29 Jan 2016								*
* Title		: fifo.c									*
********************************************************/
// Info : sends information by fifo to server
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/stat.h>
#include <sys/types.h>
int main()
{
	mkfifo("all",0666);
	int fd = open("all",O_RDWR);
	char *buf=new char[100];
	
	
	int k = 0;
	while(1)
	{
		scanf("%s",buf);
		printf("wrietr\n");
		write(fd,buf,strlen(buf));
	}
	//sleep(5000);
	//while(1){
	//}
	//printf("%s\n",buf );
}