#include<iostream>
#include<string>
using namespace std;
int n;
void hash(string*h,string s)
{
	int k=s[0];
	k=(k-97)%(n+2);
	int c=k;
	while(1)
	{
		if(h[k]!="$")
		{
			k=(k+1)%(n+2);
			if(k==c)
			{
			cout<<"hash file full "<<endl;
			break;}
		}
		else
		{
			h[k]=s;
			break;
		}
	}
}
void search(string s,string *h)
{
	int i,flag=0;
	int k=s[0];
	k=(k-97)%(n+2);
	int c=k;
	if(h[k]==s)
	{
	cout<<"found at "<<k;
	exit(1);}
	for(int i=0;i<n+2;i++)
	{
		if(h[i]==s)
		{
			cout<<"Element found"<<endl;
			flag=1;
			break;
		}
    }
	if(flag==0)
	cout<<"Element not found"<<endl;
} 
void del(string s,string *h)
{
	for(int i=0;i<n+2;i++)
	{
		if(h[i]==s)
		{
			cout<<"Element found"<<endl;
			h[i]="$";
			break;
		}
    }
}
int main()
{
cout<<"enter the number of names "<<endl;
cin>>n;
int i;
int size=n+2;
string h[size];
for(i=0;i<size;i++)
h[i]="$";
string s;
cin.ignore();
for(i=0;i<n;i++)
{
	getline(cin,s);
	hash(h,s);
}
for(i=0;i<size;i++)
cout<<i<<" "<<h[i]<<endl;
}
