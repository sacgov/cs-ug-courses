#include<iostream>
using namespace std;
struct lnode
{
	int data;
	lnode* next;
};
struct tr
{
	int data;
	tr*l;
	tr*r;
	tr*m;
}
void addend(lnode *l,int k)
{
	if(l==NULL)
	{
		l=new lnode;
		l->next=NULL;
		l->data=k;
	}
	lnode *temp;
	temp=new lnode;
	temp->data=k;
	temp->next=NULL;
	while(l->next!=NULL)
	l=l->next;
	l->next=temp;	
} 
int main()
{
    int i=0;
    lnode*l=NULL;
	for(i=0;i<10;i++)
	{
		addend(l,i);
	}
	int a[10],c=0;
	while(l!=NULL)
	{
		a[c++]=l->data;
		l=l->next;
	}
	tr*t=NULL;
	create(t)
}
