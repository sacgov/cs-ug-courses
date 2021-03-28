#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
int main()
{	
	int c =0,status ;
	for(c =0;c<10;c++) //to check for parallel execution
	printf("im from exec\n");

	return 0;
}
