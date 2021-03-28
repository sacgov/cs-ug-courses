#include <bits/stdc++.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <poll.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <signal.h>
using namespace std;

#define client 1
int fd[2*client],pos;
char r_myfifo[50] ;
char w_myfifo[client][50] ;
#define MAX_BUF 50
char str[MAX_BUF];
char buf[MAX_BUF];
char temp[MAX_BUF];
char gau[MAX_BUF];
struct pollfd plfd[MAX_BUF];
char cpy[MAX_BUF];
struct Shdata
{
    int data;
    int busy;
    char buf[MAX_BUF];
    int pos;
};
Shdata *shdata;


void flush(char * buf)
{
    for(int i=0;i<MAX_BUF;i++)
    buf[i]='\0';
}

void fflush(char *buf)
{
    for(int i=0;i<50;i++)buf[i]='\0';
}

void flushargg(char *args)
{
    for(int i=0;args[i]!='\0';i++)buf[i]='\0';
}

void intialize()
{
        fd[0]=open(r_myfifo,O_RDWR);
        plfd[0].fd=fd[0];
        plfd[0].events=POLLIN;
}

int reader()
{
        int res=poll(plfd, client, 0);
            if(res>0)
            {
                flush(str);
                if(plfd[0].revents & POLLIN)
                {
                flush(buf);
                flush(cpy);
                read(plfd[0].fd, buf, MAX_BUF);
                    if(buf[0]!='\0')
                    {
                        strcpy(str,buf);
                        int i=0,j;
                        for(i=0;str[i]!=' ';i++);
                        i++;
                        for(j=0;str[i]!='\0';j++)
                        cpy[j]=str[i++];
                        cpy[j]='\0';
                        printf("Received: %s\t\n", cpy);
                        printf("Received: %s\t\n", buf);
                        sleep(2);
                        return 1;
                    }
                }
        }
        return -1;

}


int main()
{
    char ch1[50]="r_myfifo";
    char ch2[50]="w_myfifo";
    char ch3[50];
    strcpy(r_myfifo,"r_myfifo.txt");
    for(int i=0;i<client;i++)
    {
        fflush(ch3);
        ch3[0]=i+48;
        ch3[1]='\0';
        fflush(ch1);
        fflush(ch2);
        strcpy(ch2,"w_myfifo");
        strcpy(ch1,"r_myfifo");
        strcat(ch1,ch3);
        strcat(ch1,".txt");
        strcat(ch2,ch3);
        strcat(ch2,".txt");
        strcpy(w_myfifo[i],ch2);
    }

    int status=0;
    FILE *in;
	char buff[512];
	intialize();

    char *argg[client+3];
    flush(gau);
    int var=1;

    int shmid=shmget(526,1000,IPC_CREAT|0666);
    if(shmid<0)cout<<"error\n";
    shdata=new Shdata[MAX_BUF];
    shdata=(Shdata *)shmat(shmid,NULL,0);
    shdata[0].pos=0;

    int flag=1;
    shdata[0].busy=0;
    flush(shdata[0].buf);
    while(1)
    {

        pos=-1;
        if(flag==1&&((pos=reader())<0))continue;
        for(int i=0;i<shdata[0].pos;i++)
        {
            if(shdata[i].busy==0)
            {
                flag=1;
                strcpy(shdata[i].buf,cpy);
                kill(shdata[i].data,SIGUSR1);
                break;
            }
            else
            {
                flag=0;
            }
        }
    }
}
