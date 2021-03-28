#include<iostream>
using namespace std;
void print (int a[],int s)
{
	for(int i=0;i<s;i++)
	cout<<a[i]<<" ";
	cout<<endl;	
}
void shellsort(int a[10],int n)
{
	int gap=n/2;
	do
	{
		int swap;
		do
		{
			swap=0;
			for(int i=0;i<n-gap;i++)
				if(a[i]>a[i+gap])
				{
					int t=a[i];
					a[i]=a[i+gap];
					a[i+gap]=t;
					swap=1;
				}
		}
		while(swap);
		gap=gap/2;
	}
	while(gap>0);
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
	shellsort(a,x);
	cout<<"after sorting "<<endl;
	print(a,x);
}
