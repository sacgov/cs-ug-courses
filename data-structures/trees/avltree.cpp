#include<iostream>
using namespace std;
struct bst
{
	bst*lchild;
	bst*rchild;
	int data;
};
int height(bst*t)
{
	if(t==NULL)
	return -1;
	else
	return(1+max(height(t->lchild),height(t->rchild)));
}

int dif(bst*t)
{
	return(height(t->lchild)-height(t->rchild));
}
void srlc(bst*&t)
{
	bst*t1=t->lchild;
	t->lchild=t1->rchild;
	t1->rchild=t;
	t=t1;
}
void srrc(bst*&t)
{
	bst*t1=t->rchild;
	t->rchild=t1->lchild;
	t1->lchild=t;
	t=t1;
}
void drlc(bst*&t)
{
	srrc(t->lchild);
	srlc(t);
}
void drrc(bst*&t)
{
	srlc(t->rchild);
	srrc(t);
}
void insert(bst*&t,int k)
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
		if(k<t->data)
		{
		insert(t->lchild,k);
		if(dif(t)==2)
		{
			if(k<t->lchild->data)
			srlc(t);
			else
			drlc(t);
		}
	    }
		else
		{
		insert(t->rchild,k);
		if(dif(t)==-2)
		{
			if(k<t->rchild->data)
			drrc(t);
			else
			srrc(t);
		}
	    }
	}
} 
void insertd(bst*&t,int k)
{
	if(t==NULL)
	return;
	else
	{
		if(k<t->data)
		{
		insert(t->lchild,k);
		if(dif(t)==2)
		{
			if(k<t->lchild->data)
			srlc(t);
			else
			drlc(t);
		}
	    }
		else
		{
		insert(t->rchild,k);
		if(dif(t)==-2)
		{
			if(k<t->rchild->data)
			drrc(t);
			else
			srrc(t);
		}
	    }
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
int nodes(bst*t)
{
	if(t==NULL)
	return 0;
	else 
	return(1+nodes(t->lchild)+nodes(t->rchild));
}
class queue
{
	public:
	int front=-1;
	int rear=-1;
	int size;
	bst* e[500];
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
	break;
	else
	t=k;
    }
    else
    t=k;
    } 
}
int min(bst*t)
{
	if(t->lchild==NULL)
		return t->data;
	else{
		min(t->lchild);
	}
}
void del(bst* &t,int k)
{
	    int p;
		if(t->lchild==NULL && t->rchild==NULL){
			t=NULL;
		}
		else if(k==t->data){
			p=min(t->rchild);
			bst* L=t;
			del(L,p);
			t->data=p;
		}
		else if(k<t->data){
			del(t->lchild,k);
		}
		else if(k>t->data){
			del(t->rchild,k);
		}
}
void check(bst*&t)
{
	int c=dif(t);
	if(c==2)
	{
		if(t->lchild->rchild==NULL)
		srlc(t);
		else
		drlc(t);
	}
	if(c==-2)
	{
		if(t->rchild->rchild==NULL)
		srrc(t);
		else
		drrc(t);
	}
}

int main()
{
	bst*t;
	t=new bst;
	t=NULL;
	for(int i=1;i<=16;i++)
	{
	//	int k;
	//	cout<<"enter number to be added "<<endl;
	//	cin>>k;
		insert(t,i);
	}
	cout<<endl;
    preorder(t);
    cout<<endl;
    bst*n=NULL;
    queue q;
    q.enqueue(n);
    printorder(t,q);
    cout<<"enter element to delete"<<endl;
    int k;
    cin>>k;
    del(t,k);
    q.front=-1;
    q.rear=-1;
    q.enqueue(n);
    printorder(t,q);
    check(t);
    q.front=-1;
    q.rear=-1;
    q.enqueue(n);
    printorder(t,q);
}
