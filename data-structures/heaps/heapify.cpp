#include<iostream>
using namespace std;
void swap(int&a,int&b)
{
	int t=a;
	a=b;
	b=t;
}
int getimp(int h[],int &size)
{
	int i=0;
	swap(h[1],h[size-1]);
	
	int j;
	j=1;
	while(2*j<size-1)
	{
		if(h[1]<h[2*j]&&h[2*j]<h[2*j])
		swap(h[1],h[2*j]);
		if(h[1]<h[2*j+1]&&h[2*j]<h[2*j+1])
		swap(h[1],h[2*j+1]);
		j++;
	}
	size--;
	return h[1];
	
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
	cout<<getimp(h,n);
    
}
