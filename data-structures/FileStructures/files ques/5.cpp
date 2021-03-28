
#include<iostream>
#include<fstream>
#include<string.h>

using namespace std;

char buffer[100];;
struct stu
{
	char *name;
	char rno[2];
};
struct stu2
{
	char name[8];
	char rno[2];
};void pack(char *a,int fno)
{
	strcat(buffer,a);
	if(fno==0)
	strcat(buffer,"|");
	else
	strcat(buffer,"|#");
}
void flush()
{
	strcpy(buffer,"\0");
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

void findinti(char *a,char *b)
{
	int noofw=0;
	for(int i=0;i<=strlen(a);i++)
	{
		if(a[i]==' ' || a[i]=='\0')
		   noofw++;
	}
	int noofspaces=8-2*noofw+2;
	int big=0;
	int index=0;
	int c=0;
	for(int i=0;i<=strlen(a);i++)
	{

		if(a[i]==' ' || a[i]=='\0')
		   {
		   	  if(c>big && c<=noofspaces )
		   	  {
		   	  	big=c;
		   	  	index=i-c;
		   	  }
		   	  c=0;
		   }
		   c++;
	}

	int k=0;
	for(;k<big;k++)
	{
		b[k]=a[index+k];
	}
	b[k++]=' ';
	if(index!=0)
	  {
	   b[k++]=a[0];
	   b[k++]=' ';
      }

	for(int i=0;i<strlen(a);i++)
	   if(a[i]==' ' && i!=index)
	      {
	        b[k++]=a[i+1];
			b[k++]=' ';
	      }
	      b[k]='\n';
	      b[k+1]='\0';
   cout<<b;
}
void input(stu2 &s)
{
	cout<<"\n\nEnter the name: ";
    cin>>s.name;
    cout<<"\n\nEnter the rollno: ";
    cin>>s.rno;

}
void input(stu &s)
{
	string n;
	cout<<"\n\nEnter the name: ";
	cin.get();
    getline(cin,n,'.');
    s.name=new char(n.length());
    strcpy(s.name,n.c_str());
    cout<<"\n\nEnter the rollno: ";
    cin>>s.rno;

}
void create()
{
	cout<<"\n\nEnter the number of users in file1: ";
	int n;
	cin>>n;
	stu2 s;
	ofstream fout("name1.txt");
	for(int i=0;i<n;i++)
	{
		input(s);
		pack(s.name,0);
		pack(s.rno,1);
		fout<<buffer;
		flush();
	}
	flush();
	fout.close();
	fout.open("name2.txt");
	stu s1;
	cout<<"\n\nEnter the number of users in file2: ";

	cin>>n;
	for(int i=0;i<n;i++)
	{
		input(s1);
		pack(s1.name,0);
		pack(s1.rno,1);
		fout<<buffer;
		flush();

	}
	flush();
	fout.close();

}
void modify()
{
	ifstream f1("name1.txt");
	ifstream f2("name2.txt");
	ofstream fout("namemod.txt");
	string a,b;
	stu2 s;
	while(!f1.eof() && !f2.eof())
	{
		getline(f1,a,'#');
		getline(f2,b,'#');
		strcpy(buffer,a.c_str());
		cout<<buffer<<"1.";
		fout<<buffer<<"#";
		flush();
		strcpy(buffer,b.c_str());
		char name[100];
		unpack(name);
		findinti(name,s.name);
		unpack(s.rno);
		flush();
		pack(s.name,0);
		pack(s.rno,1);
		cout<<buffer<<"2";
		fout<<buffer<<"#";
	    flush();

	}
	fout.close();
}
int main()
{

	create();
	modify();
	return 0;

}
