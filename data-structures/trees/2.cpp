#include<iostream>
using namespace std;
struct btnode
{
	btnode *lchild;
	char data;
	btnode *rchild;
};
typedef btnode *btptr;
class stack
{
	public:
		int size;
		int top=-1;
		btptr element[50];
		int isstackempty()
		{
			if(top==-1)
			return(1);
			else
			return(0);
		}
		int isstackfull()
		{
			if(top==size)
			return(1);
			else
			return(0);
		}
		void push(btptr b)
		{
			element[++top]=b;
		}
		btptr pop()
		{
			return(element[top--]);
		}
};
class queue
{
	public:
	int front=-1;
	int rear=-1;
	int size;
	btptr element[50];
	int isqueuefull()
	{
		if((rear+1)%size==front)
		return(1);
		else
		return(0);
	}
	int isqueueempty()
	{
		if(front==-1)
		return(1);
		else
		return(0);
	}
	void enqueue(btptr T)
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
			element[rear]=T;
//		}
	}
	btptr dequeue()
	{
		btptr t;
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
void insert(btptr BT,char ch)
{
	int n;
	cout<<"enter 1 to insert left 2 to insert right ";
	cin>>n;
	if(n==1)
	{
		if(BT->lchild!='\0')
		insert(BT->lchild,ch);
		else
		{
			BT->lchild=new btnode;
			BT->lchild->data=ch;
			BT->lchild->lchild='\0';
			BT->lchild->rchild='\0';
		}
	}
	else
	{
		if(BT->rchild!='\0')
		insert(BT->rchild,ch);
		else
		{
			BT->rchild=new btnode;
			BT->rchild->data=ch;
			BT->rchild->lchild='\0';
			BT->rchild->rchild='\0';
		}
	}
}
void print(btptr T)//level order traversal
{
	btptr t;
	btptr s,p;
	s=new btnode;
	s->lchild='\0';
	s->data='*';
	s->rchild='\0';
	queue Q,q;
	Q.enqueue(T);
	Q.enqueue(s);
	stack a;
	int tag=1;
	while(!Q.isqueueempty())
	{
		t=Q.dequeue();
		cout<<t->data<<"\n";
		if(t->data!='*')
		{
			q.enqueue(t);
			if(t->lchild!='\0')
			Q.enqueue(t->lchild);
			if(t->rchild!='\0')
			Q.enqueue(t->rchild);
		}
		else
		{
			if(tag==1)
			{
				while(!q.isqueueempty())
				{
					p=q.dequeue();
					cout<<p->data;
				}
				tag=2;
			}
			else
			{
				while(!q.isqueueempty())
				{
					p=q.dequeue();
					a.push(p);
				}
				while(!a.isstackempty())
				{
					p=a.pop();
					cout<<p->data;
				}
				tag=1;
			}
			cout<<"\n";
			if(Q.front!=Q.rear)
			Q.enqueue(s);
		}
	}
}
int main()
{
	btptr BT;
	BT=new btnode;
	int i=1,n=0;
	char ch;
	while(i==1)
	{
		cout<<"enter element which is to be added to binary tree ";
		cin>>ch;
		if(n==0)
		{
			BT->data=ch;
			BT->lchild='\0';
			BT->rchild='\0';
			n++;
		}
		else
		insert(BT,ch);
		cout<<"enter 1 to add elements 0 to stop ";
		cin>>i;
	}
	print(BT);
	return 0;
}
