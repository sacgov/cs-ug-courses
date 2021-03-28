#include<iostream>
using namespace std;
class queue
{
	public:
	int front=-1;
	int rear=-1;
	int size;
	int e[50];
	int isqfull()
	{
		if((rear+1)%size==front)
		return(1);
		else
		return(0);
	}
	int isqempty()
	{
		if(front==-1)
		return(1);
		else
		return(0);
	}
	void enqueue(int k)
	{
		if(isqfull())
		cout<<"queue is full ";
		else
		{
			if(front==-1)
			{
				front=0;
				rear=0;
			}
			else
			{
				rear=(rear+1)%size;
			}
			e[rear]=k;
		}
	}
	int dequeue()
	{
		int t;
		if(isqempty())
		{
			cout<<"queue is empty ";
			exit(1);
		}
		else
		{
			if(front==rear)
			{
				t=e[front];
				front=-1;
				rear=-1;
			}
			else
			{
				t=e[front];
				front=(front+1)%size;
			}
			return(t);
		}
	}
	int ndq()
	{
		if(rear>=front)
		{
			return(rear-front+1);
		}
		else
		return(size-front+rear+1);
		
	}
	
};
int main()
{
	queue Q;
	int i,j,k,m;
	cout<<"enter no. of elements ";
	cin>>Q.size;
	for(i=0;i<Q.size;i++)
	{
		cout<<"enter element ";
		cin>>k;
		Q.enqueue(k);
	}
	for(i=0;i<Q.size;i++)
	{
		k=Q.dequeue();
		for(j=0;j<Q.size-1;j++)
		{
			m=Q.dequeue();
			if(k>m)
			Q.enqueue(m);	
			else
			{
				Q.enqueue(k);
				k=m;	
			}
		}
		Q.enqueue(k);
	}
	for(i=0;i<Q.size;i++)
	cout<<Q.dequeue()<<" ";
	return 0;
}
