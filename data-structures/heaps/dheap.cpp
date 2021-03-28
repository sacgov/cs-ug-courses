#include<iostream>
using namespace std;
void swap(int &a,int &b)
{
	int t=a;
	a=b;
	b=t;
}
int min(int H[],int d,int i,int s)
{
	int m=i*d+1;
	for(int k=m+1;k<m+d-1&&k<=s;k++)
	{
		if(H[k]<H[m])
		m=k;
	}
	return(m);
}
void heapify(int H[],int s,int i,int d)
{
	int j;
	while(d*i<s)
	{
		j=min(H,d,i,s);
		if(H[i]>H[j])
		{
			swap(H[i],H[j]);
			i=j;
		}
		else
		break;
	}
}
void heapsort(int H[],int s,int d)
{
		int i=0;
		while(s>=0)
		{
			cout<<H[i]<<"\t";
			swap(H[i],H[s]);
			s=s-1;
			heapify(H,s,i,d);
		}
}
int main()
{
	int H[100];
	int i,s,j,k,d;
	j=1;
	s=-1;
	cout<<"enter the depth of the heap ";
	cin>>d;
	while(j==1)
	{
		cout<<"enter element into heap ";
		cin>>k;
		H[s+1]=k;
		s=s+1;
		i=s;
		while(i>0)
		{
			if(i%d!=0)
			{
				if(H[i]<H[i/d])
				{
					swap(H[i],H[i/d]);
					i=i/d;
				}
				else
				break;
			}
			else
			{
				if(H[i]<H[i/d-1])
				{
					swap(H[i],H[i/d-1]);
					i=i/d-1;
				}
				else
				break;
			}
		}
		cout<<"enter 1 to add elements and enter 0 to stop ";
		cin>>j;
	}
	for(i=0;i<=s;i++)
	{
		cout<<H[i]<<"\t";
	}
	cout<<"\n";
	heapsort(H,s,d);
	return 0;
}
