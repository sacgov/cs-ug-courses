#include<iostream>
using namespace std;
void print (int a[],int s)
{
	cout<<endl;
	for(int i=0;i<s;i++)
	cout<<a[i]<<" ";
	cout<<endl;	
}
void pushback(int a[],int s,int k,int n)
{
	for(int i=0;i<s;i++)
	{
		if(a[i]>k)
		{
			for(int j=s;j>i;j--)
			a[j]=a[j-1];
			a[i]=k;
			print(a,n+1);
			break;
		}
	}
}
void insort(int a[],int n)
{
	for(int i=1;i<=n;i++)
	pushback(a,i,a[i],n);
}
int main()
{
	int a[500];
	int flag=1,x=0;
	while(flag!=-1)
	{
		cout<<"enter element into the array"<<endl;
		cin>>flag;
		if(flag!=-1)
		a[x++]=flag;
	}
	cout<<"size of array is "<<x<<endl;
	print(a,x);
	int q=x-1;
	insort(a,q);
	cout<<"after sorting "<<endl;
	print(a,x);
}