#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<fstream>
#include<conio.h>
#include<string.h>
#include<iomanip>
using namespace std;
class employee
{
   public: char reg[15],n[2],std[3],age[5],*buffer,d[2],name[80];
   	char *name1;


void writevariableRecord()
{
	 char std1[80],age1[80];
	  name1=new char();
	  buffer=new char();
  ofstream fout("a2.txt",ios::app);
  fflush(stdin);  //Open file in append mode
  
  cout<<"\n Enter the reg no = "; cin>>reg;
  fflush(stdin);
  cout<<"\n Enter the employee name = "; cin>>name1;
  fflush(stdin);
  
  cout<<"\n Enter the age = "; cin>>age;
  fflush(stdin);
  cout<<"\n Enter the no. of children = "; cin>>n;
  fflush(stdin);
  strcpy(d,n);
  int result=atoi(n);
  strcpy(buffer,reg);   strcat(buffer,"|");
  strcat(buffer,name1);   strcat(buffer,"|");
  strcat(buffer,age);    strcat(buffer,"|");
  strcat(buffer,d);    strcat(buffer,"|");

  for(int i=0;i<result;i++)
  {
  	cout<<"\n Enter the class of child  "<<i+1<<" : ";
  	cin>>std;
  	strcat(buffer,std);strcat(buffer,"|");
  	cout<<"\n Enter the age of child "<<i+1<<" : ";
  	cin>>age;
  	strcat(buffer,age);strcat(buffer,"|");
  	
  }
  fflush(stdin);
  fout<<buffer<<endl;	 //writing the packed information to buffer
  fout.close();
}

void writefixedrecord()
{
	 int d;
	
  ofstream fout("a2.txt",ios::app);
  fflush(stdin);  //Open file in append mode
  
  cout<<"\n Enter the reg no = "; cin>>reg;
  fflush(stdin);
  cout<<"\n Enter the employee name = "; cin>>name;
  fflush(stdin);
  
  cout<<"\n Enter the age = "; cin>>age;
  fflush(stdin);
  cout<<"\n Enter the no. of children = "; cin>>n;
  fflush(stdin);

 
 
  strcpy(buffer,reg);   strcat(buffer,"|");
  strcat(buffer,name);   strcat(buffer,"|");
  strcat(buffer,age);    strcat(buffer,"|");
  strcat(buffer,n); strcat(buffer,"|");
  fout<<buffer<<endl;	 //writing the packed information to buffer
  fout.close();
}

void displayFile()
{
   ifstream fin("a2.txt");
   while(!fin.eof())
  {
  	cout<<endl<<endl;
  	int m=1;
   	 fflush(stdin);
     fin.getline(buffer,80);
     char *pch;
     pch = strtok(buffer,"|");
  	 while (pch != NULL)
  	 {
  	 	
  		print(m);
  		cout<<pch<<endl;
     pch = strtok (NULL, "|");
     m++;
 	 }
     fflush(stdin);
    
  }
  fin.close();
}


			void print(int m)
			{			
  			if(m==1)
			cout<<"Name            :";
			
  			if(m==2)
			cout<<"Registration no.:";
			
  			if(m==3)
			cout<<"Age             :";
			
			if(m==4)
			cout<<"No. of children.:";
			if(m>4)
			{
				if(m%2==0)
				cout<<"the age of child  "<<m-4<<" is :  ";
				else
				cout<<"the class of child  "<<m-4<<" is :  ";
				
			}
  		
}


};

void sortrecords(int m)
{
	
    ifstream fin1("a2.txt");
	ofstream fout2("d2.txt");
	char *s[200];
	
	char temp[100];
	int j=0;
	cout<<"*";
	while(fin1.peek()!=EOF) 
	{
		s[j]=new char[100];
		fin1.getline(s[j],100);
		fflush(stdin);
		j++;
	}
	

	for(int i=0;i<j;i++)
	{
	for(int z=0;z<j-i-1;z++)	
	{
		if (strcmp(s[z],s[z+1])>0)
		{
			strcpy(temp,s[z]);
			strcpy(s[z],s[z+1]);
			strcpy(s[z+1],temp);
		}
	}
	}
	for(int i=0;i<j;i++)
	fout2<<s[i]<<endl;
}

int main()
{
   employee e[100];int n,m;
   cout<<"enter the no. of variable records";
   
   cin>>n;
   fstream fin;
   fstream fout;
   
   for(int i=0;i<n;i++)
   {
      cout<<"\n write to file\n"
	  <<"\n";
      e[i].writevariableRecord();
    
	}
	cout<<"enter the no. of fixed records";
	cin>>m;
	for(int i=0;i<m;i++)
	  {
      cout<<"\n write to file\n"
	  <<"\n";
      e[i].writefixedrecord();
      } 
	  int w;
	   w=m+n;  
	 for(int i=0;i<w;i++)
	 e[i].displayFile();
		
	sortrecords(w);	
	 return 0;
}


	  
