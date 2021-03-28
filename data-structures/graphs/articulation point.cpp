#include<iostream>
using namespace std;
struct graph
{
	int n;
	int *c;
	int **adj;
};
struct ver
{
	int b[10];
	int child[10];
	int par=-1;
	int num=-1;
	int low=-1;
	int bc=0;
	int cc=0;
};
void dfsassign(graph g,int no,ver *v)
{
	static int nu=1;
//	cout<<no<<" ";
	v[no].num=nu++;
	g.c[no]=1;
	for(int i=0;i<g.n;i++)
	 if(g.c[i]!=-1&&g.adj[no][i]==1)
		{
			bool t=true;
			if(v[no].num<v[i].num||v[i].num==-1)
			t=false;
			if(v[no].par==i)
			t=false;
			for(int j=0;j<v[no].cc;j++)
			if(v[no].child[j]==i)
			{
				t=false;
				break;
			}
			if(t)
		   	v[no].b[v[no].bc++]=i;
		}
	for(int i=0;i<g.n;i++)
	{
		
		if(g.c[i]==-1&&g.adj[no][i]==1)
        {
        	v[no].child[v[no].cc++]=i;
        	v[i].par=no;
        	dfsassign(g,i,v);
        }
	} 
}
void print(ver *v,int n)
{
	for(int i=0;i<n;i++)
	{
		cout<<i<<" ";
		cout<<"num="<<v[i].num<<" "<<"low= "<<v[i].low<<"par="<<v[i].par<<" "<<endl<<"children ";
		for(int j=0;j<v[i].cc;j++)
		cout<<v[i].child[j]<<" ";
		cout<<endl<<"back ";
		for(int j=0;j<v[i].bc;j++)
		cout<<v[i].b[j]<<" ";
		cout<<endl<<endl;
	}
}
void low(ver *v,int x)
{
	v[x].low=v[x].num;
	for(int i=0;i<v[x].bc;i++)
	{
		if(v[v[x].b[i]].num<v[x].low)
		v[x].low=v[v[x].b[i]].num;
	}
	for(int i=0;i<v[x].cc;i++)
	{
		low(v,v[x].child[i]);
		if(v[v[x].child[i]].low<v[x].low)
		v[x].low=v[v[x].child[i]].low;
	}
}

void create (graph &g)
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
	while(1)
	{
		int s,d;
		cin>>s;
		if(s==-1)
		break;
		cin>>d;
		g.adj[s][d]=1;
		g.adj[d][s]=1;
	}
}
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
int getzero(ver*v,int n)
{
	for(int i=0;i<n;i++)
	{
		if(v[i].num=1)
		return i;
	}
}
int main()
{
	graph g;
	create(g);
	cout<<"node to start ";
    int no;
    cin>>no;
    ver v[g.n];
    print(g);
    dfsassign(g,no,v);
    int in=getzero(v,g.n);
    low(v,in);
    print(v,g.n);
    cout<<"in= "<<in<<endl;
    for(int i=0;i<g.n;i++)
    {
    	if(i==in)
    	{
    		if(v[i].cc>1)
    		cout<<i<<" ";
    	}
    	else
        for(int j=0;j<v[i].cc;j++)
        {	
    	    {
    		if(v[v[i].child[j]].low>=v[i].num)
    	    cout<<i<<" ";
    	    }	
        }
    }
}
/*
8
0
7
0
3
0
1
1
2
2 
3
3
4
4
5
5
3
2
6
-1
0


10
0
1
0
3
1
2
1
5
2
0
2
4
3
4
6
5
6
7
7
5
7
9
8
9
9
8
-1
*/
