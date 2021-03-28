#include<iostream>
using namespace std;
struct gtnode
{
	gtnode* child[50];
	int mem=0;
	char data;
};
class queue
{
	public:
	int front=-1;
	int rear=-1;
	int size;
	gtnode* e[50];
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
	void enqueue(gtnode* k)
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
	gtnode* dequeue()
	{
		gtnode*t;
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
void printorder(gtnode*t,queue &q)
{
	gtnode*n=NULL;
	while(t!=NULL)	
	{
    cout<<t->data<<" ";	
    for(int i=0;i<t->mem;i++)
    {
    	if(t->child[i]!=NULL)
        q.enqueue(t->child[i]);
    }
	gtnode*k=q.dequeue();
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
void create(gtnode*&root)
{
	int i=0,t;
	if(root==NULL)
	{
		char c;
		cout<<"enter data of present child"<<endl;
		cin>>c;
		cout<<"enter no of children"<<endl;
		cin>>t;
		if(c!='.')
	{
		root=new gtnode;
		root->data=c;
		root->mem=t;
		for(i=0;i<root->mem;i++)
		root->child[i]=NULL;
	}
	else
	return;
	}
	    for(i=0;i<root->mem;i++)
		{
			cout<<"enter child "<<i+1<<" of "<<root->data<<" ";
			create(root->child[i]);
		}
} 
int main()
{
	gtnode*g;
	g=NULL;
	create(g);
	queue q;
	gtnode*n=NULL;
	q.enqueue(n);
	printorder(g,q);
}
