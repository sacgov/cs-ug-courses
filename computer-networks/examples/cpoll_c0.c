#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <pthread.h>
#include <fcntl.h>
#include <sys/ipc.h>
int creadfd,cwritefd;
char buf[1000];
char buf2[1000];
void * writer()
{
	while(1)
	{
		printf("enter message to send : \n");
		scanf("%s",&buf);
		write(cwritefd,buf,1000);
		printf("hnv\n");
		usleep(1000);
	}
}
void * reader()
{
	while(1)
	{
		read(creadfd,buf2,1000);
		printf("reader\n");
		printf("%s\n",buf2 );
		usleep(1000);
	}
}
int main()
{
	int c = mkfifo("c0",0666);
	int c1 = mkfifo("ser0",0666);
	creadfd = open("ser0",O_RDWR);
	cwritefd = open("c0",O_RDWR);
	printf("%d%d\n",c,c1 );
	exit(0);
	pthread_t p1,p2;
	pthread_create(&p1,NULL,&writer,NULL);
	pthread_create(&p2,NULL,&reader,NULL);
	pthread_join(p1,NULL);
	pthread_join(p2,NULL);
}