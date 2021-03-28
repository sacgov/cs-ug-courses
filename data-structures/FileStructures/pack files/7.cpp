#include<iostream>
#include<fstream>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
using namespace std;
class employee
{
   public: char Name[30];
           char Age[4];
		   char salary[8];
		    char buffer[150];
		    char a[3];
		   	char name[18];
		   	char age[3];
		   	void pack();
		   	int r;
		   	void unpack();		
};


void employee::pack()
{ 
   ofstream fout("record.txt");
   cout<<"Enter name :";
   cin.getline(Name,15);
   	fflush(stdin);
   cout<<"\nEnter age :";
   cin>>Age;
   	fflush(stdin);
   cout<<"\nEnter salary :";
   cin>>salary;
   fflush(stdin);
   cout<<"enter no. of children ";
   cin>>a;
   	fflush(stdin);
  	strcpy(buffer,Name);strcat(buffer,"|");
  	strcat(buffer,salary); strcat(buffer,"|");
  	strcat(buffer,Age); strcat(buffer,"|");
  	strcat(buffer,a);strcat(buffer,"*");
  	   
  	   int k=strlen(buffer);
  	   r=atoi(a);int l,e;char name1[80];
  	for(int g=1;g<=r;g++)
  	{
        cout<<"Enter name of child"<<g<<endl;
		cin>>name;
		fflush(stdin);
		e=strlen(name);
		l=e;
		for(int i=l;i<18;i++)
		{
		name[i]=' ';
		fflush(stdin); 
		}
		strcpy(name1,name);
		strcat(buffer,name1);fflush(stdin); strcat(buffer,"|");
		fflush(stdin);
		cout<<"Enter age of child"<<g<<endl;
		fflush(stdin);
		cin>>age;	fflush(stdin); 
		int u=strlen(age); 	   	
  	   		for(int j=u;j<3;j++)
  	   	{
  	   		if(j==2)
  	   		age[j]='/0';
  	   		else
  	   		fflush(stdin); 
  	   		age[j]='#';
  	   		fflush(stdin); 
  	   	}
  	   	if(g==r)
  	   {
  	   	fflush(stdin);
  	   strcat(buffer,age);fflush(stdin); strcat(buffer,"^");
  	   fflush(stdin);
	   }
  	   	fflush(stdin);
  	    if(g!=r)
  	   {
  	   	fflush(stdin);
  	         strcat(buffer,age);fflush(stdin); strcat(buffer,"^");
  	         fflush(stdin);
  	   }
  	   fflush(stdin);		
	}
fout<<buffer<<endl;
fout.close();
}
		void employee::unpack()
		{
			ifstream fin;
			ofstream fout1("record3.txt",ios::app);
			fin.open("record.txt");
			
			for(int i=0;i<r;i++)
			{
				fin.getline(buffer,150,'*');
				fout1<<buffer;
				int q=strlen(buffer);
				
				fin.seekg(q+25*i);
				fin.getline(buffer,24,'^');
				fout1<<buffer;
				cout<<buffer<<endl;
				
				fin.clear();
				fin.seekg(0);
				fout1<<endl;
				
			}
		}
int main()

{
	cout<<"Enter no of records";
	int n;
	cin>>n;
	employee s[n];
	for(int i=0;i<n;i++)
	{
		cout<<"enter details for employee "<<i+1<<endl;	
		fflush(stdin);
		cout<<endl;
		s[i].pack();
		s[i].unpack();
	}
}
