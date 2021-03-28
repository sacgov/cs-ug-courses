#include<iostream>
#include<cstring>
#include<fstream>
#include<stdio.h>
using namespace std;

char buffer[100];

union Contact
{
	char cellno[11];
	char room[6];
};
struct Student
{
	char name[20];
	char cgpa[5];
	char tag[2];
	Contact *c;
};

void pack(char * buffer, char* field,int tag)
{
    strcat(buffer,field);
    if(tag==0)
    {
        strcat(buffer,"|");
    }
    else
    {
        strcat(buffer,"#");
    }

}
istream& operator >> (istream& cin,Student &s)
{
	cout<<"\nEnter name of Student: ";
	cin.getline(s.name,20);
	pack(buffer,s.name,0);
	cout<<"Enter cgpa of Student: ";
    cin.getline(s.cgpa,5);
    pack(buffer,s.cgpa,0);
	cout<<"Enter\n1.Cell no\n2.Room no\n";
    cin.getline(s.tag,2);
    pack(buffer,s.tag,0);
	if(strcmp(s.tag,"1")==0)
	{
		cout<<"Enter cell no of Student: ";
		s.c=new Contact;
        cin.getline(s.c->cellno,11);
        pack(buffer,s.c->cellno,1);
	}
	else
	{
		cout<<"Enter room of Student: ";
		s.c=new Contact;
        cin.getline(s.c->room,6);
        pack(buffer,s.c->room,1);
	}
	return cin;
}

void output(ofstream& out, Student s)
{
    out<<s.name<<"|"<<s.cgpa<<"|";
    if(strcmp(s.tag,"1")==0)
    {
        out<<s.c->cellno<<"#";
    }
    else
    {
        out<<s.c->room<<"#";
    }
}

void unpack(char *c, Student &s)
{
    char temp[16];
    int j=0;
    int t=0;
    for(int i=0;c[i]!='\0';i++)
    {
        j=0;
        while((c[i]!='|')&&c[i]!='\0')
        {
            temp[j++] = c[i++];
        }
        temp[j]='\0';

        if(t==0)
            strcpy(s.name,temp);
        else if(t==1)
            strcpy(s.cgpa,temp);
        else if(t==2)
            strcpy(s.tag,temp);
        else if(t==3)
        {
            if(strcmp(s.tag,"1")==0)
            {
                strcpy(s.c->cellno,temp);
            }
            else
            {
                strcpy(s.c->room,temp);
            }
        }
        t++;
    }
}

int main()
{
	Student s;
    int i=0;

    ofstream out;
	out.open("records.txt");

    char check;
    do{
        strcpy(buffer,"");
        cin>>s;
        out<<buffer;
        cout<<"Do you want to enter more(y/n): ";
        cin>>check;
        cin.ignore();
    }while(check=='y'||check=='Y');

    out.close();

    ifstream in;
    in.open("records.txt");

    ofstream out2;
    out2.open("Cell.txt");
    ofstream out3;
    out3.open("Room.txt");


    while(!in.eof())
    {
        strcpy(buffer,"");
        in.getline(buffer,100,'#');
        unpack(buffer,s);
        cout<<buffer;
        if(strlen(buffer)<=2)
            break;
        if(strcmp(s.tag,"1")==0)
        {
            output(out2,s);
        }
        else
        {
            cout<<"IN";
            output(out3,s);
        }
    }
	return 0;

}


