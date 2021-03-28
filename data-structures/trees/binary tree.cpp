#include<iostream>
using namespace std;
struct bst
{
	bst*lchild;
	bst*rchild;
	char data;
};
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
int search(bst*t,char k)
{
	if(t!=NULL)
	{
		search(t->lchild,k);
		if(t->data==k)
		{
			return 1;
			exit(1);
		}
		search(t->rchild,k);
	}
	else
	return 0;
}
void linsert(bst*&t,int k)
{
	if(t==NULL)
	{
		t=new bst;
		t->lchild=NULL;
		t->rchild=NULL;
		t->data=k;
	}
	else
	{
		cout<<"enter  1 for right o for left";
		int u;
		cin>>u;
		if(u==0)
		linsert(t->lchild,k);
		else if(u==1)
		linsert(t->rchild,k);
		else
		cout<<"not valid option";
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
void printorder(bst*t)
{
	bst*n=NULL;
	queue q;
	q.enqueue(n);
	while(t!=NULL)
	{
    cout<<t->data<<" ";
	if(t->lchild!=NULL)
    {q.enqueue(t->lchild);}
    if(t->rchild!=NULL)
    {q.enqueue(t->rchild);}
	bst*k=q.dequeue();
	if(k==NULL)
	{
	q.enqueue(n);
	cout<<endl;
	k=q.dequeue();
	if(k==NULL)
	exit(1);
	else
	t=k;
    }
    else
    t=k;
    }
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
void preorder(bst*t)
{
	if(t!=NULL)
	{
		cout<<t->data;
		preorder(t->lchild);
		preorder(t->rchild);
	}
	else
	return;
}
void itercreate(bst *&t)
{
stack s;
cout<<"enter head data"<<endl;
char c;
cin>>c;
t=new bst;
t->lchild==NULL;
t->rchild==NULL;
t->data=c;
s.push(t);
c='l';
while(s.top!=-1)
{
while(c!='.')
{
	cout<<" enter left for "<<t->data<<endl;
	cin>>c;
	if(c!='.')
	{
	t->lchild=new bst;
	t=t->lchild;
	t->lchild=NULL;
	t->rchild=NULL;
	t->data=c;
	s.push(t);
    }
}
    do
    {
    	t=s.pop();
    	cout<<"enter right child for "<<t->data<<endl;
    	cin>>c;
    	if(c!='.')
    	{
    		t->rchild=new bst;
    		t=t->rchild;
    		t->lchild=t->rchild=NULL;
    		t->data=c;
    		s.push(t);
    	}
    }while(c=='.'&&s.top!=-1);
}
}
int main()
{
	bst *root;
	root=NULL;
/*	for(int i=1;i<=n;i++)
	{
		int k;
		cout<<"enter the number"<<endl;
		cin>>k;
	    insert(root,k);
    }*/
   create(root);
   inorder(root);
   cout<<endl;
   preorder(root);
   printorder(root);
}
