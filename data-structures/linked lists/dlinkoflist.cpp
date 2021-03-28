#include<iostream>
using namespace std;
struct dnode
{
	int data;
	dnode* right;
	dnode *left;
};
struct node
{
	int d;
	dnode* down;
	node* n;
};
void print1(node *l)
{
	while(l!=NULL)
{
cout<<l->d;
l=l->n;
}}
void addend(dnode *l,int k)
{
	dnode *temp;
	temp=new dnode;
	temp->data=k;
	temp->right=NULL;
	temp->left=NULL;
	while(l->right!=NULL)
	l=l->right;
	l->right=temp;
	temp->left=l;	
} 
void addbranch(node *m,int num,int k)
{
	node *t;
	t=m;
	int i;
	for(i=0;i<k;i++)
	t=t->n;
	if(t->down==NULL)
	{
	t->down=new dnode;
	t->down->data=num;
	t->down->right=NULL;
	t->down->left=NULL;
	
	}
	else
	addend(t->down,num);
		
}
	void addnode(node *l,int k)
{
	node *temp;
	temp=new node;
	temp->d=k;
	temp->down=NULL;
	while(l->n!=NULL)
	l=l->n;
	l->n=temp;
	temp->n=NULL;
}
void print(dnode *l)
{
	while(l!=NULL)
{
cout<<l->data<<" ";
l=l->right;
}}
void printnode(node *m)
{
	node *t;
	t=m;
	int k=0;
	while(m!=NULL)
	{    cout<<k++<<" ";
		if(m->down!=NULL)
    {
		print(m->down);
	}
	cout<<endl;
	m=m->n;
}
}
int main()
{
	int i=0;
	node* m;
	m=new node;
	m->n=NULL;
	m->down=NULL;
	m->d=0;
	for(i=1;i<10;i++)
	addnode(m,i);
    char c='y';
	while(c=='y')
	{
		cout<<"data to be entered"<<endl;
		int num;
		cin>>num;
		int k=num%10;
		addbranch(m,num,k);
		cin>>c;
	}
	printnode(m);
}
