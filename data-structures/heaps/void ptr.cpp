#include<iostream>
using namespace std;
int main()
{
	void *p;
	p=new int;
	*p=4;
	cout<<*p;
}
