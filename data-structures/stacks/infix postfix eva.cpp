
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
		px+=x[i];
		if(x[i]=='(')
		{
			sta.push(x[i]);
		}
	    if(x[i]==')')
			{
				while(sta.top!=-1&&sta.atop()!='(')
				
				{
					px+=sta.pop();
					
				}
				
				
			}	
			
		
		if(x[i]=='+'||x[i]=='-')
		{
			c=sta.atop();
			if(sta.top==-1)
			sta.push(x[i]);
			
			else
			{
				while((c=='*'||c=='/'||c=='+'||c=='-')&&sta.top!=-1)
				{
					e=sta.pop();
					if(e!='(')
					px+=e;
					c=sta.atop();
				}
				sta.push(x[i]);
			
			
			
			}
		}
	
	if(x[i]=='*'||x[i]=='/')
	{
		if(sta.top==-1)
		sta.push(x[i]);
		else
		{
		
		c=sta.atop();
		while((c=='/'||c=='*')&&sta.top!=-1)
		{
			e=sta.pop();
			if(e!='(')
			px+=e;
			c=sta.atop();
		}
		sta.push(x[i]);
	}
}
	}
	while(sta.top!=-1)
	{
		e=sta.pop();
	    if(e!='(')
	    {
	    	px+=e;
	    }
	    
		
	}
	cout<<px<<endl;
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
	
