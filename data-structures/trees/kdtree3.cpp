#include<iostream>
using namespace std;
const int k=3;
struct kdnode
{
	kdnode *lchild;
	void *data[k];
	kdnode *rchild;
};
typedef kdnode *kdptr;
void insert(kdptr &T,void *v[],int l)
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
		int *p,*q;
		char *r,*s;
		switch(l)
		{
			case 0:p=(int*)T->data[0];
				   q=(int*)v[0];
				   if(q<p)
				   insert(T->lchild,v,(l+1)%k);
			   	   else
				   insert(T->rchild,v,(l+1)%k);
				   break;
			case 1:r=(char*)T->data[1];
				   s=(char*)v[1];
				   if(s<r)
				   insert(T->lchild,v,(l+1)%k);
			   	   else
				   insert(T->rchild,v,(l+1)%k);
				   break;
			case 3:p=(int*)T->data[2];
				   q=(int*)v[2];
				   if(q<p)
				   insert(T->lchild,v,(l+1)%k);
			   	   else
				   insert(T->rchild,v,(l+1)%k);
				   break;
		}
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
	s->data[0]='\0';
	s->rchild='\0';
	queue Q;
	Q.enqueue(T);
	Q.enqueue(s);
	while(!Q.isqueueempty())
	{
		t=Q.dequeue();
		if(t->data[0]!='\0')
		{
			for(int i=0;i<k;i++)
			{
				if(i==0)
				cout<<*(int*)(t->data[i])<<"\t";
				if(i==1)
				cout<<*(char*)(t->data[i])<<"\t";
				if(i==2)
				cout<<*(int*)(t->data[i])<<"\t";
			}
			if(t->lchild!='\0')
			Q.enqueue(t->lchild);
			if(t->rchild!='\0')
			Q.enqueue(t->rchild);
		}
		if(t->data[0]=='\0')
		{
			cout<<"\n";
			if(Q.front!=Q.rear)
			{
				Q.enqueue(s);
			}
		}
	} 
}
void inorder(kdptr K)
{
	if(K!='\0')
	{
		inorder(K->lchild);
		for(int i=0;i<k;i++)
		{
			switch(i)
			{
				case 0:cout<<*(int*)(K->data[0])<<",";
					   break;
				case 1:cout<<*(char*)(K->data[1])<<",";
					   break;
				case 2:cout<<*(int*)(K->data[2])<<",";
					   break;
			}
		}
		cout<<"\t";
		inorder(K->rchild);
	}
}
int main()
{
	kdptr K;
	K='\0';
	int i=1,j,l=0;
	int p,r;
	char q;
	void *v[k];
	while(i==1)
	{
		for(j=0;j<k;j++)
		{
			cout<<"enter "<<j<<" element  to be added to tree ";
//			cin>>v[j];
			if(j==0)
			{
				cin>>p;
				v[j]=(void*)new int(p);
			}
			if(j==1)
			{
				cin>>q;
				v[j]=(void*)new char(q);
			}
			if(j==2)
			{
				cin>>r;
				v[j]=(void*)new int(r);
			}
		}
//		for(j=0;j<k;j++)
//		{
//			if(j!=1)
//			cout<<*(int*)v[j]<<",";
//			else
//			cout<<*(int*)v[j]<<",";
//		}
		insert(K,v,l);
		cout<<"enter 1 to add elements 0 to stop ";
		cin>>i;
	}
//	print(K);
	cout<<endl;
	inorder(K);
	return 0;
}
