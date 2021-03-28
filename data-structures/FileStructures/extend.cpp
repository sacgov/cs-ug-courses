#include <iostream>
#include <string>
#include <cmath>
using namespace std;
struct bucket
{
	int daata[100];
	int d1=0;
};
int get(int d)
{
	return(pow(2,d));
}
string bin(int k)
{
	int h=0;string s;
	while(k>0)
	{
		s[h++]='a';
		k=k/2;
	}
	cout<<"S"<<s;
	return s;
}
int main()
{
	bucket* b[100];
	int d=4;
	int din=get(d);
	string s=bin(d);
	cout<<"s"<<s<<"s";
	while(1)
	{
		int num;
		cout<<"enter number to insert :";
		cin>>num;
		if(num<0)
			break;
		//insert(num,b,d);
	}

}
