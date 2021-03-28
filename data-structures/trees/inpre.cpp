#include<iostream>
#include<string>
using namespace std;
struct bst
{
	bst*lchild;
	bst*rchild;
	char data;
};
void tcreate(string s,string&s2,bst*&t)
{
	if(s.length()==0)
	return;
	if(t==NULL)
	{
		t=new bst;
		t->lchild=NULL;
		t->rchild=NULL;
		t->data=s2[0];
	}
	int g=s.find(s2[0]);
	string lc=s.substr(0,g);
	int len=s.length();
	string rc=s.substr(g+1,len-g-1);
	s2=s2.substr(1,s2.length()-1);
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
	string in,pre;
	cin>>in;
	cout<<"enter preorder"<<endl;
	cin>>pre;
	bst*t=NULL;
	tcreate(in,pre,t);
	inorder(t);
}
