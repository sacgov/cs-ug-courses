/********************************************************
* Author 	: Sachin Govind
* Date   	: 03 March 2016 (Thursday)
* Title		: Poll server for internet_main_server.c
********************************************************/
// Info :  polls on the client ip and op and reports it to main server
//her server has to hold info about all the clients and the work that is being done
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <string.h>
#include <netdb.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/ipc.h>
#include <assert.h>
int main()
{
	int ffd ;
	//common fifo initialize
	mkfifo("common_iss_fifo", 0666|IPC_CREAT);
	ffd = open("common_iss_fifo",O_RDWR);
	assert(ffd>=0);
	int byte_count;
	char buffer[1024];
	printf("POLLSERVER started\n");
	while(1)
	{
		//output pollservers findings on the terminal
		byte_count = read(ffd ,buffer,sizeof(buffer));
		write(1,"POLLSERVER : ",13);
		write(1,buffer,byte_count);
	}
	
}