#include<iostream>
#include<string>
#include<fstream>
using namespace std;
struct st{
	string rlno;
	char name[50];
	string cgpa;
};
void pack(ostream& file,st stu)
{
	string buffer;
	buffer=stu.rlno+"|"+stu.name+"|"+stu.cgpa+"*";
	file<<buffer;
	return ;
}
istream & operator>>(istream& in,st &stu)
{
	int ans;
	cout<<"Enter the roll no: ";
	in>>stu.rlno;
	cin.get();
	cout<<"\nEnter the name: ";
	in.getline(stu.name,50);
	cout<<"\nEnter cgpa: ";
	cin>>stu.cgpa;
	return in;
}
string unpack(istream& file)
{
	string buffer="",temp;
	while(!file.eof())
	{
		file>>temp;
		buffer+=temp+" ";
	}
	return buffer;
}
int gen(string s)
{
	int i=0;
	int n=0;
	while(i<=s.length()-1)
	{
		int x=(int)(s[i]-48);
		n=n*10+x;
		i++;
	}
	return n;
}
int main()
{
	fstream file,file2,file3;
	int n,i,j=0;
	file.open("rollno1.txt",ios::out);
	file2.open("rollno2.txt",ios::out);
	cout<<"How many records are there in the first file?\n";
	cin>>n;
	st* stu=new st[n];
	cout<<"Enter the records\n";
	for(i=0;i<n;i++)
	{
		cin>>stu[i];
		pack(file,stu[i]);
	}
	delete []stu;
	cout<<"How many records are there in the second file?\n";
	cin>>n;
	st* stu1=new st[n];
	cout<<"Enter the records\n";
	for(i=0;i<n;i++)
	{
		cin>>stu1[i];
		pack(file2,stu1[i]);
	}
	delete []stu1;
	file.close();
	file2.close();
	file.open("rollno1.txt",ios::in);
	file2.open("rollno2.txt",ios::in);
	file3.open("merged.txt",ios::out);
	string buffer1=unpack(file);
	string buffer2=unpack(file2);
	i=0;
	int n1,n2;
		string s1="",s2="";
		while(buffer1[i]!='|')
		{
			s1+=buffer1[i];
			i++;
		}
		n1=gen(s1);
		while(buffer2[j]!='|')
		{
			s2+=buffer2[j];
			j++;
		}
		n2=gen(s2);
	while(i<buffer1.length()-1&&j<buffer2.length()-1)
	{
		while(n1<=n2)
		{
			file3<<n1;
			while(buffer1[i]!='*')
			{
				file3<<buffer1[i];
				i++;
			}
			file3<<buffer1[i];
			i++;
			s1="";
			if(i>=buffer1.length()-1)
			break;
			while(buffer1[i]!='|')
			{
				s1+=buffer1[i];
				i++;
			}
			n1=gen(s1);
			cout<<n1;
		}
		if(i<buffer1.length()-1)
		{
			while(n2<=n1)
			{
				file3<<n2;
				while(buffer2[j]!='*')
				{
					file3<<buffer2[j];
					j++;
				}
				file3<<buffer2[j];
				j++;
				s2="";
				if(j>=buffer2.length()-1)
				break;
				while(buffer2[j]!='|')
				{
					s2+=buffer2[j];
					j++;
				}
				n2=gen(s2);
			}
		}
	}
	if(i==buffer1.length()-1)
	{
		file3<<n2;
		while(j<buffer2.length())
		{
			file3<<buffer2[j];
			j++;
		}
	}
	else if(j==buffer2.length()-1)
	{
		file3<<n1;
		while(i<buffer1.length())
		{
			file3<<buffer1[i];
			i++;
		}
	}	
	
	return 0;
	
}
