#include<iostream>
#include<string>
using namespace std;
struct bst
{
	bst*lchild;
	bst*rchild;
	char data;
};
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
string s[10];
void printorder(bst*t,queue q)
{
	bst*n=NULL;
	int k1=0;
	for(int i=0;i<10;i++)
	s[i]="";
	while(t!=NULL)	
	{
	s[k1]=s[k1]+t->data;
	if(t->lchild!=NULL)
    {q.enqueue(t->lchild);}
    if(t->rchild!=NULL)
    {q.enqueue(t->rchild);}
	bst*k=q.dequeue();
	if(k==NULL)
	{
	q.enqueue(n);
	k=q.dequeue();
	k1++;
	if(k==NULL)
	break;
	else
    t=k;
    }
    else
    t=k;
    }
    for(int i=k1;i>=0;i--)
	cout<<s[i];
}
void inorder(bst*t)
{
	if(t!=NULL)
	{
		inorder(t->lchild);
		cout<<t->data;
		inorder(t->rchild);
	}
	else
	return;
} 
int main()
{
	bst *root;
	root=NULL;
	create(root);
   inorder(root);
   cout<<endl;
   bst*j=NULL;
   queue q;
   q.enqueue(j);
   printorder(root,q);
}
