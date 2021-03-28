#include<iostream>
using namespace std;
class stack
{
	public:
	int top=-1;
	int size;
	int element[50];
	void push(int b)
	{
		element[++top]=b;
	}
	int pop()
	{
		return(element[top--]);
	}
};
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
	stack s;
	int n,i,k;
	
	cout<<"enter 1 to fill stack with queue 2 to fill queue with stack \n";
	cin>>n;
	switch(n)
	{
		case 1: cout<<"enter size of the queue ";
				cin>>q.size;
				for(i=0;i<q.size;i++)
				{
					cout<<"enter element ";
					cin>>k;
					q.enqueue(k);
				}
				for(i=0;i<q.size;i++)
				s.push(q.dequeue());
				for(i=0;i<q.size;i++)
				cout<<s.pop()<<" ";
				break;
		case 2: cout<<"enter size of stack ";
				cin>>s.size;
				for(i=0;i<s.size;i++)
				{
					cout<<"enter element ";
					cin>>k;
					s.push(k);
				}
				for(i=0;i<s.size;i++)
				q.enqueue(s.pop());
				for(i=0;i<s.size;i++)
				cout<<q.dequeue()<<" ";
				break;
	}	
	return 0;
}
