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
    cout<<mkfifo("crc.dat",0666)<<endl;
    while(1)
    {
        int k=0,t=0,*pos,m;
        string msg;
        cin>>msg;cout<<(msg)<<"\n";
        //reverse(msg.begin(), msg.end());
        int r=num_red_bit(msg.length());
        pos=new int[r];for(int i=0;i<r;i++)pos[i]=0;
        m=msg.length();
        unsigned int total=m;

        bitset<100> message;

        for(int i=1;i<m+r;i++)
        {
            if(i==pow(2,k))
            {
                k++;continue;
            }
            message.set(i,msg[t++]-48);
        }

        for(int i=1;i<=m+r;i++)
        {
            int p=0,t=i;
            while(t>0)
            {
                if(t&1)
                pos[p]^=message[i];
                t>>=1;p++;
            }
        }

        for(int i=0;i<r;i++)
        {
            message.set(pow(2,i),pos[i]);
        }cout<<"message\t"<<message<<endl;

        int iSecret, iGuess,aSecret;

          /* initialize random seed: */
          /* generate secret number between 0 and 9: *///cout<<msg_cpy<<endl;
          iSecret = rand() % (m+r)+1;
          aSecret=rand() % 2;
          for(int i=1;i<=total+r;i++)cout<<message[i];cout<<endl;
          cout<<"random\t"<<iSecret<<"\t"<<aSecret<<endl;
            message.set(iSecret,aSecret);
            //cout<<message<<endl
            string mystring=message.to_string<char,std::string::traits_type,std::string::allocator_type>();

            //cout<<mystring<<endl;

            int fd=open("crc.dat",O_WRONLY);
            m=mystring.length();
            char ch[200];int i;
            for(i=0;i<m;i++)
            ch[i]=mystring[i];
            ch[i++]=' ';
            while(total>0)
            {
                ch[i++]=total%10+48;
                total=total/10;
            }
            ch[i]='\0';
            //cout<<"write\t"<<ch<<endl;
            //puts(ch);//cout<<strlen(ch)<<endl;
            write(fd,ch,strlen(ch));
    }
    return 0;
}
