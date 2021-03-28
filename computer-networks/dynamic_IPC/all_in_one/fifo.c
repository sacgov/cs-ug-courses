/********************************************************
* Author 	: Sachin Govind								*
* Date   	: 04 February 2016 (Thursday)							*
* Title		: fifo.c									*
********************************************************/
// Info : sends information by fifo to server by taking i/p from user
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
	mkfifo("all",0666); //create a fifo
	int fd = open("all",O_RDWR);
	char *buf=new char[100];
	
	printf("Enter messages to send to server : \n");
	int k = 0;
	while(1)
	{
		scanf("%s",buf); //takes i/p and writed it server which is polling for this i/p
		//printf("wrietr\n");
		write(fd,buf,strlen(buf));
	}
	//sleep(5000);
	//while(1){
	//}
	//printf("%s\n",buf );
}