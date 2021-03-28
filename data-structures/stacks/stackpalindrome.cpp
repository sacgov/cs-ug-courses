#include<iostream>
#include<cstring>
using namespace std;
class stack
{
	public:
		void input();
		void output();
		void push(char x);
		char pop();
		char a[100];
		int t=0;
		
};
int main()
{
	stack s;
	cout<<"enter the string to checked"<<endl;
	char p[100];
	cin.getline(p,100);
	int len=strlen(p);
		for(int i=0;i<len;i++)
		{
			s.push(p[i]);			
		}

	int u=0;
	for(int i=0;i<len;i++)
	{
		char d=s.pop();
		if(d==p[i])
		u++;
	}
	if(u==len)
	cout<<"it is a palindrome";
	else
	cout<<"it is not a palindrome";
	
	
}
void stack::input()
{
	cout<<"enter number of character to input";
	int n;
	cin>>n;
	for(int i=0;i<100;i++)
	cin>>a[i];
	t++;
	
	
}
void stack::output()
{
	int i;
	for(i=0;i<t;i++)
	cout<<a[i];
}
void stack::push(char x)
{
	a[t]=x;
	t++;
}
char stack::pop()
{
	t--;
	return a[t];

}
