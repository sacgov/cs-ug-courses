#include<iostream>
using namespace std;
struct bst
{
	bst*lchild;
	bst*rchild;
	char data;
};
void create(bst*&root)
{
	if(root==NULL)
	{
		char c;
		cin>>c;
		if(c!='.')
	{
		root=new bst;
		root->data=c;
		root->lchild=NULL;
		root->rchild=NULL;
	}
	else
	return;
	}
		cout<<"enter left child for "<<root->data<<" ";
	    create(root->lchild);
	    cout<<"enter right child for "<<root->data<<" ";
	    create(root->rchild);
} 
class stack
{
	public:
	bst* s[50];
void push(bst* x)
{
	top++;
	s[top]=x;
	
}	
bst* pop()
{
	bst* t;
	t=s[top];
	top--;
	return t;
}
int top=-1;
bst* atop()
{
	return s[top];
}};
class queue
{
	public:
	int front=-1;
	int rear=-1;
	int size;
	bst* e[50];
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
	void enqueue(bst* k)
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
	bst* dequeue()
	{
		bst*t;
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
void iterinorder(bst *t)
{
	int k=1;
	stack s;
	while(k==1)
	{
		while(t!=NULL)
		{
			s.push(t);
			t=t->lchild;
		}
		while(s.top!=-1&&t==NULL)
		{
			t=s.pop();
			cout<<t->data;
			t=t->rchild;	
		}
		if(s.top==-1&&t==NULL)
		k=0;
	}
}
void iterpreorder(bst*t)
{
	stack s;
	s.push(t);
	while(s.top!=-1)
	{
		t=s.pop();
		cout<<t->data;
		if(t->rchild!=NULL)
		s.push(t->rchild);
		if(t->lchild!=NULL)
		s.push(t->lchild);
	}
} 
void postorder(bst*t)
{
	if(t!=NULL)
	{
		postorder(t->lchild);
		postorder(t->rchild);
		cout<<t->data; 
	}
	else
	return;
}
void iterpostorder(bst*t)
{
	stack s1,s2;
	s1.push(t);
	while(s1.top!=-1)
	{
		t=s1.pop();
		s2.push(t);
		if(t->lchild!=NULL)
		s1.push(t->lchild);
		if(t->rchild!=NULL)
		s1.push(t->rchild);
	}
	while(s2.top!=-1)
	cout<<s2.pop()->data<<" ";
}
int main()
{
	bst*root=NULL;
	create(root);
	iterpreorder(root);
}
