#include<iostream>
using namespace std;
struct lnode
{
	int data;
	lnode* next;
};
void print(lnode *l)
{
	while(l!=NULL)
{
cout<<l->data;
l=l->next;
}}

void deldup(lnode *l)
{
	lnode *t;
	int d;
	while(l->next!=NULL)
	{
		d=l->data;
		t=l;
		l=l->next;
		while(t->next!=NULL)
		{
			if(t->next->data==d)
			{
				t->next=t->next->next;
			}
			else
			if(t!=NULL)
			t=t->next;
		}		
	}
}   
void delndup(lnode *l,lnode *l2,int n)
{
	int d;
	while(l->next!=NULL)
	{
		d=l->data;
		t=l;
		l=l->next;
		while(t->next!=NULL)
		{
			if(t->next->data==d)
			{
				t->next=t->next->next;
			}
			else
			if(t!=NULL)
			t=t->next;
		}		
	}
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
		lnode *l2;
lnode *tem1;
tem1=new lnode;
l2=tem1;
cout<<"enter no of elements"<<endl;
cin>>n;	
for(i=0;i<n;i++)
{
	cin>>j;
	tem1->data=j;
	if(i!=n-1)
	{
	tem1->next=new lnode;
	tem1=tem1->next;}
	else
	tem1->next=NULL;
}
tem->next=l2;
deldup(l);
cout<<endl;
print(l);

	}
