#include <iostream>
using namespace std;
struct lnode
{
	int data;
	lnode* next=NULL;
};
void addend(lnode *&l,int k)
{
	if(l==NULL)
	{
		l=new lnode;
		l->data=k;
		l->next=NULL;	
	}
	else
	{
	lnode *t;
	t=l;
	while(t->next!=NULL)
	t=t->next;
	t->next=new lnode;
	t->next->data=k;
	t->next->next=NULL;
	}
}
void print(lnode *l)
{
	while(l!=NULL)
{
cout<<l->data;
l=l->next;
}}
struct topnode
{
	int d;
	lnode*l=NULL;
	bool flag=false;
	int ind=0;
};
void fill(topnode*t,int n)
{
	for(int i=0;i<n;i++)
	{
		cout<<"enter data for "<<i<<endl;
		cout<<"enter value"<<endl;
	    cin>>t[i].d;
	    cout<<"enter indegree "<<endl;
	    cin>>t[i].ind;
	    int a=0;
	    while(a!=-1)
	{
		cout<<"enter next link "<<endl;
		cin>>a;
		if(a==-1)
		break;
		else
		addend(t[i].l,a);
	}
}
}
void printtop(topnode*t,int n)
{
	for(int i=0;i<n;i++)
	{
		cout<<"{"<<t[i].d<<"}"<<"{"<<t[i].ind<<"}";
	    print(t[i].l);cout<<endl;
}}
bool stillone(topnode*t,int &index,int n)
{
	for(int i=0;i<n;i++)
	{
		if((!t[i].flag)&&t[i].ind==0)
		{
			cout<<"tt"<<i<<"tt"<<t[index].d<<"tt"<<endl;
			index=i;
			t[i].flag=true;
			return true;
		}
	}
	return false;
}
void resetind(topnode*&t,lnode *l)
{
	while(l!=NULL)
{
	cout<<"LL";print(l);cout<<"LL"<<endl;
	t[l->data].ind--;
	l=l->next;
}
}
void topsort(topnode*t,int n)
{
	int index;
	while(stillone(t,index,n))
	{
		cout<<t[index].d<<" ";cout<<"k"<<endl; 
		resetind(t,t[index].l);
		printtop(t,n);
	}
}
int main()
{
	cout<<"enter the number of numbers ";
	int n;
	cin>>n;
	topnode t[n];
	fill(t,n);
	printtop(t,n);
	topsort(t,n);
		
}
/*


8
0
0
1
-1
1
1
2
-1
2
2
4
6
-1
3
0
2
5
-1
4
2
6
-1
5
2
4
6
-1
6
3
7
-1
7
1
-1


*/

