#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
int main()
{	
	int c =0,status ;
	printf("this is first\n");
	c = fork();
	if(c==0)
	{
		int pid =wait(&status); //add wait or comment it not here in parent
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
//wait in child has no difference wait polls on child process of calling threaad and suspends the calling thread
