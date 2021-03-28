#include<bits/stdc++.h>
#include <fcntl.h>
#include <sys/stat.h>
#include<string.h>
#include <unistd.h>
#include <stdlib.h>
using namespace std;

pthread_mutex_t kbd=PTHREAD_MUTEX_INITIALIZER;

#define client 2
int fd[2*client];
char r_myfifo[client][50] ;
char w_myfifo[client][50] ;
int name=-1;
int n_names=0,total=0,pos=0,mvar=0;
#define MAX_BUF 1024
char str[MAX_BUF];
char buf[MAX_BUF];

void flush(char * buf)
{
    for(int i=0;i<MAX_BUF;i++)
    buf[i]='\0';
}

void fflush(char *buf)
{
    for(int i=0;i<50;i++)buf[i]='\0';
}


void *writer(void *etc)
{
    while(1)
    {
        sleep(3);
        for(int i=0;i<client;i++)
        {
            flush(buf);
            //cout<<"the value of is before\t"<<fd[i]<<"\n";
            fd[i]=open(r_myfifo[i],O_RDONLY);
            //cout<<"the value of is\t"<<fd[i]<<"\n";
            mvar=0;
            read(fd[i], buf, MAX_BUF);
            if(buf!=NULL)
            {
                printf("Received: %s\t%d\n", buf,total);
                strcpy(str,buf);
                name=i;
                total++;
                if(n_names>client)
                {
                    n_names=0;
                }
            }
            close(fd[i]);
        }
    }
}

void *kbdreader(void * etc)
{
    //cout<<"inside reader\n";
    while(1)
    {
        //for(int i=0;i<client;i++)close(fd[i]);
        sleep(3);
        int var=0;
        while(name==-1){}pos=0;
        for(int i=0;i<client;i++)
        {//cout<<"name\t"<<name<<endl;
            if(i!=name)
            {
                //pthread_mutex_lock(&kbd);
                fd[client+pos]=open(w_myfifo[i],O_WRONLY);
                //cout<<"enter the input  "<<fd[client+pos]<<"\t"<<pos<<"\t"<<buf<<"\t"<<str<<endl;

                write(fd[client+pos], str, MAX_BUF);
                flush(str);
                close(fd[client+pos]);
                pos++;
            }
            else{name=-1;}

            //pthread_mutex_unlock(&kbd);
        }
    }
}

int main()
{
    char ch1[50]="r_myfifo";
    char ch2[50]="w_myfifo";
    char ch3[50];
    for(int i=0;i<client;i++)
    {
        fflush(ch3);
        ch3[0]=i+48;
        ch3[1]='\0';
        fflush(ch1);
        fflush(ch2);
        strcpy(ch2,"w_myfifo");
        strcpy(ch1,"r_myfifo");
        //cout<<ch3<<"\t";
        strcat(ch1,ch3);
        //cout<<ch3;
        strcat(ch1,".txt");
        strcat(ch2,ch3);
        strcat(ch2,".txt");
        strcpy(r_myfifo[i],ch1);
        strcpy(w_myfifo[i],ch2);
        //cout<<ch3[0]<<"\t"<<ch2<<"\n";
        cout<<mkfifo(w_myfifo[i],0666);
    }

        pthread_t kbdthread,writethread;//cout<<"hello world\n";

        pthread_create(&writethread,NULL,writer,NULL);
        pthread_create(&kbdthread,NULL,kbdreader,NULL);

        pthread_join(writethread,NULL);
        pthread_join(kbdthread,NULL);


    return 0;
}
