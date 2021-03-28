/********************************************************
* Author 	: Sachin Govind
* Date   	: 30 January 2016 (Saturday)
* Title		: dup/dup2
********************************************************/
// Info : dup and dup2 practice open a file abc for its working
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
int main()
{
	int fd = dup(1);
	write(1,"welcome\n",8);
	// 1 and fd are interchangeable
	int infd = open("abc",O_RDWR);
	int k = dup2(infd,1);
	//printf("%d\n",k );
	//write(infd,"welcome input\n",14);
	//char * buf = malloc(20*sizeof(char));
	//scanf("%s",buf);
	//printf("%s\n",buf );
	//int dfd = dup(1);
	printf("gh\n");
	write(infd,"welcome input\n",14);
	close(infd);
}
