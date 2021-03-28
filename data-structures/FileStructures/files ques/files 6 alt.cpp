#include<iostream>
#include<cstring>
#include<cstdlib>
#include<fstream>
using namespace std;
char buffer[1000];


struct student
{
	char rno[10];
	char name[30];
	char cellno[11];
	char roomno[7];

};
void pack(char *buffer,char *x)
{//stores every record and each feild to char arrey buffer
	strcat(buffer,x);
	strcat(buffer,"|");
}

int main()
{
	int n,a;
	student s;

	char ch;
	cout<<" how many students' details do you want to save ? "<<endl;
	cin>>n;
	cout<<"enter student details as roll no,name"<<endl;
	cin.ignore();
	for(int i=0;i<n;i++)
	
	{ 
	  strcat(buffer,"#");
	  cout<<"enter roll no:"<<endl;
		cin.getline(s.rno,10);
		pack(buffer,s.rno);
		cout<<"enter name : "<<endl;
		cin.getline(s.name,30);
		pack(buffer,s.name);
		cout<<"do you want to give your mobile number or room no? enter 1 for m.no and 2 for r.no ::"<<endl;
	    cin>>a;
		cin.ignore();
		if(a==1)
		{   
			cout<<"enter your m.no(10 digits):(start with 0)"<<endl;
			
			cin.getline(s.cellno,10);
			pack(buffer,s.cellno);
		}
		else if(a==2)
		{ 
		cout<<"enter your room no.(ex 7-1-10) :(start with 0)"<<endl;
		cin.ignore();
		cin.getline(s.roomno,6);
		pack(buffer,s.roomno);
		}
	}
	ofstream f1;
	f1.open("detail.txt");
	f1<<buffer;
	f1.close();
	return 0;
}

