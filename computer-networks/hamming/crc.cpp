/********************************************************
* Author     : Sachin Govind
* Date       : 14 February 2016 (Sunday)
* Title      : Sends the message for implementing Cyclic Redundancy Check
********************************************************/
// Info : Message Sender of Cyclic Redundancy Check implementation 
#include <bits/stdc++.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <bitset>
#include <stdlib.h>
#include <unistd.h>
#include <iostream>

#define max 20
using namespace std;

int position(bitset<max> message)
{
    int pos=-1;
        for(int i=0;i<message.size();i++)
        {
            if(message.test(i))
            {
                pos=i;
            }
        }
        return pos;
}


int main()
{
    mkfifo("crc.dat",0666);
    while(1)
    {
        string msg,cpy;
        string agreed_polynomial="1011";
        cin>>msg;//agreed_polynomial;

        for(int i=1;i<agreed_polynomial.length();i++)
        {
            msg+="0";
        }
        int m=agreed_polynomial.length();

        for(int i=0;i<(msg.length()-m);i++)
        {
            agreed_polynomial+="0";
        }

        cpy=msg;
        cout<<"message :"<<msg<<"    "<<"POLY :"<<agreed_polynomial<<endl;
        bitset<max> message(msg);
        bitset<max> pol(agreed_polynomial);
        int pos1,pos2;

        cout<<"message\t"<<message<<"\n";
        cout<<"pol\t"<<pol<<"\n";
        pos2=position(message);

        //cout <<"xor\t"<< (message^=pol) << '\n';
        while(pos2>m-2)
        {
            pos1=position(message);
            cout<<"pos1\t"<<pos1<<endl;
            message^=pol;
            cout<<"message\t"<<message<<endl;
            pos2=position(message);
            cout<<"pos2\t"<<pos2<<endl;
            pol>>=(pos1-pos2);
            cout<<"pol\t"<<pol<<endl;
        }
        cout<<"the crc is:\t"<<message<<endl;

        bitset<max> msg_cpy(cpy);

        for(int i=0;i<m-1;i++)
        {
            if(message.test(i))
            msg_cpy.set(i,1);
        }

        //cout<<"msg_cpy\t"<<msg_cpy<<endl;

        int iSecret, iGuess;

      /* initialize random seed: */
      //srand (time(NULL));

      /* generate secret number between 0 and 9: *///cout<<msg_cpy<<endl;
      iSecret = rand() % 10;
      cout<<"random\t"<<iSecret<<endl;
        msg_cpy.set(iSecret,1);
        //cout<<msg_cpy<<endl;

        string mystring=msg_cpy.to_string<char,std::string::traits_type,std::string::allocator_type>();

        cout<<mystring<<endl;

        int fd=open("crc.dat",O_WRONLY);
        m=mystring.length();
        char ch[101];
        for(int i=0;i<m;i++)
        ch[i]=mystring[i];
        //cout<<"write\t"<<ch<<endl;
        write(fd,ch,m);
    }

    return 0;
}