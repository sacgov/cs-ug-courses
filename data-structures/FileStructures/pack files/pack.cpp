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
	for(int i=0; i<s.length(); i++)
	{
		string temp="";
		while(s[i]!='|' && s[i]!='#')
		{
			temp+=s[i];
			i++;
		}
		cout<<temp<<endl;
	}
}
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
 cout<<" unpacking"<<endl;
 fstream f1;
	f1.open("text.txt");
	for(int i=0;i<n;i++)
	unpack(f1);
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
