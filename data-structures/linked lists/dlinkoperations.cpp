#include<iostream>
using namespace std;
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
void addfirst(dnode*&l,int k)
{
	dnode *temp;
	temp=new dnode;
	temp->data=k;
	temp->right=l;
	temp->left=NULL;
	l=temp;
}
void del(dnode*&l,int d)
{
	int i;
	dnode *t;
	t=l;
	for(i=1;i<d-1;i++)
	t=t->right;
	if(d!=1)
	{
	t->right=t->right->right;
	t->right->left=t;
    }
	else
	{
	l=l->right;
	l->left=NULL;}
}  
void search(dnode *l,int d)
{
	int count=1;
	while(l!=NULL)
	{
		if(l->data!=d)
		{l=l->right;
		count++;}
		else
		{
			cout<<"pos "<<count;
			break;
		}
		if(l==NULL)
		{
			cout<<"not found"<<endl;
		}
    }
} 
void addafter(dnode* l,int d,int k)
{
	dnode* temp;
	temp=new dnode;
	temp->data=k;
	while(l->data!=d)
	{
		l=l->right;
	}
    	temp->left=l;
		temp->right=l->right;
		l->right=temp;
}
void addbefore(dnode* l,int d,int k)
{
	dnode* temp;
	temp=new dnode;
	temp->data=k;
	while(l->right->data!=d)
	{
		l=l->right;
	}
	temp->left=l;
	temp->right=l->right;
	l->right=temp;
} 
int main()
{

dnode *l;
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
int k;
 cout<<"addfirst"<<endl;
 cin>>k;
addfirst(l,k);
print(l);
cout<<endl;
cout<<"addafter"<<endl;
cin>>k;
int b;
cout<<"after what"<<endl;
cin>>b;
addafter(l,b,k);
print(l);
cout<<endl; 
cout<<"addbefore"<<endl;
cin>>k;
cout<<"after what"<<endl;
cin>>b;
addbefore(l,b,k);
print(l);
cout<<endl; 
cout<<"to search"<<endl;
cin>>k;
search(l,k);
cout<<endl;
cout<<"enter pos to be deleted"<<endl;
cin>>k;
del(l,k);
print(l);
cout<<endl;



}
