#include<iostream>
#include<cstdlib>
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
			count=0;
		}
    }
    return count;
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
lnode *l1;
tem=new lnode;
l1=tem;
cout<<"enter no of elements"<<endl;
int no;
cin>>no;	
for(i=0;i<no;i++)
{
	cin>>j;
	tem->data=j;
	if(i!=no-1)
	{
	tem->next=new lnode;
	tem=tem->next;}
	else
	tem->next=NULL;
}
int s=l1->data;
int pos=search(l,s);
if(pos==0)
exit(1);
if(pos+no>n+1)
{
cout<<"not found"<<endl;
exit(1);}

{
	for(i=1;i<pos;i++)
	l=l->next;
	for(i=1;i<=no;i++)
	{
		if(l->data!=l1->data)
		{
			cout<<"not a substring"<<endl;
			exit(1);
		}
		l=l->next;
		l1=l1->next;
		
	}
	cout<<"it is substring"<<endl;
}

}
