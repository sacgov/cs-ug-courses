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
void euler(graph g,int no,int *out,int *e,int &s)
{
	e[s++]=no;
	bool t=false;
	int i=0;
	for(i=0;i<g.n;i++)
    if(g.adj[no][i]==1)
    {
    	g.adj[no][i]=0;
    	g.adj[i][no]=0;
    	out[no]--;
    	out[i]--;
    	t=true;
    	break;
    }
    if(t)
    euler(g,i,out,e,s);
    
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
	print(g);
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
bool getind(int *eul,int*out,int &in,int u)
{
	for(int i=0;i<u;i++)
	{
		if(out[eul[i]]>0)
		{
			in=i;
		    return true;
		}
		
	}
	return false;
}
void splice(int * eul,int *e,int &u,int s,int in)
{
	int temp[100];
	for(int i=0;i<in;i++)
	temp[i]=eul[i];
	int h=in;
	for(int i=0;i<s;i++)
	temp[h++]=e[i];
	for(int i=in+1;i<u;i++)
	temp[h++]=eul[i];
	u=h;
	for(int i=0;i<h;i++)
	eul[i]=temp[i];
}
int main()
{
	graph g;
	create(g);
    cout<<"node to start ";
    int no;
    cin>>no;
    int out[g.n];
    getout(g,out);
    int e[100];int eul[100],in=8;	
    int s=0;int u=0;
    euler(g,no,out,e,s);
    for(int i=0;i<s;i++)
    eul[u++]=e[i];
	while(getind(eul,out,in,u))
	{
		for(int i=0;i<u;i++)
		cout<<eul[i]<<" ";
		cout<<endl<<in<<endl;
		s=0;
		euler(g,eul[in],out,e,s);
		splice(eul,e,u,s,in);	
	}
	for(int i=0;i<u;i++)
	cout<<eul[i]<<" ";
	cout<<endl;
}
/*
13
3
4
1
3
3
2
6
9
6
3
3
9
3
7
7
10
4
10
7
4
11
4
5
10
4
5
10
11
4
1
9
7
9
12
12
10
8
9
2
8
9
10
-1
1
*/
