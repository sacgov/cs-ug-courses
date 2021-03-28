#include<iostream>
using namespace std;
struct bst
{
	bst*lchild;
	bst*rchild;
	int data;
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
		insert(t->lchild,k);
		else
		insert(t->rchild,k);
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
int maxterm(bst *t)
{
	if(t->rchild==NULL)
	return t->data;
	else
	{
		t=t->rchild;
	    maxterm(t);
	}	
} 
int minterm(bst *t)
{
	if(t->lchild==NULL)
	return t->data;
	else
	{
		t=t->lchild;
	    minterm(t);
	}	
} 
void insearch(bst*t,int k)
{
	if(t!=NULL)
	{
		insearch(t->lchild,k);
		if(t->data==k)
		{
			cout<<"found";
			return;
		}
		insearch(t->rchild,k);
	}
	else
	return ;
} 
void search(bst*t,int k)
{
	if(t->data==k)
	{
	cout<<"found";
	return;}
	else if(t->data<k)
	{
		if(t->rchild==NULL)
		{
		cout<<"not found";
		return;}
		else
		search(t->rchild,k);
	}
	else
	{
		if(t->lchild==NULL)
		{
		cout<<"not found";
		return;}
		else
		search(t->lchild,k);
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
	    int m;
		if(t->lchild==NULL && t->rchild==NULL){
			t=NULL;
		}
		else if(k==t->data){
			m=min(t->rchild);
			bst* L=t;
			del(L,m);
			t->data=m;
		}
		else if(k<t->data){
			del(t->lchild,k);
		}
		else if(k>t->data){
			del(t->rchild,k);
		}
}
int main()
{
	bst *root;
	root=NULL;
	for(int i=1;i<6;i++)
	{int k;cin>>k;
	insert(root,k);}
	cout<<endl;
	postorder(root);
	cout<<endl;
	inorder(root);
	cout<<endl;
	preorder(root);
	cout<<endl;
	bst *tem=root;
	while(tem->lchild!=NULL)
	{
		tem=tem->lchild;
	}
	cout<<tem->data<<endl;
	tem=root;
	while(tem->rchild!=NULL)
	{
		tem=tem->rchild;
	}
cout<<maxterm(root);
cout<<endl;
insearch(root,4);
search(root,3);
cout<<endl;
bst*n=NULL;
queue q;
q.enqueue(n);
printorder(root,q);
cout<<endl;
del(root,2);
inorder(root);
}

