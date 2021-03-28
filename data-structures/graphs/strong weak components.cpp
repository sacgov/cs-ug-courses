#include<iostream>
using namespace std;
struct graph
{
	int n;
	int *c;
	int **adj;
};
class stack
{
	public:
	int s[50];
void push(int x)
{
	top++;
	s[top]=x;
	
}	
int pop()
{
	int t;
	t=s[top];
	top--;
	return t;
}
int top=-1;
};
void print(graph g)
{
	for(int i=0;i<g.n;i++)
	{
		cout<<i<<"  ";
		for(int j=0;j<g.n;j++)
		cout<<g.adj[i][j]<<" ";
		cout<<endl;
	}
	cout<<endl;
	for(int i=0;i<g.n;i++)
	cout<<g.c[i]<<" ";
	cout<<endl;
} 
void clear(int *ch,int n)
{
	for(int i=0;i<n;i++)
	ch[i]=-1;
}
void dfs(graph g,int no,stack&s)
{
	cout<<no<<" ";
	s.push(no);
	g.c[no]=1;
	for(int i=0;i<g.n;i++)
    if(g.c[i]==-1&&g.adj[no][i]==1)
    dfs(g,i,s);
}
void create(graph &g)
{
	cout<<"enter number of vertices ";
	cin>>g.n;
	g.adj=new int*[g.n];
	g.c=new int[g.n];
	for(int i=0;i<g.n;i++)
	{
		g.adj[i]=new int[g.n];
		g.c[i]=-1;
	}
	for(int i=0;i<g.n;i++)
	for(int j=0;j<g.n;j++)
	{
		g.adj[i][j]=0;
	}
	for(int i=0;i<g.n;i++)
	{
		int a=0;
		cout<<"enter vertive for "<<i<<endl;
		while(a!=-1)
		{
			cout<<"vertice ";
			cin>>a;
			if(a==-1)
			break;
			else
			{
				g.adj[i][a]=1;
			}
		}
	}
}
void createcopy(graph &g1,graph g)
{
	g1.n=g.n;
	g1.adj=new int*[g1.n];
	g1.c=new int[g1.n];
	for(int i=0;i<g1.n;i++)
	{
		g1.adj[i]=new int[g1.n];
		g1.c[i]=-1;
	}
	for(int i=0;i<g1.n;i++)
	for(int j=0;j<g1.n;j++)
	{
		g1.adj[i][j]=0;
	}
	for(int i=0;i<g1.n;i++)
	{
		for(int j=0;j<g1.n;j++)
		{
			if(g.adj[i][j]==1)
			g1.adj[i][j]=1;
		}
	}
}
int main()
{
	graph g;
    create(g);
    clear(g.c,g.n);
	graph g1;
	createcopy(g1,g);
	for(int i=0;i<g1.n;i++)
	for(int j=0;j<g1.n;j++)
	{
		if(g.adj[i][j]==1)
		{
			g1.adj[j][i]=1;
			g1.adj[i][j]=0;
		}
	}
	clear(g1.c,g1.n);
	print(g);
	print(g1);
	int arr[100];int x=0;
	for(int i=0;i<g.n;i++)
    if(g.c[i]==-1)
    {
    	stack s;
    	dfs(g,i,s);
    	cout<<endl;
    	while(s.top!=-1)
		arr[x++]=s.pop();
    }
    for(int i=x-1;i>=0;i--)
    {
    	if(g1.c[arr[i]]==-1)
    	{
    	stack s;
    	dfs(g1,arr[i],s);
    	cout<<endl;
    	}
    } 	
}
/*
10
1
3
-1
2
5
-1
0
3
-1
4
-1
-1
2
-1
5
7
-1
8
-1
9
-1
7
-1
*/
