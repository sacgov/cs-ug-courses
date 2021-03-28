#include<iostream>
using namespace std;
struct graph
{
	int n;
	int *c;
	int **adj;
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
int v[90];
void strong(graph g,graph g1,int no,int b)
{
	if(v[b]==-1)
	{
		for(int i=0;i<g.n;i++)
		{
			if(g.adj[b][i]==1&i!=no)
			{
				v[b]=1;
				g1.adj[no][i]=1;
				strong(g,g1,no,i);
			}
		}
	}
}
void getout(graph g,int *out)
{
	for(int i=0;i<g.n;i++)
	{
		int count=0;
		for(int j=0;j<g.n;j++)
		{
			if(g.adj[i][j]==1)
			{
				count++;
			}
		}
		out[i]=count;
	}
}
void strprint(graph g1)
{
	int max=g1.n-1;
	int out[g1.n];
	getout(g1,out);
	while(max!=-1)
	{
		bool t=false;
		for(int i=0;i<g1.n;i++)
		if(out[i]==max)
		{
			cout<<i<<" ";
			t=true;
		}
		if(t)
		cout<<endl;
		max--;
	}
	
}
void dfs(graph g,graph g1,int no)
{
	cout<<no<<" ";
	g.c[no]=1;
	for(int i=0;i<g.n;i++)
    if(g.adj[no][i]==1)
    {
    	clear(v,g.n);
    	strong(g,g1,no,i);
    	clear(v,g.n);
    	if(g.c[i]==-1)
    	dfs(g,g1,i);
    }  
}
int main()
{
	graph g;
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
		while(a!=-1)
		{
			cin>>a;
			if(a==-1)
			break;
			else
			{
				g.adj[i][a]=1;
			}
		}
	}
	graph g1;
	createcopy(g1,g);
    cout<<"node to start ";
    int no;
    cin>>no;
    dfs(g,g1,no);
	for(int i=0;i<g.n;i++)
	if(g.c[i]==-1)
	dfs(g,g1,i);
	cout<<endl;
	print(g1);
	strprint(g1);
}
/*
5
1
-1
2
-1
3
-1
0
4
-1
-1
0
*/
