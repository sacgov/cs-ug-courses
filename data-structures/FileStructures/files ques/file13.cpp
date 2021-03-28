#include<iostream>
#include<fstream>
using namespace std;
struct stu{
	string rlno;
	char* name=new char[50];
	string state;
};
void pack(ostream& file,stu st)
{
	string buffer="";
	buffer=st.state+"|"+st.rlno+"|"+st.name+"*";
	file<<buffer;
	return ;
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
istream & operator>>(istream& in,stu& st)
{
	cout<<"Enter the roll no: ";
	in>>st.rlno;
	cin.get();
	cout<<"\nEnter the name: ";
	in.getline(st.name,50);
	cout<<"\nEnter the state: ";
	in>>st.state;
	return in;
}
int main()
{
	fstream file,file2;
	file.open("StudentState.txt",ios::out);
	int n,i;
	cout<<"how many records are there?\n";
	cin>>n;
	stu* st=new stu[n];
	for(i=0;i<n;i++)
	{
		cout<<"Enter the deatils of student no. "<<i+1<<endl;
		cin>>st[i];
		pack(file,st[i]);
	}
	file.close();
	file.open("StudentState.txt",ios::in);
	file2.open("RollState.txt",ios::out);
	string buffer=unpack(file);
	string a[50],b[50];
	int p=0;
	string temp;
	for(i=0;i<buffer.length()-1;i++)
	{
		temp="";
		while(buffer[i]!='|')
		{
			temp+=buffer[i];
			i++;
		}
		a[p]=temp;
		i++;
		temp="";
		while(buffer[i]!='|')
		{
			temp+=buffer[i];
			i++;
	
		}
		b[p]=temp;
		i++;
		while(buffer[i]!='*')
		{
			i++;
		}
		p++;
	}
	file.close();
	int q=0,r;
	buffer="";
	for(i=0;i<p;i++)
	{
		temp=a[i];
		if(a[i]!="")
		{
			buffer=a[i]+" - "+b[i];
			for(r=i+1;r<p;r++ )
			{
				if(a[i]==a[r])
				{
					a[r]="";
					buffer+=" "+b[r];
				
				}
			}
			file2<<buffer<<endl;
		}
	}
	file2.close();
	return 0;
	
	
}
