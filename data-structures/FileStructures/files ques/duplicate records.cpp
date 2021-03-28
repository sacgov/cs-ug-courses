#include<iostream>
#include<fstream>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
using namespace std;
class employee
{
   public: char Name[15];
           char Age[4];
		   char salary[8];
		    char buffer[150];
		    char a[3];
		   	char name[15];
		   	char age[3];
		   	void pack();
		   	int r;
		   	void unpack();
	
	
	
};

void employee::pack()
{ 
   ofstream fout("record5.txt",ios::app);
   cout<<"Enter name :";
   cin.getline(Name,15);
   	fflush(stdin);
   cout<<"\nEnter age :";
   cin>>Age;
   	fflush(stdin);
   cout<<"\nEnter salary :";
   cin>>salary;
   fflush(stdin);
   cout<<"ENTER no. of children ";
   cin>>a;
   	fflush(stdin);
  	strcpy(buffer,Name);strcat(buffer,"|");
  	strcat(buffer,salary); strcat(buffer,"|");
  	strcat(buffer,Age); strcat(buffer,"|");
  	strcat(buffer,a);strcat(buffer,"*");
  	   
  	   //int k=strlen(buffer);
  	   r=atoi(a);
  	   cout<<r;
  	   char age1[4];
  	for(int i=1;i<=r;i++)
  	{
  	   		fflush(stdin); 
        cout<<"Enter name of child"<<i<<endl;
		cin>>name;
		fflush(stdin);	
		int e=strlen(name);
		for(int i=e;i<15;i++)
		{
		/*if(i==14)
		name[i]=='\0';
		else*/
		name[i]=' ';
		fflush(stdin);
		}
		
		strcat(buffer,name);strcat(buffer,"|");
			fflush(stdin);
		cout<<"Enter age of child"<<i<<endl;fflush(stdin); 
		cin>>age;	fflush(stdin); 
		int u=strlen(age); 	   	
  	   		for(int j=u;j<3;j++)
  	   	{
  	   		/*if(j==2)
  	   		age[j]='/0';
  	   		else
  	   		*/
  	   		age[j]=' ';
  	   		fflush(stdin);
  	   	}
  	   	strcpy(age1,age);
  	   	if(i==r)
  	   {
  	   	fflush(stdin);
  	   strcat(buffer,age1); strcat(buffer,"#");
  	   fflush(stdin);
	   }
  	   	
  	    else
  	   {
  	         strcat(buffer,age1); strcat(buffer,"|");
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
			ofstream fout1("record6.txt",ios::app);
			fin.open("record5.txt");
			
			for(int i=0;i<r;i++)
			{
				fin.getline(buffer,150,'*');
				fout1<<buffer;
				int q=strlen(buffer);

				fin.seekg(q+21*i);
				fin.getline(buffer,21);
				fout1<<buffer;
		    	fin.clear();
			    fin.seekg(0);
				fout1<<endl;
			}
		}
			
		
int main()

{
	cout<<"Enter no. of records :";
	int n;
	cin>>n;
	employee s[n];
	for(int i=0;i<n;i++)
	{
		cout<<"ENTER details for employee "<<i+1<<endl;
		
		fflush(stdin);
		cout<<endl;
		s[i].pack();
		s[i].unpack();
	}
	return 0;	
	
}
