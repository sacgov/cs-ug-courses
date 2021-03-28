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
	queue q;
	int i,n,k;
	cout<<"enter size of the queue ";
	cin>>q.size;
	char c='y';
	while(c=='y')
	{
		cout<<"\nenter 1 to add element\n"
			<<"enter 2 for dequeue an element\n"
			<<"enter 3 to print\n";
		cin>>n;
		switch(n)
		{
			case 1: cout<<"enter element to be added to queue ";
					cin>>k;
					q.enqueue(k);
					break;
			case 2: cout<<q.dequeue();
					break;
			case 3: 
			int r=q.ndq();
			for(i=0;i<r;i++)
					{
						cout<<q.dequeue()<<" ";
					}
					break;
		}
		cout<<endl<<"enter y to continue"<<endl;
		cin>>c;
	}
}
