#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#define MAX 100
int main()
{	
	int c =0,status ;
	int pp1[2];
	pipe(pp1);
	char buf[20] = "sachin";
	char bufw[10] = "hello";
	write(pp1[1],bufw,MAX);
	read(pp1[0],buf,MAX);
	printf("%s\n",buf );
	int ppc[2]; //read child
	int pp[2]; // read parent
	pipe(ppc);
	pipe(pp);
	//now it is verified that the pipe is working
	c = fork();
	if(c==0)
	{
		printf("im child process\n" );
		char buf[MAX] = "writing to parent";
		printf("%s\n",buf );
		close(pp1[0]);
		write(pp1[1],buf,MAX);

		//exit(1);
	}
	else if(c<0)
	{
		printf("error\n");
	}
	else
	{
		int pid =wait(&status);
		printf("im parent process\n");
		close(pp1[1]);
		char buf[MAX];
		read(pp1[0],buf,MAX);
		printf("reading the message -> %s \n",buf );
		//exit(0);
	}

	return 0;
}
