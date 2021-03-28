#include<iostream>
#include<string>
using namespace std;
struct bst
{
	bst* rchild;
	bst* lchild;
	char data;	
};
class stack
{
	public:
	bst* s[50];
void push(bst* x)
{
	top++;
	s[top]=x;
	
}	
bst* pop()
{
	bst* t;
	t=s[top];
	top--;
	return t;
}
int top=-1;
bst* atop()
{
	return s[top];
}};
bst* createbst(char x)
{
	bst *t=new bst;
	t->lchild=NULL;
	t->rchild=NULL;
	t->data=x;
	return t;
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
int cal(int a,char y,int b)
{
	if(y=='/')
   	return(a/b);
    if(y=='-')
    return(a-b);
   	if(y=='+')
   	return(a+b);
   	if(y=='*')
   	return(a*b);
} 
int eval(bst*t)
{
	if(t->data!='+'&&t->data!='-'&&t->data!='*'&&t->data!='/')
	return(t->data-48);
	else
	{
		int a=eval(t->lchild);
		int b=eval(t->rchild);
		return(cal(a,t->data,b));
	}
}
int main()
{
	string px="";
	char c,e;
	cout<<"enter postfix"<<endl;
	getline(cin,px);
	int len=px.length();
	int i;
    stack post;
	int k=px.length();
	for(i=0;i<k;i++)
	{
		if(px[i]=='+'||px[i]=='-'||px[i]=='*'||px[i]=='/')
		{
			bst* x=post.pop();
         	bst* y=post.pop();
         	bst *t=createbst(px[i]);
         	t->rchild=y;
         	t->lchild=x;
         	post.push(t);
	    }
    	else
		post.push(createbst(px[i]));
    }
    bst*root=post.pop();
    inorder(root);
    cout<<endl;
    cout<<eval(root);
	return 0;
}
	
