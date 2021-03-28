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
lnode* mergelists(lnode *l1,lnode* l2)
{
	lnode*T;
	if(l1==NULL)
	return l2;
	else if(l2==NULL)
	return l1;
	else if(l1->data<l2->data)
	{
		T=new lnode;
		T->data=l1->data;
		T->next=mergelists(l1->next,l2);
	}
	else if(l1->data>l2->data)
	{
		T=new lnode;
		T->data=l2->data;
		T->next=mergelists(l1,l2->next);	
	}
	return(T);
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
		cout<<"enter number of integers"<<endl;
	lnode *l1;
	lnode *tem;
    tem=new lnode;
    int n,i,j;
    l1=tem;
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
	cout<<"enter number of integers"<<endl;
	lnode *l2;
    tem=new lnode;
    l2=tem;
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
lnode *l3;
l3=new lnode;
l3->next=NULL;
l3=mergelists(l1,l2);
print (l3); 
}
