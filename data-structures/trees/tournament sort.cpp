#include<iostream>
using namespace std;
int a[10];
struct tmnode
{
	tmnode*lchild;
	tmnode*rchild;
	int data;
};
int min(int a,int b)
{
	if(a<b)
	return a;
	else
	return b;
}
int update(tmnode *&t)
{
	if(t==NULL)
    {
         return 1000;
    }
	if( t->lchild==NULL && t->rchild== NULL )
    {
        return (t->data);
    }
    else if( t->lchild!=NULL && t->rchild!=NULL )
    {

        t->data = (min(update(t->lchild),update(t->rchild)));
        return (t->data);
    }
}
void changemin(tmnode*&t,int k)
{
	if(t->data==k)
	{
		if(t->lchild=='\0'&&t->rchild=='\0')
		{
			t->data=1000;
			return;
		}
		if(t->lchild->data==k)
		changemin(t->lchild,k);
		if(t->rchild->data==k)
		changemin(t->rchild,k);
	}
}
void sort(tmnode*t)
{
	int k=0;
	while(t->data!=1000)
	{
		a[k++]=update(t);
		changemin(t,a[k-1]);
	}
	if(t->data=1000)
	{
		for(int i=0;i<k-1;i++)
		cout<<a[i]<<'\t';
	}
}
class queue
{
	public:
	int front=-1;
	int rear=-1;
	int size;
	tmnode* e[50];
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
	void enqueue(tmnode* k)
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
	tmnode* dequeue()
	{
		tmnode*t;
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
void inorder(tmnode*t)
{
	if(t!='\0')
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
	int arr[100];
	int i;
	cout<<"enter the number of numbers"<<endl;
	int n;cin>>n;
	queue q;
	for(i=0;i<n;i++)
	{
		cin>>arr[i];
		tmnode*t=new tmnode;
		t->data=arr[i];
		t->lchild='\0';
		t->rchild='\0';
		q.enqueue(t);
	}
	while(q.rear!=0)
	{
		tmnode*t1=q.dequeue();
		tmnode*t2=q.dequeue();
		tmnode*t3=new tmnode;
		t3->lchild=t1;
		t3->rchild=t2;
	    if(t1->data>t2->data)
	    t3->data=t2->data;
	    else
	    t3->data=t1->data;
		q.enqueue(t3);
	}
	tmnode*root=q.dequeue();
	cout<<"sorted order is"<<endl;
	sort(root);
	
	
}
