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
	int tag;
	char buff[50];
	void pack(char d[]);
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

int main()
{
	student s;
	buffer b;
	fout.open("varrying format.txt");
	cout<<"\nEnter 1 if you want the details of roll number : ";
	cout<<"\nEnter 2 if you want the details of roll number, name : ";
	cout<<"\nEnter 3 if you want the details of roll number, name and cgpa : "<<endl;
	cin>>b.tag;
	if (b.tag == 1)
	{
		cout<<"\nEnter roll number : ";
		cin>>s.rolno;
		b.pack(s.rolno);
	}
	
	if (b.tag == 2)
	{
		cout<<"\nEnter roll number : ";
		cin>>s.rolno;
		b.pack(s.rolno);
		
		cout<<"\nEnter name : ";
		cin>>s.name;
		b.pack(s.name);
	}
	
	if(b.tag == 3)
	{
		cout<<"\nEnter roll number : ";
		cin>>s.rolno;
		b.pack(s.rolno);
		
		cout<<"\nEnter name : ";
		cin>>s.name;
		b.pack(s.name);

		cout<<"\nEnter cgpa : ";
		cin>>s.cgpa;
		b.pack(s.cgpa);

	}	
	
	fout<<b.buff;
	fout.close();
	getch();
}


