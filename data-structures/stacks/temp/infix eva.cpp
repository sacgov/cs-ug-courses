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
if(top>-1)
	return s[top];}}
void retval(stack sta,stack &post)
{
	char c;
	char g=post.pop();
	if(g=='+'||g=='-'||g=='*'||g=='/')
		{
			if(post.top>-1){
			
			int x=post.pop();
    	    x=x-48;
         	int y=post.pop();
    	    y=y-48;
    	   if(g='/')
    	{
    		int u=y/x;
    		char c=u+48;
    		post.push(c);
    		
    	}
    	if(g=='-')
    	{
    		int u=y-x;
    		char c=u+48;
    		post.push(c);
    		
    	}
    	if(g=='+')
    	{
    		int u=y+x;
    		char c=u+48;
    		post.push(c);
    		
    	}
    	if(g=='*')
    	{
    		int u=y*x;
    		char c=u+48;
    		post.push(c);
    		
	    }
	    }}
}
int main()
{
	string x;
	string px="";
	stack sta;
	stack val;
	char c,e;
	cout<<"enter infix"<<endl;
	getline(cin,x);
	int len=x.length();
	int i;
	for(i=0;i<len;i++)
	{
			if(x[i]!=')'&&x[i]!='('&&x[i]!='+'&&x[i]!='-'&&x[i]!='*'&&x[i]!='/')
		    val.push(x[i]);
		    if(x[i]=='(')
			sta.push(x[i]);
			if(x[i]==')')
			{
				while(sta.top!=-1&&sta.atop()!='(')
				
				{
					px+=sta.pop();
					retval(stack sta,stack val);
				}	
			}	    
	}
	return 0;
}
