#include<iostream>
#include<string>
using namespace std;
union uni
{
	char s[100];
	int data;
};
struct lnode
{
	lnode* next;
	int tag;
	uni u1;
};
void print(lnode *l)
{
	while(l!=NULL)
	{
		if(l->tag==1)
		cout<<l->u1.s;
		else
		cout<<l->u1.data;
		cout<<endl;
		l=l->next;
	}
}
void addend(lnode *l,lnode* temp)
{
	while(l->next!=NULL)
	l=l->next;
	l->next=temp;
	temp->next=NULL;
}
int main()
{
	char c;
	lnode *l;
	l=new lnode;
	l->next=NULL;
		int t;
		cout<<"enter 1 for name 2 for no"<<endl;
		cin>>t;
		l->tag=t;
		if(t==1)
		{
			cin.ignore();
			cin.getline(l->u1.s,99);
		}
		else if(t==2)
		{
			int h;
			cin>>h;
			l->u1.data=h;
	    }
		else
		cout<<"wrong option"<<endl;
		cout<<"enter y for yes or any other for no"<<endl;
		cin>>c;
	while(c=='y')
	{
		int t;
		cout<<"enter 1 for name 2 for no"<<endl;
		cin>>t;
		if(t==1)
		{
			lnode *tem;
	        tem=new lnode;
	        tem->next=NULL;
	        tem->tag=t;
			cin.ignore();
			cin.getline(tem->u1.s,99);
			addend(l,tem);
		}
		else if(t==2)
		{
			int h;
			cin>>h;
			lnode *tem;
	        tem=new lnode;
	        tem->next=NULL;
	        tem->u1.data=h;
	        tem->tag=t;
			addend(l,tem);
		}
		else
		cout<<"wrong option"<<endl;
		cout<<"enter y for yes or any other for no"<<endl;
		cin>>c;
	}
print(l);
}
