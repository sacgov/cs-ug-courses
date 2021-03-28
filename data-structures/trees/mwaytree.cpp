#include<iostream>
using namespace std;
struct mwt
{
	int key[2];
	mwt*child[3];
	int m=0;;
};
int getkey(mwt*root,int k)
{
	for(int i=0;i<root->m;i++)
	{
		if(k<(root->key[i]))
		return i;
	}
	return root->m;
}
void display(mwt*root)
{
		int i;
		for(i=0;i<root->m;i++)
		{
		if(root->child[i]!=NULL)
		display(root->child[i]);
		cout<<root->key[i]<<" ";
		}
		if(root->child[i]!=NULL)
		display(root->child[i]);
} 
void insert(mwt*&root,int k)
{
	if(root==NULL)
	{
		root=new mwt;
		root->key[0]=k;
		for(int i=0;i<3;i++)
		{
			root->child[i]=NULL;
		}
		root->m=1;
	}
	else
	{
		int p=getkey(root,k);
		if(root->m<2)
		{
			for(int i=root->m-1;i>=p;i--)
			{
				root->key[i+1]=root->key[i];
				root->child[i+1]=root->child[i];
				root->m++;
			}
			
		}
		else
		insert(root->child[p],k);
	}
}

int main()
{
	mwt*root=NULL;
	int fl=1,ele;
	while(fl)
	{
	cout<<"enter the element\n";
	cin>>ele;
	insert(root,ele);
	cout<<"enter 1 to continue(else 0)\n";
	cin>>fl;
	}
	display(root);
}
