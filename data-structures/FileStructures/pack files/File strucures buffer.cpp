#include<iostream>
#include<cstring>
#include<conio.h>
#include<fstream>
using namespace std;
ofstream fout;
class student
{	public:
	char rolno[7];
	char name[20];
	char cgpa[4];
};

class buffer
{	public:
	char buff[50];
	void pack(char d[]);
	void unpack();
	buffer()
	{
		buff[0]='\0';
	}
};

void buffer :: pack(char d[])
{
	strcat(buff,d);
	strcat(buff,"-");
}

void buffer :: unpack()
{
	int m;
	m = strlen(buff);
	for(int i=0; i<m ; i++)
	{
		if (buff[i] == '-')
		{
			for(static int j=0 ; j<i ; j++)
			{
				fout<<buff[j];
			}
		}
	}
}

int main()
{	
	int i;
	student s;
	buffer b;
	fout.open("buffer.txt");
	cout<<"\nEnter student roll number";
	cin>>s.rolno;
	b.pack(s.rolno);
	cout<<"\nEnter student name :";
	cin>>s.name;
	b.pack(s.name);
	cout<<"\nEnter cgpa";
	cin>>s.cgpa;
	b.pack(s.cgpa);
	b.unpack();
	fout.close();
}
