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
	char *arg[] = {"./forexe",(char *)0};
	if(c==0)
	{
		printf("im child process before exec\n" );
		execv("./forexe",arg);
	}
	else if(c<0)
	{
		printf("error\n");
	}
	else
	{
		printf("parent before wait\n");
		//int pid =wait(&status);//if wait is removed exec process becomes zombie and cannot return control to terminal
		printf("im parent process after wait\n");
	}

	return 0;
}
