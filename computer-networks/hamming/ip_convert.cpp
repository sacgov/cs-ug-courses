#include<bits/stdc++.h>
#include<unistd.h>
using namespace std;

string hex_rep="";
int dec_rep[4];

void hex(bitset<32> bits)
{
    int sum=0,i;
    for(i=0;i<4;i++)
    {
        if(bits.test(i))
        {
            sum+=pow(2,i);
        }
    }
    switch(sum)
    {
        case 10:hex_rep+="A";break;
        case 11:hex_rep+="B";break;
        case 12:hex_rep+="C";break;
        case 13:hex_rep+="D";break;
        case 14:hex_rep+="E";break;
        case 15:hex_rep+="F";;break;
        default:hex_rep+=(sum+48);break;
    }
}

int value(char ch)
{//cout<<ch<<"\t";
    switch(ch)
    {
        case 'A':return(10);break;
        case 'B':return(11);break;
        case 'C':return(12);break;
        case 'D':return(13);break;
        case 'E':return(14);break;
        case 'F':return(15);break;
        default:return(ch-48);
    }
}


void deci()
{
    int val=0,k=0;
    for(int i=hex_rep.length()-1;i>=0;i-=2)
    {
            val=value(hex_rep[i]);
            val+=16*value(hex_rep[i-1]);
            dec_rep[k++]=val;
    }
}

int main()
{
    string bit;
    cin>>bit;
    reverse(bit.begin(), bit.end());
    bitset<32> bits(bit);
    //bitset<4> hex;
    //cout<<bits;
    int size=32;
    while(size>0)
    {size-=4;
      hex(bits);
      bits>>=4;
    }
    cout<<"hex_decimal representation :\t"<<hex_rep<<endl;
    deci();
    cout<<"IP address is:\t";
    for(int i=3;i>=0;i--)
    {
        if(i>=0&&i<3)
        cout<<".";
        cout<<dec_rep[i];
    }
    cout<<endl;
    return 0;
}
