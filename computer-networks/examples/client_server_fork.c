#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
int main(int argc,char *argv[])
{
	int i;
	//printf("%s\n",argv[i] );
	for(i=0;i<argc ;i++){
	FILE * f1 = popen(argv[i],"r");
	dup2(fileno(f1),1);}

}