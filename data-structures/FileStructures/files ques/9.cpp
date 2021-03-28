#include<iostream>
#include<fstream>
#include<string.h>

using namespace std;


char buffer[100]="\0";
char buffer2[100]="\0";
void pack(char *a,int fno)
{
	strcat(buffer,a);
	if(fno==0)
	strcat(buffer,"|");
	else
	strcat(buffer,"|#");
}
void pack2(char *a,int fno)
{
	strcat(buffer2,a);
	if(fno==0)
	strcat(buffer2,"|");
	else
	strcat(buffer2,"|#");
}

void flush()
{
	strcpy(buffer,"\0");
}
void flush2()
{
	strcpy(buffer2,"\0");
}

void unpack(char *f)
{
	int i=0;
	for(;buffer[0]!='|';i++)
	   {
	   	f[i]=buffer[0];
	   	for(int j=0;j<strlen(buffer);j++)
	   	   buffer[j]=buffer[j+1];


	   }
	   f[i++]='\0';
	for(int j=0;j<strlen(buffer);j++)
 	   	   buffer[j]=buffer[j+1];

}

struct st1
{
	char rno[10];
	char mark[4];
	int count;
};

void input(st1 &s)
{
   cout<<"\n\nEnter the rollno: ";
   cin>>s.rno;
   pack(s.rno,0);

   	cin>>s.mark;
    pack(s.mark,1);
}
void create()
{
	ofstream f1("sub1.txt");
	ofstream f2("sub2.txt");
	ofstream f3("sub3.txt");
	st1 s;
	int n;
	cout<<"\n\nEnter the number of records for 1st sub: ";
	cin>>n;
	for(int i=0;i<n;i++)
	{
		input(s);
		f1<<buffer;
		flush();

	}
	cout<<"\n\nEnter the number of records for 2nd sub: ";
	cin>>n;
	for(int i=0;i<n;i++)
	{
		input(s);
		f2<<buffer;
		flush();

	}
	cout<<"\n\nEnter the number of records for 3rd sub: ";
	cin>>n;
	for(int i=0;i<n;i++)
	{
		input(s);
		f3<<buffer;
		flush();

	}
	f1.close();
	f2.close();
	f3.close();
}
void checksubs()
{
	ofstream f4("count.txt");
	ifstream f1("sub1.txt");
	ifstream f2("sub2.txt");
	ifstream f3("sub3.txt");
	string a;
	string b;
	string c;
	st1 s1,s2,s3;


	while(getline(f1,a,'#'))
	{
		strcpy(buffer,a.c_str());
		unpack(s1.rno);
		pack2(s1.rno,0);
		unpack(s1.mark);
		pack2(s1.mark,0);
		flush();
		while(getline(f2,b,'#'))
		{
			strcpy(buffer,b.c_str());

			unpack(s2.rno);
			if(strcmp(s2.rno,s1.rno)==0)
			  {
			  	unpack(s2.mark);
			    pack2(s2.mark,0);
			    flush();
		      }
			else
			 flush();
		}
		while(getline(f3,c,'#'))
		{
			strcpy(buffer,c.c_str());
			cout<<buffer<<endl;
			unpack(s3.rno);
			if(strcmp(s3.rno,s1.rno)==0)
			   {
			   	unpack(s3.mark);
			    pack2(s3.mark,0);
			   flush();
		      }
			else
			 flush();
		}
	   pack2("\b",1);
	   f4<<buffer2;
	   flush2();
	   flush();

	}
	f1.close();
	f2.close();
	f3.close();
	f4.close();
}

int main()
{
	create();
	checksubs();
	return 0;
}
