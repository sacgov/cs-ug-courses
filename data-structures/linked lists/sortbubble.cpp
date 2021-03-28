#include<iostream>
using namespace std;
struct lnode
{
	int data;
	lnode* next;
};
void sort(lnode*l)
{
	lnode*temp;
	temp=l;
	int c=0;
	while(temp->next!=NULL)
	{
		if(temp->data>temp->next->data)
		{
			int k;
			k=temp->data;
			temp->data=temp->next->data;
			temp->next->data=k;
			c=1;
		}
		temp=temp->next;
	}
	if(c==1)
	sort(l);
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
sort(l);
print(l);
	
}
