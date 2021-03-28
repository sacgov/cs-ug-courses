#include<iostream>
#include<string>
using namespace std;
struct bst
{
	bst*lchild;
	bst*rchild;
	char data;
};
void tcreate(string s,string s2,bst*&t)
{
	if(s.length()==0)
	return;
	int lenin=s.length();
	int a[lenin];
	for(int i=0;i<lenin;i++)
	a[i]=s2.find(s[i]);	
	int min=a[0];
	int minindex=0;
	for(int i=0;i<lenin;i++)
	{
		if(a[i]<min)
		{
			min=a[i];
			minindex=i;
		}
	}
	if(t==NULL)
	{
		t=new bst;
		t->lchild=NULL;
		t->rchild=NULL;
		t->data=s[minindex];
	}
	int g=s.find(s[minindex]);
	string lc=s.substr(0,g);
	int len=s.length();
	string rc=s.substr(g+1,len-g-1);
	tcreate(lc,s2,t->lchild);
	tcreate(rc,s2,t->rchild);
}
void inorder(bst*t)
{
	if(t!=NULL)
	{
		inorder(t->lchild);
		cout<<t->data;
		inorder(t->rchild);
	}
	else
	return;
} 
int main()
{
	cout<<"enter inorder"<<endl;
	string in,lorder;
	cin>>in;
	cout<<"enter lorder"<<endl;
	cin>>lorder;
	bst*t=NULL;
	tcreate(in,lorder,t);
	inorder(t);
}
