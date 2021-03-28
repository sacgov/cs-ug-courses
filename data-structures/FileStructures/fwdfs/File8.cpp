#include<iostream>
#include<string>
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

void packConsole(ofstream& out, string &buffer, Employee& e)
{
	int i,j=0;
    buffer = "";

	for(i=0;i<6;i++)
	{
		if(i<e.employeeNumber.length())
		{
			buffer.append(1,e.employeeNumber[i]);
		}
		else
			buffer.append(1,' ');
	}
	buffer.append(1,'|');

	for(i=0;i<15;i++)
	{
		if(i<e.employeeName.length())
			buffer.append(1,e.employeeName[i]);
		else
            buffer.append(1,' ');
	}

	if(e.numberOfChildren>0)
	{
	    buffer.append(1,'|');

		for(i=0;i<15;i++)
		{
			if(i<e.children[0].childName.length())
				buffer.append(1,e.children[0].childName[i]);
			else
                buffer.append(1,' ');
		}
		buffer.append(1,'|');
		for(i=0;i<2;i++)
		{
			if(i<e.children[0].grade.length())
				buffer.append(1,e.children[0].grade[i]);
			else
                buffer.append(1,' ');
		}

	}
	buffer.append(1,'#');

	for(i=0;buffer[i]!='\0';i++)
		out<<buffer[i];
	return;
}

void input(ofstream& out, string& buffer)
{
	Employee e;
	cout<<"Enter Employee Number: ";
	getline(cin,e.employeeNumber,'\n');
	cout<<"Enter Employee Name: ";
	getline(cin,e.employeeName,'\n');
	cout<<"Child name: ";
	getline(cin,e.children[0].childName,'\n');
	cout<<"Child class: ";
	getline(cin,e.children[0].grade,'\n');
	e.numberOfChildren = e.children[0].childName.length()>0 ? 1 : 0;
	packConsole(out,buffer, e);
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

void update(Employee* s, Employee& e, int& n)
{
	int flag = 0;
	for(int i=0;i<n;i++)
	{
		if(s[i].employeeNumber==e.employeeNumber)
		{
			if(e.numberOfChildren>0)
			{
				s[i].numberOfChildren++;
				s[i].children[s[i].numberOfChildren-1].childName = e.children[0].childName;
				s[i].children[s[i].numberOfChildren-1].grade = e.children[0].grade;
			}
			flag = 1;
		}
	}
	if(flag == 0)
	{
		s[n].employeeNumber = e.employeeNumber;
		s[n].employeeName = e.employeeName;
		s[n].numberOfChildren = 1;
		s[n].children[0].childName = e.children[0].childName;
		s[n].children[0].grade = e.children[0].grade;
		n++;
	}
}

void clear(Employee &e)
{
	e.employeeName = "";
	e.employeeNumber = "";
	e.numberOfChildren = 0;
	e.children[0].childName = "";
	e.children[0].grade = "";
}

void packRepeating(ofstream& out, Employee& e)
{
	string buffer;
	buffer.append(e.employeeNumber);
	buffer.append(1,'|');
	buffer.append(e.employeeName);
	for(int i=0;i<e.numberOfChildren;i++)
	{
		buffer.append(1,'|');
		buffer.append(e.children[i].childName);
		buffer.append(1,'|');
		buffer.append(e.children[i].grade);
	}
	buffer.append(1,'#');
	out<<buffer;
}

int main()
{
	ofstream out;
	out.open("Packed.txt");

	string buffer;
	Employee emp[10];
	Employee temp;

	int i=0;
	int count = 0;

	char check;

	do{
		input(out, buffer);
		cout<<"Do you want to enter more(y/n): ";
		cin>>check;
		cin.ignore();
	}while(check=='y'||check=='Y');

	out<<"#";
	out.close();

	ifstream in;
	in.open("Packed.txt");

	while(!in.eof())
	{
		getline(in,buffer,'#');
		if(buffer.length()<2)
			break;
		unpack(buffer,temp);
		update(emp,temp,count);
		clear(temp);
		i++;
	}

	in.close();

	out.open("Unpacked.txt");

	for(int i=0;i<count;i++)
	{
		packRepeating(out,emp[i]);
	}

	out.close();

	return 0;
}
