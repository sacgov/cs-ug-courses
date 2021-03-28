#include<iostream>
#include<iomanip>
#include<fstream>
using namespace std;
int main()
{
	int b,d,e[80],y=0,count,count2=0,a[80],c[80],i,j,n,l,m;
	ifstream fin1,fin2;
	fin1.open("frequency.txt");
	fin2.open("numbers.txt");

	while(fin2.peek()!=EOF)
	{
		fin2>>b;
		e[y]=b;
		y++;
	}
	
	
	/*fin2.seekg(0);

	for(i=0;i<y;i++)
	{
		for(j=0;j<y-i;j++)
		{
			if (e[j]>e[j+1])
			swap(e[j],e[j+1]);
		}
	}*/
	for(i=0;i<y;i++)
	{
		count=0;
		while(fin1.peek()!=EOF)
		{
			fin1>>d;
			if(e[i]==d)
			count++;
			
		}
		
		cout<<"the count of"<<e[i]<<"is\t"<<count<<endl;
		fin1.clear();
		fin1.seekg(0);
		c[count2]=count;
		a[count2]=count;
		count2++;
		
	}
	cout<<endl<<endl<<endl<<endl;
	
	
	for(i=0;i<count2;i++)
	{
		for(j=0;j<count2-i;j++)
		{
			if (a[j]>a[j+1])
			swap(a[j],a[j+1]);
		}
	}
	

	l=a[count2-1];
	for(j=1;j<=l;j++)
	{
		for(m=0;m<count2;m++)
		{
			if(c[m]<a[count2-1])
			cout<<"   ";
			else
			cout<<"*  ";
		}
		a[count2-1]=a[count2-1]-1;
		cout<<endl;
	}
	for(i=0;i<y;i++)
	cout<<e[i]<<" " <<setw(2);
	
	return 0;
}
