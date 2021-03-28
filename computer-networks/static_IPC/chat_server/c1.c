#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <pthread.h>
#include <fcntl.h>
#include <sys/ipc.h>
int fd,n,fd1;
char *buffer;
char *buffer1;

void *thread1()
{
	while(1)
	{
		printf("Enter the value\n");
		scanf("%s",buffer);
		write(fd,buffer,256);
		usleep(1000);
	}

}

void *thread2()
{
	while(1)
	{
		read(fd1,buffer1,256);
		printf("%s\n",buffer1);
		usleep(1000);
	}
}

int main(int argc,char *argv[])
{
	buffer1 = malloc(256*sizeof(char));
	buffer = malloc(256*sizeof(char));
	int f=mkfifo("cs1",0666);
	int f1=mkfifo("s1",0666);
	printf("%d%d\n",f,f1 );
	fd=open("cs1",O_RDWR);
	fd1=open("s1",O_RDWR);
	pthread_t p1,p2;
	pthread_create(&p1,NULL,&thread1,NULL);
	pthread_create(&p2,NULL,&thread2,NULL);
	pthread_join(p1,NULL);
	pthread_join(p2,NULL);
}

	
	
