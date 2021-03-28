#include<iostream>
using namespace std;
struct bst
{
	bst*lchild;
	bst*rchild;
	int data;
	int b;
}; 
int c; int a[100];int b[100];int count=0;
void insert(bst*&t,int k,int count)
{
	if(t==NULL)
	{
		t=new bst;
		t->lchild=NULL;
		t->rchild=NULL;
		t->data=k;
		t->b=count;
	}
	else
	{
		if(k<t->data)
		{
		insert(t->lchild,k,count--);
	    }
		else
		
		{
			insert(t->rchild,k,count++);	
		}
		
	}
} 
void preorder(bst*t)
{
	if(t!=NULL)
	{
		//if(t->b<0)
		//{
		//	if(a[-t->b]==0)
		//{
			cout<<t->data<<" "<<t->b<<endl;
		/*	a[-t->b]=1;
		}
		}
		else
		{
			if(b[t->b]==0)
		{
			cout<<t->data;
			b[t->b]=1;
		}
		}*/
		preorder(t->lchild);
		preorder(t->rchild);
}
}
int main()
{
	for(int i=0;i<50;i++)
	{
		a[i]=b[i]=0;
	}
	bst*root=NULL;
	for(int i=0;i<8;i++)
	{
	int j;cin>>j;
	insert(root,j,count);
    }
	preorder(root);
}
