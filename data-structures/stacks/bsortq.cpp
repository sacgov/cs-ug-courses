#include<iostream>
using namespace std;
class queue
{
	public:
	int front=-1;
	int rear=-1;
	int size;
	int element[50];
//	int isqueuefull()
//	{
//		if((rear+1)%size==front)
//		return(1);
//		else
//		return(0);
//	}
//	int isqueueempty()
//	{
//		if(front==-1)
//		return(1);
//		else
//		return(0);
//	}
	void enqueue(int k)
	{
//		if(isqueuefull())
//		cout<<"queue is full ";
//		else
//		{
			if(front==-1)
			{
				front=0;
				rear=0;
			}
			else
			{
				rear=(rear+1)%size;
			}
			element[rear]=k;
//		}
	}
	int dequeue()
	{
		int t;
//		if(isqueueempty())
//		{
//			cout<<"queue is empty ";
//			return(-1);
//		}
//		else
//		{
			if(front==rear)
			{
				t=element[front];
				front=-1;
				rear=-1;
			}
			else
			{
				t=element[front];
				front=(front+1)%size;
			}
			return(t);
//		}
	}
	
};
int main()
{
	queue Q;
	int i,j,k,l;
	cout<<"enter no. of elements u need to sort ";
	cin>>Q.size;
	for(i=0;i<Q.size;i++)
	{
		cout<<"enter "<<i+1<<" element ";
		cin>>k;
		Q.enqueue(k);
	}
	for(i=0;i<Q.size;i++)
	{
		k=Q.dequeue();
		for(j=0;j<Q.size-1;j++)
		{
			l=Q.dequeue();
			if(k>l)
			Q.enqueue(l);	
			else
			{
				Q.enqueue(k);
				k=l;	
			}
		}
		Q.enqueue(k);
	}
	for(i=0;i<Q.size;i++)
	cout<<Q.dequeue()<<"\t";
	return 0;
}
