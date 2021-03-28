#include<iostream>
#include<string>
using namespace std;
class stack
{
	public:
	string s;
void push(char x)
{
	top++;
	s[top]=x;
	
}	
char pop()
{
	char t;
	t=s[top];
	top--;
	return t;
}
int top=-1;
char atop()
{
	return s[top];
}};
int main()
{
	string px="";
	char c,e;
	cout<<"enter postfix"<<endl;
	getline(cin,px);
	int len=px.length();
	int i;
     stack post;
	string o="";
	int k=px.length();
	for(i=0;i<k;i++)
	{
		if(px[i]=='+'||px[i]=='-'||px[i]=='*'||px[i]=='/')
		{
			if(post.top>-1){
			
			int x=post.pop();
    	    x=x-48;
         	int y=post.pop();
    	    y=y-48;
    	   if(px[i]=='/')
    	{
    		int u=y/x;
    		char c=u+48;
    		post.push(c);
    		
    	}
    	if(px[i]=='-')
    	{
    		int u=y-x;
    		char c=u+48;
    		post.push(c);
    		
    	}
    	if(px[i]=='+')
    	{
    		int u=y+x;
    		char c=u+48;
    		post.push(c);
    		
    	}
    	if(px[i]=='*')
    	{
    		int u=y*x;
    		char c=u+48;
    		post.push(c);
    		
    	}}}
    	else
		post.push(px[i]);
	    }
	    c=post.pop();
	    int res=c-48;
	    cout<<res;
	return 0;
}
	
