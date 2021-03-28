#include<iostream>
#include<cstring>
using namespace std;
class stack
{
	public:
		void input();
		void output();
		void push(int x);
		int pop();
		int a[100];
		int t=0;
		
};
int main()
{
	stack s;
	cout<<"enter the number to converted"<<endl;
	int p;
	cin>>p;
	while(p!=0)
	{
		int k=p%2;
		s.push(k);
		p=p/2;
	}
	int h=s.t;
	for(int i=0;i<h;i++)
	cout<<s.pop();	
	
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
void stack::push(int x)
{
	a[t]=x;
	t++;
}
int stack::pop()
{
	t--;
	return a[t];

}
