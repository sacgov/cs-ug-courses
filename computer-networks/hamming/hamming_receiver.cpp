#include<bits/stdc++.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include<string.h>
#include<bitset>
#include<stdlib.h>
#include <unistd.h>

using namespace std;

int num_red_bit(int m)
{
    int r=0;
    while(pow(2,r)<(m+r+1))
    r++;
    return r;
}

void print(int pos[],int r)
{
for(int i=0;i<r;i++)cout<<pos[i]<<"\t";//cout<<endl;
}

int main()
{
    while(1)
    {
        int size=0,k=0,i;
        int fd=open("crc.dat",O_RDONLY);

        char msg_read[200];
        read(fd,msg_read,200);
        //puts(msg_read);
        char mystring[101];
        for(i=0;msg_read[i]!=' ';i++)
        mystring[i]=msg_read[i];
        mystring[i]='\0';//puts(mystring);
        for(int i=strlen(mystring)+1;i<strlen(msg_read);i++)
        {
            size+=pow(10,k)*(msg_read[i]-48);
            k++;
        }//cout<<size<<endl;


        int r=num_red_bit(size);
        int *pos;
        pos=new int[r];
        for(int i=0;i<r;i++)pos[i]=0;
        //print(pos,r);cout<<endl;

        string msg;
        for(int i=0;i<strlen(mystring);i++)
        msg+=mystring[i];

        bitset<100> message(msg);//cout<<message<<endl;

        for(int i=1;i<=size+r;i++)
        {//cout<<i<<"\t";
            int p=0,t=i;
            while(t>0)
            {
                if(t&1)
                pos[p]^=message[i];
                //print(pos,r);//cout<<p<<"\t"<<t<<"\t";
                t>>=1;p++;//cout<<t<<"\t"<<endl;
            }
        }print(pos,r);
        cout<<endl;
        int sum =0;
        for(int i=0;i<r;i++)
        {
            if(pos[i]==1)
            {
                sum+=pow(2,i);
            }
        }
        cout<<"pos is \t"<<sum<<endl;
        if(sum!=0)
        message.flip(sum);
        for(int i=1,k=0;i<=size+r;i++)
        {
            if(i==pow(2,k))
            {
                k++;continue;
            }
            cout<<message[i];
        }cout<<endl;
    }
    return 0;
}
