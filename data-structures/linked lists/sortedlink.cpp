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
void combine(lnode *l1,lnode* l2,lnode* l3)
{   
	int d1=l1->data;
	int d2=l2->data;
	if(d1<=d2)
	{
	l3->data=d1;
	l1=l1->next;
    }
	else
	{
	l3->data=d2;
	l2=l2->next;}
	while(l1!=NULL&&l2!=NULL)
	{
		 d1=l1->data;
	     d2=l2->data;
	     if(d1<=d2)
	     {
	     	addend(l3,d1);
	     	l1=l1->next;
	     }
	     else
	     {
	     	addend(l3,d2);
	     	l2=l2->next;
	     }
	}
	if(l1==NULL)
	{
		while(l2!=NULL)
		{
			d2=l2->data;
			addend(l3,d2);
			l2=l2->next;
		}
	}
	if(l2==NULL)
	{
		while(l1!=NULL)
		{
			d1=l1->data;
			addend(l3,d1);
			l1=l1->next;
		}
	}
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
combine(l1,l2,l3);
print (l3); 
         
}
