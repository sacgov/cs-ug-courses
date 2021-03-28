#include <bits/stdc++.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <bitset>
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
    int fd=open("crc.dat",O_RDONLY);

    while(1)
    {
    	string agreed_polynominal="1011";
    	char mystring[max+1];
        read(fd,mystring,max);

        string msg;
        cout<<"mystring : "<<mystring<<endl;
        for(int i=0;i<strlen(mystring);i++)
        msg+=mystring[i];

        bitset<max> message(msg);
        cout<<message<<endl;
        int m=agreed_polynominal.length();

        for(int i=0;i<(position(message)-m)+1;i++)
        {
            agreed_polynominal+="0";
        }

        bitset<max> pol(agreed_polynominal);//
        cout<<pol<<endl;
        int pos1,pos2;

        cout<<"message\t"<<message<<"\n";
        cout<<"poly\t"<<pol<<"\n";
        pos2=position(message);

        //cout <<"xor\t"<< (message^=pol) << '\n';
        while(pos2>m-2)
        {
            pos1=position(message);//cout<<"pos1\t"<<pos1<<endl;
            message^=pol;//cout<<"message\t"<<message<<endl;
            pos2=position(message);//cout<<"pos2\t"<<pos2<<endl;
            pol>>=(pos1-pos2);  //cout<<"pol\t"<<pol<<endl;
            //sleep(2);
        }//cout<<message<<endl;
        if(position(message)==-1)
        {
            cout<<"msg received without error\n";
        }
        else
        {
            cout<<"MSG CONTAINS SOME ERROR :) :)\n";
        }
    }
    return 0;
}












