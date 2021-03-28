#include<iostream>
#include<string>
#include<fstream>

using namespace std;
int i;
string itos(int n);
struct student
{
	int rno;
	string name;
	int cgpa;
};
void pack(ofstream& f,student& stu);

string itos(int n)
{
	string z;
	while(n>0)
	{
		z=(char(n%10+48))+z;
		n/=10;
	}
	return z;
}
void unpack(fstream & f)
{
	string s;
	getline(f,s);
	string q[10];
	q[0][0]=s[0];
	int k=0,t=0;
	for(int i=0; i<s.length(); i++)
	{    
		if(s[i]!='#'&&s[i]!='|')
		q[k]+=s[i];
		if(s[i]=='#')
		k++;
		
	}
	for(int i=0;i<k;i++)
{   cout<<i+1<<" ";
int cou=0;
	for(int j=0;j<k;j++)
	{
		if(i!=j)
		{
		if(q[i]==q[j])
			{cou++;
			cout<<j+1<<",";}	
		}	
	}
	if(cou==0)
		cout<<" no duplicates"<<endl;
		cout<<endl;}
}
void unpack1(fstream & f)
{
	string s;
	getline(f,s);
	cout<<s;
	string q[100];
	int k=0,t=0;
	for(int i=0; i<s.length(); i++)
	{  	if(s[i]!='#'&&s[i]!='|')
		q[k]+=s[i];
		if(s[i]=='#')
		k++;}
		for(int i=0;i<k;i++)
		cout<<q[i]<<endl;
	static int dup[100];
	for(int i=0;i<k;i++)
   { int cou=0;
   if(dup[i]==0)
	{cout<<"|"<<i+1<<",";
	for(int j=0;j<k;j++)
	{ if(i!=j)
		{if(q[i]==q[j])
			{cou++;
			cout<<j+1<<",";
			dup[j]=1; }}	
	}
	if(cou==0)
		cout<<" no duplicates";
}}}
int main()
{

    student stu;
    ofstream f;
    f.open("text.txt");
    cout<<"enter number of students"<<endl;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    pack(f,stu);
    cout<<"packed"<<endl;
 f.close();
 cout<<"unpacking"<<endl;
 fstream f1;
	f1.open("text.txt");
	for(int i=0;i<n;i++)
	unpack1(f1);
	f1.close();
	
}
void pack(ofstream& f,student& stu)
{
	string buffer;

		string tem;
		cout<<"enter rno;";
		cin>>stu.rno;
		int w=stu.rno;
		tem=itos(w);
		buffer=buffer+tem+"|";
		cout<<"name";
		cin.ignore();
		getline(cin,stu.name);
		buffer=buffer+stu.name+"|";
		cout<<"gpa";
		cin>>stu.cgpa;
		tem=(itos(stu.cgpa));
		buffer=buffer+tem+"#";
	f<<buffer;
}
