#include<iostream>
#include<string>
using namespace std;
struct lnode
{
	int data;
	lnode* next;
};
void print(lnode *l)
{
	string f=""; 
	while(l!=NULL)
{
int t=l->data;
char c=t+48;
f=f+c;
l=l->next;
}
int len=f.length();
for(int i=len-1;i>=0;i--)
cout<<f[i];
}
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
int main()
{
	string s1;
	string s2;
	cout<<"enter integers"<<endl;
	cin>>s1>>s2;
	int ls1=s1.length();
	int ls2=s2.length();
	int i,j,n;
	lnode *l1;
	lnode *l2;
	l1=new lnode;
	l2=new lnode;
	int d;
	l1->data=s1[ls1-1]-48;
	l1->next=NULL;
for(i=ls1-2;i>=0;i--)
{
	d=s1[i]-48;
	addend(l1,d);
}
l2->data=s2[ls2-1]-48;
l2->next=NULL;
for(i=ls2-2;i>=0;i--)
{
	d=s2[i]-48;
	addend(l2,d);
}
lnode *sum;
sum=new lnode;
sum->data=0;
sum->next=NULL;
int c=0;
int s;
int r;
while(l1!=NULL&&l2!=NULL)
{
	s=l1->data+l2->data+c;
	l1=l1->next;l2=l2->next;
	r=s%10;
	addend(sum,r);
	c=s/10;
}
if(l1==NULL)
{
	while(l2!=NULL)
	{
	s=l2->data+c;
	l2=l2->next;
	r=s%10;
	addend(sum,r);
	c=s/10;}
}
else
{
		while(l1!=NULL)
	{
	s=l1->data+c;
	l1=l1->next;
	r=s%10;
	addend(sum,r);
	c=s/10;}
}
if(c>0)
addend(sum,c);
sum=sum->next;
print(sum);
}
