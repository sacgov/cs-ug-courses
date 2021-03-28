#include<iostream>
using namespace std;
const int k=3;
struct kdnode
{
	kdnode *lchild;
	int data[k];
	kdnode *rchild;
};
typedef kdnode *kdptr;
void insert(kdptr &T,int v[],int l)
{
	int i;
	if(T=='\0')
	{
		T=new kdnode;
		T->lchild='\0';
		for(i=0;i<k;i++)
		{
			T->data[i]=v[i];
		}
		T->rchild='\0';
	}
	else
	{
		if(v[l]<T->data[l])
		insert(T->lchild,v,(l+1)%k);
		else
		insert(T->rchild,v,(l+1)%k);
	}
}
class queue
{
	public:
	int front=-1;
	int rear=-1;
	int size;
	kdptr element[50];
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
	void enqueue(kdptr k)
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
			element[rear]=k;
//		}
	}
	kdptr dequeue()
	{
		kdptr t;
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
void print(kdptr T)//level order traversal
{
	kdptr t;
	kdptr s;
	s=new kdnode;
	s->lchild='\0';
	for(int i=0;i<k;i++)
	s->data[i]=-1;
	s->rchild='\0';
	queue Q;
	Q.enqueue(T);
	Q.enqueue(s);
	while(!Q.isqueueempty())
	{
		t=Q.dequeue();
		if(t->data[0]!=-1)
		{
			for(int i=0;i<k;i++)
			cout<<t->data[i]<<"\t";
			if(t->lchild!='\0')
			Q.enqueue(t->lchild);
			if(t->rchild!='\0')
			Q.enqueue(t->rchild);
		}
		if(t->data[0]==-1)
		{
			cout<<"\n";
			if(Q.front!=Q.rear)
			{
				Q.enqueue(s);
			}
		}
	} 
}
void inorder(kdptr T)
{
	if(T!='\0')
	{
		inorder(T->lchild);
		for(int i=0;i<k;i++)
		cout<<T->data[i]<<",";
		cout<<"  ";
		inorder(T->rchild);
	}
}
int main()
{
	kdptr K;
	K='\0';
	int i=1,j,v[k],l=0;
	while(i==1)
	{
		for(j=0;j<k;j++)
		{
			cout<<"enter "<<j<<" element  to be added to tree ";
			cin>>v[j];
		}
		insert(K,v,l);
		cout<<"enter 1 to add elements 0 to stop ";
		cin>>i;
	}
	print(K);
	cout<<"\n";
	inorder(K);
	return 0;
}
