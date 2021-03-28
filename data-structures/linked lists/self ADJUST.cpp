#include<iostream>
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
			cout<<"pos "<<count<<endl;
			break;
		}
		if(l==NULL)
		{
			cout<<"not found"<<endl;
			exit(1);
		}
    }
    return count;
}     
int del(lnode*&l,int d)
{
	int i;
	lnode *t;
	t=l;
	for(i=1;i<d-1;i++)
	t=t->next;
	int y=t->next->data;
	if(d!=1)
	{
	int y=t->next->data;
	t->next=t->next->next;}
	else
	{
	int y=t->data;
	l=l->next;}
	return y;
}
void print(lnode *l)
{
	while(l!=NULL)
{
cout<<l->data;
l=l->next;
}}  
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
char c='y';
while(c=='y')
{
int k;
cout<<"enter integer"<<endl;
cin>>k;
int w=search(l,k);
int r=del(l,w);
addfirst(l,r);
cout<<"enter y to continue"<<endl;
cin>>c;
}
cout<<"final list is"<<endl;
print(l);
}

