#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<fstream>
#include<conio.h>
#include<string.h>
#include<iomanip>
using namespace std;
class student
{
   public: 
   char roll[15],age[5],branch[15];
   	char *name,*buffer;


void tofile()
{
	 int d;
  name=new char();
  buffer=new char();
  ofstream fout("student.txt",ios::app);
  fflush(stdin); 
  cout<<"\n Enter the student name = "; cin>>name;
  fflush(stdin);
  cout<<"\n Enter the roll no = "; cin>>roll;
  fflush(stdin);
  cout<<"\n Enter the age = "; cin>>age;
  fflush(stdin);
  cout<<"\n Enter the branch = "; cin>>branch;
  fflush(stdin);

 
 
  strcpy(buffer,name);   strcat(buffer,"|");
  strcat(buffer, roll);   strcat(buffer,"|");
  strcat(buffer, age);    strcat(buffer,"|");
  strcat(buffer, branch); strcat(buffer,"\n");
  fout<<buffer;
  fout.close();

}

void print()
{
   
  	ifstream fin("student.txt");
	
  
  while(!fin.eof())
  {
  	cout<<endl;
  	int i=1;
   	 fflush(stdin);
     fin.getline(buffer,80);
     char * h;
     h = strtok (buffer,"|");
  	 while (h != NULL)
  	 {
  	 	
  		switch (i)
  		{
  			case 1:cout<<"Name\t:\t";break;
  			case 2:cout<<"Roll\t:\t";break;
  			case 3:cout<<"Age\t:\t";break;
  			case 4:cout<<"Course\t:\t";break;
  			case 5:cout<<"Branch\t:\t";break;
  		}
     cout<<h<<endl;
     h = strtok (NULL, "|");
     i++;
 	 }
     fflush(stdin);
    
  }
  fin.close();
  getch();
}
};

int main()
{
   student s[100];int n;
   cout<<"enter the no. of records";
   cin>>n;
   fstream fin;
   fstream fout;
   
   for(int i=0;i<n;i++)
   {
      cout<<"\n write to file\n"
	  <<"\n";
      s[i].tofile();
    
	}     
	 for(int i=0;i<n;i++)
	 s[i].print();
	 return 0;
}
	  
      
   

