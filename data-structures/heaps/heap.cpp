#include<iostream>
using namespace std;
void swap(int &a,int &b)
{
	int t=a;
	a=b;
	b=t;
}
int getmin(int &a,int &b,int i)
{
	int j;
	if(a<b)
	return(2*i);
	else
    return(2*i+1);
}
void heapify(int h[],int size,int i)
{
	int j;
	while(2*i<=size)
	{
		if(2*i<size)
		j=getmin(h[2*i],h[2*i+1],i);
		if(2*i==size)
		j=2*i;
		if(h[i]>h[j])
		{
			swap(h[i],h[j]);
			i=j;
		}
		else
		break;
	}
}
void heapsort(int h[],int size)
{
		int i=1;
		while(size>=1)
		{
			swap(h[i],h[size]);
			size--;
			heapify(h,size,i);
		}
}
int main()
{
int h[100],i,j,k,n;
	cin>>n;
	h[0]=0;
	for(i=1;i<n+1;i++)
	{
		cin>>h[i];
		j=i;
		while(j>1)
		{
			if(h[j]<h[j/2])
			{
				swap(h[j],h[j/2]);
			}
			j=j/2;
		}
	}
	for(int i=1;i<n+1;i++)
	cout<<h[i]<<" ";
	heapsort(h,n);
	return 0;
}
