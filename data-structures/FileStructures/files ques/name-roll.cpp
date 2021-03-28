#include<iostream>
#include<string>
#include<fstream>
using namespace std;
union uni
{
	char mno[50];
	char rno[25];
};
struct st{
	string rlno;
	char* name=new char[50];
	int tag;
	uni add;
};
void pack(ostream& file,st stu)
{
	string buffer="";
	if(stu.tag==1)
	buffer+="1";
	else
	buffer+="2";
	buffer+=stu.rlno+"|"+stu.name+"|";
	if(stu.tag==1)
	buffer+=stu.add.mno;
	else
	buffer+=stu.add.rno;
	buffer+="*";
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
	cout<<"Will you provide mobile no or room no?Press 1 for mobile no. and 2 for room no.\n";
	in>>ans;
	if(ans==1)
	{
		cout<<"\nEnter mobile no: ";
		in>>stu.add.mno;
		stu.tag=1;
	}
	else if(ans==2)
	{
		cout<<"\nEnter room no: ";
		in>>stu.add.rno;
		stu.tag=2;
	}
	else
	cout<<"Invalid entry.\n";
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
int main()
{
	fstream file,file2,file3;
	int n,i;
	file.open("Stu.txt",ios::out);
	cout<<"Enter the file\n";
	cout<<"how many number of records are there?\n";
	cin>>n;
	st* stu=new st[n];
	for(i=0;i<n;i++)
	{
		cout<<"Enter the details of student no. "<<i+1<<endl;
		cin>>stu[i];
		pack(file,stu[i]);
	}
	file.close();
	file.open("Stu.txt",ios::in);
	file3.open("rmno.txt",ios::out);
	file2.open("mobno.txt",ios::out);
	string s=unpack(file);
	//cout<<s;
	for(i=0;i<s.length()-1;i++)
	{
		if(s[i]=='1')
		{
			i++;
			while(s[i]!='*')
			{
				file2<<s[i];
				i++;
			}
			file2<<s[i];
		}
		else
		{
			i++;
			while(s[i]!='*')
			{
				file3<<s[i];
				i++;
			}
			file3<<s[i];
		}
		
	}
	return 0;
	
}
