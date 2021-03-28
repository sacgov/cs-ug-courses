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
class queue
{
	public:
	int front=-1;
	int rear=-1;
	int size=300;
    int e[500];
	int isqfull()
	{
		if((rear+1)%size==front)
		return(1);
		else
		return(0);
	}
	bool isempty()
	{
		if(front==-1)
		return(true);
		else
		return(false);
	}
	void enqueue(int k)
	{
		if(isqfull())
		cout<<"queue is full ";
		else
		{
			if(front==-1)
			{
				front=0;
				rear=0;
			}
			else
			{
				rear=(rear+1)%size;
			}
			e[rear]=k;
		}
	}
	int dequeue()
	{
		int t;
		if(isempty())
		{
			cout<<"queue is empty ";
			return 0;
		}
		else
		{
			if(front==rear)
			{
				t=e[front];
				front=-1;
				rear=-1;
			}
			else
			{
				t=e[front];
				front=(front+1)%size;
			}
			return(t);
		}
	}
	int ndq()
	{
		if(rear>=front)
		{
			return(rear-front+1);
		}
		else
		return(size-front+rear+1);
	}
};
void dfs(graph g,int no)
{
	cout<<no<<" ";
	g.c[no]=1;
	for(int i=0;i<g.n;i++)
    if(g.c[i]==-1&&g.adj[no][i]==1)
    dfs(g,i);
}
void bfs(graph g,int no)
{
	queue q;
	cout<<endl;
    q.enqueue(no);
    g.c[no]=1;
	while(!q.isempty())
	{
	    int t=q.dequeue();
	    cout<<t<<" ";
	    for(int i=0;i<g.n;i++)
        if(g.c[i]==-1&&g.adj[t][i]==1)
        {
            q.enqueue(i);
            g.c[i]=1;
        }
	}
	clear(g.c,g.n);
	return;
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
				g.adj[i][a]=1;
			}
		}
	}
    cout<<"node to start ";
    int no;
    cin>>no;
    bfs(g,no);
    cout<<endl;
    dfs(g,no);	
}
