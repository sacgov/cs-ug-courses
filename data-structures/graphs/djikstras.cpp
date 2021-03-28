#include<iostream>
using namespace std;
struct graph
{
	int n;
	int *c;
	int **adj;
	int **w;
};
void print(graph g)
{
	for(int i=0;i<g.n;i++)
	{
		cout<<i<<"  ";
		for(int j=0;j<g.n;j++)
		cout<<g.adj[i][j]<<" ";
		cout<<" ";
		for(int j=0;j<g.n;j++)
		cout<<g.w[i][j]<<" ";
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
int getmin(int *d,int * c,int n)
{
	int min;
	for(int i=0;i<n;i++)
	{
		if(c[i]==-1)
		{
			min=i;
			break;
		}
	}
	for(int i=0;i<n;i++)
	{
		if(c[i]==-1)
		{
			if(d[i]<d[min])
			min=i;
		}
	}
	return min;
}
void dijkstra(graph g)
{
	print(g);
	cout<<"enter the source  ";
	int s;
	cin>>s;
	int *d;int *p;
	d=new int[g.n];
	p=new int[g.n];
	clear(g.c,g.n);
	for(int i=0;i<g.n;i++)
	{
		if(i==s)
		{
			d[i]=0;
			p[i]=i;
		}
		else
		{
			p[i]=-1;
			d[i]=1000;
		}
	}
	for(int i=0;i<g.n;i++)
	{
		int min=getmin(d,g.c,g.n);
		cout<<"min "<<min<<endl;
		for(int j=0;j<g.n;j++)
		{
			if(g.adj[min][j]!=0)
			{
				int dis=d[min]+g.w[min][j];
				if(dis<d[j])
				{
					p[j]=min;
					d[j]=dis;
				}
			}
		}
		g.c[min]=0;
		print(g);
		for(int i=0;i<g.n;i++)
		cout<<d[i]<<" ";
		cout<<endl;
		for(int i=0;i<g.n;i++)
		cout<<p[i]<<" ";
		cout<<endl;
		
	}
}
int main()
{
	graph g;
	cout<<"enter number of vertices ";
	cin>>g.n;
	g.adj=new int*[g.n];
	g.w=new int *[g.n];
	g.c=new int[g.n];
	for(int i=0;i<g.n;i++)
	{
		g.adj[i]=new int[g.n];
		g.w[i]=new int[g.n];
		g.c[i]=-1;
	}
	for(int i=0;i<g.n;i++)
	for(int j=0;j<g.n;j++)
	{
		g.adj[i][j]=0;
		g.w[i][j]=0;
	}
	print(g);
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
				cout<<"enter weight "<<endl;
				int w1;
				cin>>w1;
				g.adj[i][a]=1;
			    g.w[i][a]=w1;
			}
		}
	}
	dijkstra(g);	
}
/*
5
1
2
2
7
-1
2
3
3
8
4
5
-1
1
2
3
1
-1
4
4
-1
3
5
-1
0
*/



