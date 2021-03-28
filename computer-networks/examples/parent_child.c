#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
int main()
{	
	int c =0,status ;
	c = fork();
	if(c==0)
	{
		printf("im child process\n" );
	}
	else if(c<0)
	{
		printf("error\n");
	}
	else
	{
		int pid =wait(&status);
		printf("im parent process\n");
	}

	return 0;
}
