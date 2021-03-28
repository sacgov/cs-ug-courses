#include<iostream>
using namespace std;
struct lnode
{
	int data;
	lnode* next;
};  
void del(lnode*l,int d)
{
	while(l->next!=l)
	{
	int i;
	for(i=1;i<d-1;i++)
    l=l->next;
    l->next=l->next->next;
    l=l->next;
    }
    cout<<l->data;
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
	tem->data=i+1;
	if(i!=n-1)
	{
	tem->next=new lnode;
	tem=tem->next;}
	else
	tem->next=l;
} 
cout<<"enter number of pass"<<endl;
int nu;
cin>>nu;
if(nu<2)
{
cout<<"it is not possible "<<endl;
exit(1);}
del(l,nu);
}
