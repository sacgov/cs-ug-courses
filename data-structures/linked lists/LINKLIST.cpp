#include <iostream>
using namespace std;
struct lnode
{
	int data;
	lnode* next;
};
void addfirst(lnode*&l,int k)
{
	lnode *temp;
	temp=new lnode;
	temp->data=k;
	temp->next=l;
	l=temp;
}
void addafter(lnode* l,int d,int k)
{
	lnode* temp;
	temp=new lnode;
	temp->data=k;
	while(l->data!=d)
	l=l->next;
	temp->next=l->next;
	l->next=temp;
}
void addbefore(lnode* l,int d,int k)
{
	lnode* temp;
	temp=new lnode;
	temp->data=k;
	while(l->next->data!=d)
	l=l->ext;
	temp->next=l->next;
	l->next=temp;
}
void addend(lnode *&l,int k)
{
	if(l==NULL)
	{
		l=new lnode;
		l->data=k;
		l->next=NULL;	
	}
	else
	{
	lnode *t;
	t=l;
	while(t->next!=NULL)
	t=t->next;
	t->next=new lnode;
	t->next->data=k;
	t->next->next=NULL;
	}
}
void print(lnode *l)
{
	while(l!=NULL)
{
cout<<l->data;
l=l->next;
}}
int search(lnode *l,int d)
{
	int count=1;
	while(l!=NULL)
	{
		if(l->data!=d)
		{l=l->next;
		count++;}
		else
		{
			cout<<"pos "<<count;
			break;
		}
		if(l==NULL)
		{
			cout<<"not found"<<endl;
		}
    }
}
void del(lnode*&l,int d)
{
	int i;
	lnode *t;
	t=l;
	for(i=1;i<d-1;i++)
	t=t->next;
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
int k;
cout<<"addfirst"<<endl;
 cin>>k;
addfirst(l,k);
print(l);
cout<<endl;
cout<<"addafter"<<endl;
cin>>k;
int b;
cout<<"after what"<<endl;
cin>>b;
addafter(l,b,k);
print(l);
cout<<endl;
cout<<"addbefore"<<endl;
cin>>k;
cout<<"after what"<<endl;
cin>>b;
addbefore(l,b,k);
print(l);
cout<<endl;
cout<<"addend"<<endl;
cin>>k;
addend(l,k);
print(l);
cout<<endl;
cout<<"to search"<<endl;
cin>>k;
search(l,k);
cout<<endl;
cout<<"enter pos to be deleted"<<endl;
cin>>k;
del(l,k);
print(l);
cout<<endl;
}
