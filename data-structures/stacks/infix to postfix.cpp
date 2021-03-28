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
	stack sta;
	char c,e;
	cout<<"enter infix"<<endl;
	getline(cin,x);
	int len=x.length();
	int i;
	char temp;
	for(i=0;i<len;i++)
	{
		if(x[i]!=')'&&x[i]!='('&&x[i]!='+'&&x[i]!='-'&&x[i]!='*'&&x[i]!='/')
		cout<<x[i];
		if(x[i]=='(')
		{
			sta.push(x[i]);
		}
	    if(x[i]==')')
			{
				while(sta.top!=-1&&sta.atop()!='(')				
				{
					cout<<sta.pop();	
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
					cout<<e;
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
			cout<<e;
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
	    cout<<e;	
	}	
	return 0;
}
	
