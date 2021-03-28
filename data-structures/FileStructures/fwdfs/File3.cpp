#include<iostream>
#include<string>
#include<cstring>
#include<fstream>
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

void output(ofstream& out,Student s)
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

    ofstream out1;
    ofstream out2;
	out1.open("records1.txt");
	out2.open("records2.txt");

    char check;
    cout<<"\nEnter records for File 1: \n";
    do{
        strcpy(buffer,"");
        cin>>s;
        out1<<buffer;
        cout<<"Do you want to enter more(y/n): ";
        cin>>check;
        cin.ignore();
    }while(check=='y'||check=='Y');

    cout<<"\nEnter records for File 2: \n";
    do{
        strcpy(buffer,"");
        cin>>s;
        out2<<buffer;
        cout<<"Do you want to enter more(y/n): ";
        cin>>check;
        cin.ignore();
    }while(check=='y'||check=='Y');


    out1.close();
    out2.close();

    ofstream out3;
    out3.open("Merge3.txt");

    ifstream in1;
    in1.open("records1.txt");
    ifstream in2;
    in2.open("records2.txt");

    while((!in1.eof())&&(!in2.eof()))
    {
        if(!in1.eof())
        {
            strcpy(buffer,"");
            in1.getline(buffer,100,'#');
            unpack(buffer,s);
            if(strlen(buffer)<=2)
                continue;

            output(out3,s);
        }
        if(!in2.eof())
        {
            strcpy(buffer,"");
            in2.getline(buffer,100,'#');
            unpack(buffer,s);
            if(strlen(buffer)<=2)
                continue;

            output(out3,s);

        }

    }


    in1.close();
    in2.close();

    return 0;

}
