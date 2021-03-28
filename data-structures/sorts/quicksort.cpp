#include<iostream>
using namespace std;
int partition(int a[],int low,int high)
{
	if(low<high)
	{
		int p=a[low];
		int l=low+1;
		int h=high;
		while(l<h)
		{
			while(a[l]<p)
			l++;
			while(a[h]>p)
			h--;
			if(l<h)
			{
				swap(a[l],a[h]);
				cout<<"L="<<l<<" h="<<h<<endl;
			}
			cout<<"L="<<l<<" h="<<h<<endl;
		}
		swap(a[low],a[h]);
		cout<<"low="<<low<<" h="<<h<<endl; 
		return h;
	}
}
void print (int a[],int s)
{
	cout<<endl;
	for(int i=0;i<s;i++)
	cout<<a[i]<<" ";
	cout<<endl;	
}
int six;

void quicksort(int a[],int low,int high)
{
	if(low<high)
	{
		int part=partition(a,low,high);
		cout<<part;
		print(a,six);
		quicksort(a,low,part-1);
		quicksort(a,part+1,high);
	}
}
int main()
{
	int a[500];
	int i=1,x=0;
	while(i!=-1)
	{
		cout<<"enter element into the array"<<endl;
		cin>>i;
		if(i!=-1)
		a[x++]=i;
	}
	six=x;
	cout<<"size of array is "<<x<<endl;
	print(a,x);
	int q=x-1;
	quicksort(a,0,q);
	cout<<"after sorting "<<endl;
	print(a,x);
}
