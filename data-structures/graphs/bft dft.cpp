#include<iostream>
using namespace std;
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
void swap (int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
void dfs(int **a,int n,int *ch,int no)
{
	cout<<no<<" ";
	ch[no]=1;
	for(int i=0;i<n;i++)
    if(ch[i]==-1&&a[no][i]==1)
    dfs(a,n,ch,i);
}
void bfs(int **a,int n,int *ch,int no)
{
	queue q;
	cout<<endl;
    q.enqueue(no);
    ch[no]=1;
	while(!q.isempty())
	{

	    int t=q.dequeue();
	    cout<<t<<" ";
	    for(int i=0;i<n;i++)
            if(ch[i]==-1&&a[t][i]==1)
        {
            q.enqueue(i);
            ch[i]=1;
        }
	}
	return;
}
/*void permute(int *a, int i, int n) 
{
   if (i == n)
   { for(int i=0;i<n;i++)
        if(ch[i]==-1&&copy[i]==1)
        {
            q.enqueue(i);
            ch[i]=1;
        }
   }
   else
   {
        for (int j=i;j<=n;j++)
       {
          swap((a+i), (a+j));
          permute(a, i+1, n);
          swap((a+i), (a+j)); //backtrack
       }
   }
} 
void abfs(int **a,int n,int *ch,int no)
{
	queue q;
	cout<<endl;
    q.enqueue(no);
    ch[no]=1;
	while(!q.isempty())
	{

	    int t=q.dequeue();
	    cout<<t<<" ";
	    if(en==n)
	    {
	    	en=0;
	    	cout<<endl;
	    	clear(ch);
	    }
	    int copy[n];
	    for(int i=0;i<n;i++)
	    copy[n]=a[t][i];
	}
	return;
}*/
void clear(int *ch,int n)
{
	for(int i=0;i<n;i++)
	ch[i]=-1;
}
int main()
{
	int n;
	cout<<"enter the number of nodes"<<endl;
	cin>>n;
	int ch[n];
	int **a;
	a=new int*[n];
	for(int i=0;i<n;i++)
	a[i]=new int[n];
	clear(ch,n);
	for(int i=0;i<n;i++)
	for(int j=0;j<n;j++)
	a[i][j]=0;
	for(int i=0;i<n;i++)
	{
	int a1=0;
		cout<<"enter elements for vertice "<<i<<endl;
		while(a1!=-1)
		{
			cin>>a1;
			if(a1==-1||a1>=n)
			break;
			else
			a[i][a1]=1;
		}
	}
    for(int i=0;i<n;i++)
    {
        cout<<endl;
        for(int j=0;j<n;j++)
        cout<<a[i][j];
    }
    cout<<"node to start ";
    int no;
    cin>>no;
    bfs(a,n,ch,no);
    cout<<endl;
    dfs(a,n,ch,no);
return 0;
}
/*
5
1
2
3
-1
0
2
4
-1
0
1
3
-1
0
2
4
-1
1
3
-1
0



*/

