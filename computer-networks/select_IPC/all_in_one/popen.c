/********************************************************
* Author 	: Sachin Govind								*
* Date   	: 04 February 2016 (Thursday)							*
* Title		: this fust for execution by popen			*
********************************************************/
// Info : sends o/p to server
#include <unistd.h>
#include <stdio.h>
int main()
{
int i =50;
//sends five messages to server after five seconds
	while(i>=45)
	{
		printf("from popen\n");
		i--;
		//sleep(1);
	}
}