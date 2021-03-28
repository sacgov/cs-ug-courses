#include<iostream>
using namespace std;
int arr[100]
struct lnode
{
	int data;
	lnode* next;
};
struct node
{
	int d;
	lnode* down;
	node* n;
};
void print1(node *l)
{
	while(l!=NULL)
{
cout<<l->d;
l=l->n;
}}
void addend(lnode *l,int k)
{
	lnode *temp;
	temp=new lnode;
	temp->data=k;
	while(l->next!=NULL)
	l=l->next;
	l->next=temp;
	temp->next=NULL;
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
	t->down=new lnode;
	t->down->data=num;
	t->down->next=NULL;}
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
void print(lnode *l)
{
	while(l!=NULL)
{
cout<<l->data<<" ";
l=l->next;
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
void sort(node *m)
{
	node *t;
	t=m;
	int k=0;
	while(m!=NULL)
	{    cout<<k++<<" ";
		if(m->down!=NULL)
    {
		arrinp(m->down);
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
