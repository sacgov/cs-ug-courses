#include<iostream>
#include<string>
#include<cstring>
#include<fstream>

using namespace std;

struct Student{
	char rollNo[7];
	char name[16];
	char rank[5];
};

void output(Student s)
{
    cout<<s.rollNo<<" "<<s.name<<" "<<s.rank<<endl;
}

void unpack_Fix(string c, Student &s)
{
    char temp[16];
    int j=0;
    int t=0;
    for(int i=0;i<c.length();i++)
    {
        j=0;
        while(c[i]!='|'&&i<c.length())
        {
            temp[j++] = c[i++];
        }
        temp[j]='\0';

        if(t==0)
            strcpy(s.rollNo,temp);
        else if(t==1)
            strcpy(s.name,temp);
        else if(t==2)
            strcpy(s.rank,temp);
        t++;
    }
}

void unpack_Var(string& buffer, Student& s)
{
    char temp[16];
    int j=0;
    int tag=0;
    for(int i=0;i<buffer.length();i++)
    {
        j=0;
        while(buffer[i]!='|'&&i<buffer.length())
        {
            temp[j++] = buffer[i++];
        }
        temp[j]='\0';

        if(tag==0)
            strcpy(s.rollNo,temp);
        else if(tag==1)
            strcpy(s.name,temp);
        else if(tag==2)
            strcpy(s.rank,temp);
        tag++;
    }
}

void packFix(ofstream& out, Student s)
{
	out<<s.rollNo<<"|"<<s.name<<"|"<<s.rank<<"#";
}

void packVar(ofstream& out, Student s)
{
	int i=0,j=0;
	for(i=0;i<6;i++)
	{
		if(i<strlen(s.rollNo))
			out<<s.rollNo[i];
		else
			out<<" ";
	}
	out<<"|";
	for(i=0;i<15;i++)
	{
		if(i<strlen(s.name))
			out<<s.name[i];
		else
			out<<" ";
	}
	out<<"|";
	for(i=0;i<4;i++)
	{
		if(i<strlen(s.rank))
			out<<s.rank[i];
		else
			out<<" ";
	}
	out<<"#";
}

int main()
{
	Student s;
	string buffer;

	ofstream outFix;
	ofstream outVar;
	outFix.open("Fix5.txt");
	outVar.open("Var5.txt");
	char check;

	do{
		cout<<"Enter student details for fixed file: ";
		cout<<"\nEnter roll no: ";
		cin.getline(s.rollNo,7);
		cout<<"Enter name: ";
		cin.getline(s.name,16);
		cout<<"Enter rank: ";
		cin.getline(s.rank,6);

		packVar(outFix,s);

		cout<<"Do you want to do more entries: ";
		cin>>check;
		cin.ignore();
	}while(check=='y');

	do{
		cout<<"Enter student details for variable file: ";
		cout<<"\nEnter roll no: ";
		cin.getline(s.rollNo,7);
		cout<<"Enter name: ";
		cin.getline(s.name,16);
		cout<<"Enter rank: ";
		cin.getline(s.rank,6);

		packVar(outVar,s);

		cout<<"Do you want to do more entries: ";
		cin>>check;
		cin.ignore();
	}while(check=='y');

	outFix.close();
	outVar.close();

	ifstream inFix;
	ifstream inVar;

	ofstream out;
	inFix.open("Fix5.txt");
	inVar.open("Var5.txt");
	out.open("Merge5.txt");

	while(!inFix.eof())
	{
		getline(inFix,buffer,'#');
		if(buffer.length()<2)
			break;
		unpack_Fix(buffer,s);
		packFix(out,s);
	}

	while(!inVar.eof())
    {
		getline(inVar,buffer,'#');
		if(buffer.length()<2)
			break;
		unpack_Var(buffer,s);
		packFix(out,s);
	}
	inFix.close();
	inVar.close();
	out.close();
}
