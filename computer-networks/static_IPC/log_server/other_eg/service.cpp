#include<bits/stdc++.h>
#include <fcntl.h>
#include <sys/stat.h>
#include<string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include<signal.h>
using namespace std;

#define client 2
int fd[2*client],pos;
char r_myfifo[client][50] ;
char w_myfifo[client][50] ;
#define MAX_BUF 50
char str[MAX_BUF];

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


void writer(char *buf)
{
        int w_fd;
        char str1[MAX_BUF]="signal sent to the client\n";
        w_fd=open(buf,O_RDWR);
        write(w_fd, str1, MAX_BUF);
        close(w_fd);
}

void handler(int sig)
{
    strcpy(str,"w_myfifo");
    strcat(str,shdata[shdata[0].pos-1].buf);
    strcat(str,".txt");
    //cout<<(shdata[0].pos)-1<<endl;
    shdata[shdata[0].pos-1].busy=1;
    writer(str);
    cout<<"sleeping\n";
    sleep(5);
    cout<<"woke up after 5 sec\n";
    shdata[shdata[0].pos-1].busy=0;
    cout<<"service completed\n";
}

int shmid;

void myhandler(int signum)
{
    shmdt(shdata);
    cout<<"ctrl+l\n";
}


int main(int args,char **argg)
{
    shmid=shmget(526,1000,IPC_EXCL|0666);
    if(shmid<0)cout<<"error\n";
    shdata=new Shdata[MAX_BUF];
    if((shdata=(Shdata *)shmat(shmid,NULL,0))<0)cout<<"error in attachment\n";
    shdata[shdata[0].pos].data=getpid();
    flush(str);
    shdata[shdata[0].pos].busy=0;
    shdata[shdata[0].pos].pos++;
    shdata[shdata[0].pos].busy=0;
    flush(shdata[shdata[shdata[0].pos].pos].buf);
    signal(SIGUSR1,handler);
    for(;;);

    return 0;
}


