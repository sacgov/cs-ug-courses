#include<bits/stdc++.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

using namespace std;

#define MAX_BUF 50
int fd[2];
char * r_myfifo ;
char *w_myfifo;

void flush(char * buf)
{
    for(int i=0;i<MAX_BUF;i++)
    buf[i]='\0';
}

void reader()
{
            char buf[MAX_BUF];
            flush(buf);
            fd[1]=open(w_myfifo,O_RDWR);
            //cout<<fd[1]<<"\t"<<w_myfifo<<endl;
            if(fd[1]>=0)
            {
                read(fd[1], buf, MAX_BUF);
                printf("Received: %s", buf);
                sleep(2);
            }
            close(fd[1]);
}


void writer()
{
        char buf[MAX_BUF];
        flush(buf);
        fd[0]=open(r_myfifo,O_RDWR);
        printf("enter the input\n");
        gets(buf);
        sleep(2);
        write(fd[0], buf, MAX_BUF);
        close(fd[0]);
}

int main(int argv,char **args)
{
    r_myfifo=new char[MAX_BUF];
    flush(r_myfifo);
    strcpy(r_myfifo,"r_myfifo.txt");
    cout<<mkfifo(r_myfifo,0666)<<endl;
    w_myfifo=new char[MAX_BUF];
    flush(w_myfifo);
    strcpy(w_myfifo,"w_myfifo");
    char ch[3];
    ch[0]=args[0][strlen(args[0])-1];
    ch[1]='\0';
    strcat(w_myfifo,ch);
    strcat(w_myfifo,".txt");
    cout<<mkfifo(w_myfifo,0666)<<endl;

    int status=0;
    int var=1;

    while(1)
    {
        writer();
        reader();
        //cout<<"while end";
    }

    return 0;

}



