#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <string.h>
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
		char buf[MAX] = "message to parent";
		printf("%s\n",buf );
		printf("1\n");
		close(ppc[1]);
		read(ppc[0],buf,MAX);
		printf("reading in child ->%s\n",buf );
		printf("2\n");
		close(pp[0]);
		write(pp[1],buf,MAX);
		printf("3\n");
		

		//exit(1);
	}
	else if(c<0)
	{
		printf("error\n");
	}
	else
	{
		//int pid =wait(&status);
		printf("im parent process\n");
		char buf[MAX];
		printf("4\n");
		close(ppc[0]);
		strcpy(buf,"msg to child");
		write(ppc[1],buf,MAX);
		printf("5\n");
		close(pp[1]);
		read(pp[0],buf,MAX);
		printf("6\n");
		printf("reading the message in parent-> %s \n",buf );
		
		//exit(0);
	}

	return 0;
}
