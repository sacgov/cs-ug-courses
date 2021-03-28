#include<iostream>
#include<list>
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
void mark(int **a,int n,int *ch,int no,int &c)
{
	queue q;
    q.enqueue(no);
    ch[no]=1;
	while(!q.isempty())
	{

	    int t=q.dequeue();
	    for(int i=0;i<n;i++)
        {
        	if(ch[i]==-1&&a[t][i]==1)
        {
            q.enqueue(i);
            ch[i]=1;
        }
        if(ch[i]==-1&&a[t][i]==1)
        c=1;
        }
	}
	return;
}
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
    int c=0;
    for(int i=0;i<n;i++)
    {
    	clear(ch,n);
        mark(a,n,ch,i,c);
    }
    if(c==1)
    cout<<"cyclic";
    else
    cout<<"acyclic";
return 0;
}
    

