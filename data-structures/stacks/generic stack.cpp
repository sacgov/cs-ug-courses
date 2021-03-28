#include<iostream>
#include<cstring>
using namespace std;
union uni
{
	int rollno;
	char name[15];
	float gpa;
};
struct student
{
	int tag;
	uni u1;
};
class stack
{
	public:
	int top=-1;
	int size;
	student s[10];
		stack()
		{
			top=-1;
			size=20;
		}
		void push(int a)
		{
			s[++top].u1.rollno=a;
		}
		void push(char a[])
		{
			strcpy(s[++top].u1.name,a);
		}
		void push(float f)
		{
			s[++top].u1.gpa=f;
		}
		char* pop()
		{
			return s[top--].u1.name;
		}
		int pop1()
		{
			return s[top--].u1.rollno;
		}
		float pop2()
		{
			return s[top--].u1.gpa;
		}
		void setTag(int a)
		{
			s[top+1].tag=a;
		}
		int givTag()
		{
			return s[top].tag;
		}
};
int main()
{
	stack s1;
	cout<<"Enter no of students"<<endl;
	int n;
	cin>>n;
	int k;
	for(int i=0; i<n; i++)
	{
		cout<<"Enter 1 for rollno 2 for name 3 for gpa"<<endl;
		int t;
		cin>>t;
		s1.setTag(t);
		cout<<"Enter the detail"<<endl;
		switch(t)
		{
			case 1:
				{
					cin>>k;
					s1.push(k);
					break;
					
				}
			case 2:
				{
					char t[15];
					cin.ignore();
					cin.getline(t,15);
					s1.push(t);
					break;
				}
			case 3:
				{
					float r;
					cin>>r;
					s1.push(r);
					break;
				}
		}
	}
	return 0;
	
}
