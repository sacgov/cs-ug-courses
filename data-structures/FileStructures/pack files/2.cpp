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
   public: char reg[15],n[2],std[3],age[5],buffer[100],d[2],name[80];
   	char *name1;


void writevariableRecord()
{
	 char std1[80],age1[80];
	  name1=new char();
  ofstream fout("a3.txt",ios::app);
  fflush(stdin);
  
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
  fout<<buffer<<endl;	 
  fout.close();
}

void displayFile()
{
   ifstream fin("a3.txt");
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
int main()
{
   employee e[100];int n,m;
   cout<<"enter the no. of variable records";
   
   cin>>n;

   
   for(int i=0;i<n;i++)
   {
      cout<<"\n write to file\n"
	  <<"\n";
      e[i].writevariableRecord();
   }  
	 for(int i=0;i<n;i++)
	 e[i].displayFile();
	
	 return 0;
}

