#include<iostream>
#include<string>
#include<cstring>
#include<cctype>
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

void pack(ofstream& out, Employee &a)
{
    cout<<a.employeeNumber<<"|"<<a.employeeName;
    for(int i=0;i<a.numberOfChildren;i++)
    {
        cout<<"|"<<a.children[i].childName<<"|"<<a.children[i].grade;
    }
    cout<<"#";
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

void unpack(string& buffer, Employee& e)
{
	int i=5,j;
	while(buffer[i]==' ')
		i--;
	for(j=0;j<=i;j++)
	{
		e.employeeNumber.append(1,buffer[j]);
	}
	i = 21;
	while(buffer[i]==' ')
		i--;
	for(j=7;j<=i;j++)
	{
		e.employeeName.append(1,buffer[j]);
	}
	i = 36;
	while(buffer[i]==' ')
		i--;

	for(j=23;j<=i;j++)
	{
		e.children[0].childName.append(1,buffer[j]);
	}

	j = 0;

	for(i = 39;i<41;i++)
	{
		if(buffer[i]!=' ')
		{
			e.children[0].grade.append(1,buffer[i]);
			j++;
		}
	}

	if(e.children[0].childName.length()>0)
		e.numberOfChildren = 1;
	else
		e.numberOfChildren = 0;

}

void unpackF(string c, Employee& e)
{
    string temp;
    int j=0;
    int t=0;
    e.numberOfChildren = 0;
    for(int i=0;i<c.length();i++)
    {
        temp = "";
        j=0;
        while(c[i]!='|'&&i<c.length())
        {
            temp.append(1,c[i++]);
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

int main()
{
	ofstream outF;
	outF.open("Fix4.txt");
    ofstream outV;
    outV.open("Var4.txt");

	string buffer;
	Employee a,b,e;

	int count = 0;

	char check;

    cout<<"Enter records for fixed file:\n";
	do{
        cout<<"Enter Employee Number: ";
        getline(cin,e.employeeNumber);
        cout<<"Enter Employee Name: ";
        getline(cin,e.employeeName);
        cout<<"Child name: ";
        getline(cin,e.children[0].childName);

        cout<<"Child class: ";
        getline(cin,e.children[0].grade);
        e.numberOfChildren = 1;
        pack(outF,e);
		cout<<"Do you want to enter more(y/n): ";
		cin>>check;
		cin.ignore();
	}while(check=='y'||check=='Y');
	outF<<"#";

    cout<<"Enter records for variable file:\n";
	do{
		input(outV, e);
		cout<<"Do you want to enter more(y/n): ";
		cin>>check;
		cin.ignore();
	}while(check=='y'||check=='Y');
    outV<<"#";

	outF.close();
	outV.close();

	ifstream inF;
	inF.open("Fix4.txt");
    ifstream inV;
    inV.open("Var4.txt");
    ofstream out;
    out.open("Sort4.txt");

    int flag1=1,flag2=1;
    getline(inF,buffer,'#');
    unpackF(buffer,a);

    getline(inV,buffer,'#');
    unpackF(buffer,b);


    cout<<a.employeeNumber<<"  "<<b.employeeNumber<<endl;

	while(flag1&&flag2)
	{
	    cout<<a.employeeNumber<<"  "<<b.employeeNumber<<endl;
        if((a.employeeNumber)<(b.employeeNumber))
        {
            pack(out,a);
            getline(inF,buffer,'#');
            if(buffer.length()<3)
                flag1 = 0;
            unpackF(buffer,a);
        }
        else
        {
            pack(out,b);
            getline(inV,buffer,'#');
            cout<<buffer;
            if(buffer.length()<3)
                flag2 = 0;
            unpackF(buffer,b);
        }

	}

	if(!flag1)
    {
        while(flag2)
        {
            pack(out,b);
            getline(inV,buffer,'#');
            if(buffer.length()<3)
                flag2 = 0;
            unpackF(buffer,b);
        }
    }

	if(!flag2)
    {
        while(flag1)
        {
            pack(out,a);
            getline(inF,buffer,'#');
            if(buffer.length()<3)
                flag1 = 0;
            unpackF(buffer,a);
        }
    }

    return 0;

}
