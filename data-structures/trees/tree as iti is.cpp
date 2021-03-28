#include<iostream>
using namespace std;
struct bst
{
	bst*lchild;
	bst*rchild;
	char data;
	int b;
}; 
int wid=1;
void inorder(bst*t)
{
	if(t!=NULL)
	{
		inorder(t->lchild);
		t->b=wid++;
		inorder(t->rchild);
	}
	else
	return;
} 
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
void printorder(bst*t,queue q)
{
	bst*n=NULL;
	int sub=0;
	while(t!=NULL)	
	{
	t->b=t->b-sub;
	for(int i=0;i<t->b;i++)
	cout<<" ";
	sub=sub+t->b;
    cout<<t->data;	
	if(t->lchild!=NULL)
    {q.enqueue(t->lchild);}
    if(t->rchild!=NULL)
    {q.enqueue(t->rchild);}
	bst*k=q.dequeue();
	if(k==NULL)
	{
	sub=0;
	q.enqueue(n);
	cout<<endl;
	k=q.dequeue();
	if(k==NULL)
	exit(1);
	t=k;}
	else
	t=k;
    }
}
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
int main()
{
	bst*root=NULL;
	create(root);
	 queue q;
	 bst*nu=NULL;
	 inorder(root);
   q.enqueue(nu);
   printorder(root,q);
}
