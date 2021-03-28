#include<iostream>
using namespace std;
int main()
{
	cout<<"enter the elements "<<endl;
	int p,n,i,j;
	cin>>n;
	static int a[200]; 
	cout<<"enter pass"<<endl;
	cin>>p;
    int deathcount=0;
    int count=0;
    while(deathcount!=n-1)
    {
    	for(int i=0;i<n;i++)
    	{
    		if(a[i]==0)
    		count++;
    		if(count==p)
    		{
    			a[i]=1;
    			count=0;
    			deathcount++;
    		}
    	}
    }
    for(i=0;i<n;i++)
    if(a[i]==0)
    cout<<endl<<i+1<<" element survives ";
}
