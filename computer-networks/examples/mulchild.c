#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
int main()
{	
	//printf("this is first\n");
	int c =0,status,i ;
	for(i=0;i<3;i++)
	{
		c = fork();
		if(c==0)
		{
			printf("im child process %d\n",i );
			exit(1);
		}
		else if(c<0)
		{
			printf("error\n");
		}
		else
		{
			int pid =wait(&status);
			//printf("im parent process\n"); //prints three times
		}
	}
	printf("parent program\n"); //prints one time

	return 0;
}
