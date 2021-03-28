#include<iostream>
using namespace std;
struct lnode
{
	int data;
	lnode* next;
};
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
void print(lnode *l)
{
	while(l!=NULL)
{
cout<<l->data;
l=l->next;
}}
void del(lnode*&l,int d)
{
	lnode*head=l;
	int i;
	lnode *t;
	t=l;
	for(i=1;i<d-1;i++)
	{
		t=t->next;
		if(t->next==NULL)
		{
			if(l->next!=NULL)
		del(l,l->next->data);
	    return;
		}
	}
	if(d!=1)
	t->next=t->next->next;
	else
	l=l->next;
}  
int main()
{
lnode *l;
lnode *tem;
tem=new lnode;
int n,i,j;
l=tem;
cout<<"enter no of elements"<<endl;
cin>>n;	
for(i=0;i<n;i++)
{
	cin>>j;
	tem->data=j;
	if(i!=n-1)
	{
	tem->next=new lnode;
	tem=tem->next;}
	else
	tem->next=NULL;
}
tem=l;
count=0;
for(i=0;i<n;i++)
{
	del(l,l->data);
}
}
