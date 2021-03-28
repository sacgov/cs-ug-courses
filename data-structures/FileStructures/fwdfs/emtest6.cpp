#include<iostream>
#include<fstream>
#include<algorithm>
#include<cstring>
#include<cstdlib>
#include<cmath>
using namespace std;
int findmin(int a[],int t)
{
	int min=10000,index=-1;
	for(int i=0;i<t;i++)
	{
		if(min>a[i])
		{
			min=a[i];
			index=i;
		}
	}
	if(min==1000)
	return(1000);
	else
	return(index);
}
void clear(int v[],int k)
{
	for(int i=0;i<k;i++)
	v[i]=0;
}
int allv(int e[],int k)
{
	int r=1;
	for(int i=0;i<k;i++)
	{
		if(e[i]==0)
		r=0;
	}
	return(r);
}
int main()
{
	int count;
	char buffer[100];
	fstream fin;
	fin.open("datafile.txt",ios::in);
	while(!fin.eof())
	{
		if(fin.eof())
		break;
		fin.getline(buffer,10,'\n');
		count++;
	}
	fin.close();
	count--;
	cout<<count<<"\n";
	int i,k,j,c,s,n,m;
	n=count;
	cout<<"enter size of array\n";
	cin>>s;
	cout<<"enter order of sort\n";
	cin>>k;
	int a[s],p;
	int o[k],e[k];
	fstream f[2][k];
	string s1,s2;
	s1="a";
	s2="b";
	for(i=0;i<k;i++)
	{
		f[0][i].open((s1+".txt").c_str(),ios::out);
		f[1][i].open((s2+".txt").c_str(),ios::out);
		s1=s1+"a";
		s2=s2+"b";
	}
	fin.open("datafile.txt",ios::in);
	count=0;
	c=n%s;
	m=(n-c)/s;
	while(count<m)
	{
		for(j=0;j<s;j++)
		{
			fin.getline(buffer,10,'\n');
			a[j]=atoi(buffer);
		}
		sort(a,a+s);
		p=count%k;
		for(j=0;j<s;j++)
		{
			f[0][p]<<a[j];
			f[0][p]<<"\n";
		}
		count++;
	}
	for(j=0;j<c;j++)
	{
		fin.getline(buffer,10,'\n');
		a[j]=atoi(buffer);
	}
	sort(a,a+c);
	p=count%k;
	cout<<"p is "<<p<<"\n";
	for(j=0;j<c;j++)
	{
		cout<<"came here \n";
		f[0][p]<<a[j];
		f[0][p]<<"\n";
	}
	for(j=0;j<2;j++)
	for(i=0;i<k;i++)
	f[j][i].close();
	cout<<"enter a value\n";
	cin>>i;
	int tag=0;
	int v[k];
	while(n>s)
	{
		if((++tag)%2==1)
		{
			string s1,s2;
			s1="a";
			s2="b";
			for(i=0;i<k;i++)
			{
				f[0][i].open((s1+".txt").c_str(),ios::in);
				f[1][i].open((s2+".txt").c_str(),ios::out);
				s1=s1+"a";
				s2=s2+"b";
			}
		}
		else
		{
			string s1,s2;
			s1="a";
			s2="b";
			for(i=0;i<k;i++)
			{
				f[0][i].open((s2+".txt").c_str(),ios::in);
				f[1][i].open((s1+".txt").c_str(),ios::out);
				s1=s1+"a";
				s2=s2+"b";
			}
		}
		i=-1;
		p=-1;
		clear(v,k);
		clear(e,k);
		for(j=0;j<k;j++)
		{
			f[0][j].getline(buffer,10,'\n');
			o[j]=atoi(buffer);
			v[j]=1;
		}
		j=findmin(o,k);
		while(!allv(e,k))
		{
			if(j==1000)
			{
				cout<<"clearing v\n";
				clear(v,k);
				for(j=0;j<k;j++)
				{
					f[0][j].getline(buffer,10,'\n');
					if(!f[0][j].eof())
					{
						o[j]=atoi(buffer);
						v[j]++;
					}
					else
					{
						o[j]=1000;
						e[j]=1;
					}
				}
				for(i=0;i<k;i++)
				cout<<o[i]<<",";
				cout<<"\n";
				cout<<"here present\n";
				j=findmin(o,k);
				cout<<"now after clearing j is "<<j<<"\n";
			}
			if(!allv(e,k))
			{
				cout<<"j ="<<j<<"\n";
				cout<<"o[j] ="<<o[j]<<"\n";
				if(o[j]!=0)
				{
					i=(++p)/(s*k);
					i=i%k;
					cout<<"p ="<<p<<"\n";
					cout<<"i ="<<i<<"\n";
					f[1][i]<<o[j]<<"\n";
					cout<<"here\n";
				}
				if(!f[0][j].eof()&&v[j]<s)
				{
					cout<<"where\n";
					f[0][j].getline(buffer,10,'\n');
					if(f[0][j].eof())
					{
						e[j]=1;
					}
					v[j]++;
				}
				else
				{
					buffer[0]=0;
				}
				o[j]=atoi(buffer);
				if(o[j]==0)
				o[j]=1000;
				cout<<"next element in to array "<<o[j]<<"\n";
				for(i=0;i<k;i++)
				cout<<o[i]<<",";
				cout<<"\n";
				cout<<"e array is "<<allv(e,k)<<"\n";
				j=findmin(o,k);
				cout<<"now j will be "<<j<<"\n";
			}
		}
		for(j=0;j<2;j++)
		for(i=0;i<k;i++)
		f[j][i].close();
		s=s*k;
		cout<<"s value is "<<s<<"\n";
		cout<<"enter a value\n";
		cin>>i;
		if(i==1)
		break;
	}
}
