#include<iostream>
using namespace std;
struct bst
{
	bst *lchild;
	int data;
	bst *rchild;
};
struct lnode
{
	int range;
	bst* t;
	lnode *next;
};
class stack
{
	public:
		int size;
		int top=-1;
		bst* element[50];
		int isstackempty()
		{
			if(top==-1)
			return(1);
			else
			return(0);
		}
		int isstackfull()
		{
			if(top==size)
			return(1);
			else
			return(0);
		}
		void push(bst* b)
		{
			element[++top]=b;
		}
		bst* pop()
		{
			return(element[top--]);
		}
};
void insert(bst* &T,int k)
{
	if(T=='\0')
	{
		T=new bst;
		T->data=k;
		T->lchild='\0';
		T->rchild='\0';
	}
	else
	{
		if(T->data>k)
		insert(T->lchild,k);
		else
		insert(T->rchild,k);
	}
}
void addend(lnode* &L,int k)
{
	if(L=='\0')
	{
		L=new lnode;
		L->range=k;
		L->t='\0';
		int j=1,i;
		while(j==1)
		{
			cout<<"enter data to the bst ";
			cin>>i;
			insert(L->t,i);
			cout<<"enter 0 stop adding otherwise 1 ";
			cin>>j;
		}
		L->next='\0';
	}
	else
	addend(L->next,k);
}
int search(lnode* L,bst* T,int k,int tag)
{
	if(L!='\0')
	{
		if(tag==1)
		{
			if(k>L->range)
			{
				if(L->next!='\0')
				{
					if(k>L->next->range)
					return(search(L->next,L->next->t,k,tag));
					else
					{
						tag=2;
						return(search(L,L->t,k,tag));
					}
				}
				else
				{
					tag=2;
					return(search(L,L->t,k,tag));
				}
			}
			else
			return(0);
		}
		else
		{
			if(k==T->data)
			return(1);
			else if(k<T->data)
			return(search(L,T->lchild,k,tag));
			else if(k>T->data)
			return(search(L,T->rchild,k,tag));
			else
			return(0);
		}
	}
}
void print(lnode* L)
{
	if(L!='\0')
	{
		cout<<L->range<<"-";
		if(L->next!='\0')
		cout<<L->next->range;
		else
		cout<<"-";
		cout<<":";
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
		cout<<endl;
		print(L->next);
	}
}
int main()
{
	lnode* L;
	L='\0';
	int i=1,k,j;
	while(i==1)
	{
		cout<<"enter the range ";
		cin>>k;
		addend(L,k);
		cout<<"enter 1 to continue 0 to exit ";
		cin>>i;
	}
	i=1;
	cout<<"enter element need tobe searched ";
	cin>>k;
	j=search(L,L->t,k,i);
	if(j==1)
	cout<<"element found in list\n";
	else
	cout<<"element not found ";
	print(L);
	return 0;
}
