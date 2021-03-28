#include<iostream>
using namespace std;
struct treapnode
{
	treapnode *lchild;
	char data;
	int pr;
	treapnode *rchild;
};
typedef treapnode *tptr;
void LR(tptr &T,tptr t)
{
	T->lchild=t->rchild;
	t->rchild=T;
	T=t;
}
void RR(tptr &T,tptr t)
{
	T->rchild=t->lchild;
	t->lchild=T;
	T=t;
}
void insert(tptr &T,char k,int i)
{
	tptr t;
	if(T=='\0')
	{
		T=new treapnode;
		T->lchild='\0';
		T->data=k;
		T->pr=i;
		T->rchild='\0';
	}
	else
	{
		if(k<T->data)
		{
			insert(T->lchild,k,i);
			t=T->lchild;
			if(T->pr>t->pr)
			{
				LR(T,t);
			}
		}
		else
		{
			insert(T->rchild,k,i);
			t=T->rchild;
			if(T->pr>t->pr)
			{
				RR(T,t);
			}	
		}
	}
}
void inorder(tptr T)
{
	if(T!='\0')
	{
		inorder(T);
		cout<<T->data<<" "<<T->pr<<"   ";
		inorder(T);
	}
}
int main()
{
	int i,j=1;
	char k;
	tptr T;
	T='\0';
	while(j==1)
	{
		cout<<"enter the data ";
		cin>>k;
		cout<<"enter its  priority ";
		cin>>i;
		insert(T,k,i);
		cout<<"enter 1 to continue else any other no. to exit ";
		cin>>j;
	}
	inorder(T);
	return 0;
}
