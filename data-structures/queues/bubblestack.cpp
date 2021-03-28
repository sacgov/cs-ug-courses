#include<iostream>
using namespace std;
class stack
{
	public:
	int top=-1;
	int size;
	int arr[50];
	void push(int b)
	{
		arr[++top]=b;
	}
	int pop()
	{
		return(arr[top--]);
	}
};
int main()
{
	stack a,b;
	int i,j,x,t,z;
	cout<<"enter no. of numbers";
	cin>>a.size;
	b.size=a.size;
	for(i=0;i<a.size;i++)
	{
		cout<<"enter no ";
		cin>>x;
		a.push(x);
	}
	for(i=0;i<a.size;i++)
	{
		for(j=0;j<a.size-1;j++)
		{
			if(j==0)
			{
				x=a.pop(),t=a.pop();
				if(x>t)
				{
					b.push(t);
					b.push(x);
				}
				else
				{
					b.push(x);
					b.push(t);
				}
			}
			else
			{
				x=a.pop(),t=b.pop();
				if(x>t)
				{
					b.push(t);
					b.push(x);
				}
				else
				{
					b.push(x);
					b.push(t);
				}
			}
			
		}
			for(z=0;z<b.size;z++)
			cout<<a.arr[z];
			cout<<endl;
		for(z=0;z<b.size;z++)
		{
			x=b.pop();
			a.push(x);
		}
		
	}
	for(i=0;i<a.size;i++)
	{
		cout<<a.pop()<<" ";
	}
	return 0;
}
