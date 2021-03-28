/********************************************************
* Author 	: Sachin Govind
* Date   	: 03 March 2016 (Thursday)
* Title		: provides services to clients 
********************************************************/
// Info : internet main server "execs" this to service its clients

#include <stdio.h>
#include <ctype.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/ipc.h>

int main()
{
	//writes to poll server about its doings by opening it
	mkfifo("common_iss_fifo",0666|IPC_CREAT);
	int ffd = open("common_iss_fifo",O_RDWR);
	write(1,"Enter the lines to captilise\n",30);
	char buffer[1024];
	int i;
	while(1)
	{
		//read from nsfd 0 is nsfd of main server
		int length = read(0,buffer,sizeof(buffer));
		//wrote to poll server
		write(ffd,buffer,length);
		i = length - 1;
		while(i >= 0)
		{
			buffer[i] = toupper(buffer[i]);
			i--;
		}
		//write to client
		write(1,buffer,length);
		sleep(1);
	}
}