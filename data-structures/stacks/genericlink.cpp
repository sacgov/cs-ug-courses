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
void print(lnode *l)
{
	while(l!=NULL)
{
cout<<l->data;
l=l->next;
}} 
void inputl(lnode* tem)
{
tem=new lnode;
int n,i,j;
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
}
struct dnode
{
	int data;
	dnode* right;
	dnode* left;
};
void addend(dnode *l,int k)
{
	dnode *temp;
	temp=new dnode;
	temp->data=k;
	temp->right=NULL;
	temp->left=NULL; 
	while(l->right!=NULL)
	l=l->right;
	l->right=temp;
	temp->left=l;	
} 
void print(dnode *l)
{
	while(l!=NULL)
{
cout<<l->data;
l=l->right;
}} 
void inputd(dnode *l)
{
l=new dnode;
l->right=NULL;
l->left=NULL;
int n,i,j;
cout<<"enter no of elements"<<endl;
cin>>n;	
cin>>j;
l->data=j;
for(i=1;i<n;i++)
{
	cin>>j;
	addend(l,j);
} 
}
class stack
{
	public:
		void input()
{
	cout<<"enter number of character to input";
	int n;
	cin>>n;
	for(int i=0;i<100;i++)
	cin>>a[i];
	t++; 
	
}
void output()
{
	int i;
	for(i=0;i<t;i++)
	cout<<a[i];
}
void push(int x)
{
	a[t]=x;
	t++;
}
int pop()
{
	t--;
	return a[t];

} 
		int a[100];
		int t=0;
		
};
struct final
{
	lnode *lf;
	dnode* df;
	stack sf;
	int tag;
};
int main()
{
	int i=1;
	int j;
	final f[5];
	for(i=0;i<5;i++)
	{
		cin>>f[i].tag;
		if(f[i].tag==1)
		{
			inputl(f[i].lf);
		}
		if(f[i].tag==2)
		{
			inputd(f[i].df);
		}
		if(f[i].tag==3)
		{
			cout<<"enter number of character to input";
	int n;
	cin>>n;
	for(int i=0;i<100;i++)
	cin>>a[i];
	t++;
		}
	}
	
}
