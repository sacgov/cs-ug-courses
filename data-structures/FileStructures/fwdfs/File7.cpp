#include<iostream>
#include<string>
#include<cstring>
#include<fstream>

using namespace std;

struct Child{
	string childName;
	string grade;
};

struct Employee{
	string employeeNumber;
	string employeeName;
	int numberOfChildren;
	Child children[10];
};

void pack(ofstream& out, Employee e)
{
    out<<e.employeeNumber<<"|"<<e.employeeName;
    for(int i=0;i<e.numberOfChildren;i++)
    {
        out<<"|"<<e.children[i].childName<<"|"<<e.children[i].grade;
    }
    out<<"#";
}

void input(ofstream& out,Employee& e)
{
	cout<<"Enter Employee Number: ";
	getline(cin,e.employeeNumber,'\n');
	cout<<"Enter Employee Name: ";
	getline(cin,e.employeeName,'\n');
	int t;
	cout<<"Enter number of children: ";
	cin>>t;
	cin.ignore();
	e.numberOfChildren = 0;
	for(int i=0;i<t;i++)
    {
        cout<<"Child name: ";
        getline(cin,e.children[i].childName,'\n');
        cout<<"Child class: ";
        getline(cin,e.children[i].grade,'\n');
        e.numberOfChildren++;
    }

    pack(out,e);

	return;
}

void unpack(string &buffer, Employee &e)
{
    string temp;
    int j=0;
    int t=0;
    e.numberOfChildren = 0;
    for(int i=0;i<buffer.length();i++)
    {
        temp = "";
        j=0;
        while(buffer[i]!='|'&&i<buffer.length())
        {
            temp.append(1,buffer[i++]);
        }

        if(t==0)
            e.employeeNumber = temp;
        else if(t==1)
            e.employeeName = temp;
        else if(t==2)
            e.children[e.numberOfChildren].childName = temp;
        else if(t==3)
        {
            e.children[e.numberOfChildren].grade = temp;
            e.numberOfChildren++;
            t = 1;
        }

        t++;
    }
}

void packF(ofstream& out, Employee &e)
{
    if(e.numberOfChildren==0)
        out<<e.employeeNumber<<"|"<<e.employeeName<<"#";
    for(int i=0;i<e.numberOfChildren;i++)
    {
        out<<e.employeeNumber<<"|"<<e.employeeName<<"|"<<e.children[i].childName<<"|"<<e.children[i].grade<<"#";
    }

}

int main()
{
    ofstream outV;
    outV.open("Var7.txt");

	string buffer;
	Employee a,b,e;

	int count = 0;

	char check;

    cout<<"Enter records for variable file:\n";
	do{
		input(outV, e);
		cout<<"Do you want to enter more(y/n): ";
		cin>>check;
		cin.ignore();
	}while(check=='y'||check=='Y');

    outV<<"#";
    outV.close();

    ifstream in;
    in.open("Var7.txt");
    ofstream outF;
    outF.open("Fix7.txt");

    while(!in.eof())
    {

        getline(in,buffer,'#');
        if(buffer.length()<3)
            return 0;
        unpack(buffer,e);
        packF(outF,e);

    }

}
