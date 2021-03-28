#include<iostream>
using namespace std;
void dfs(int **a,int n,int *ch,int no,int& c)
{
	c++;
	ch[no]=1;
	for(int i=0;i<n;i++)
    if(ch[i]==-1&&a[no][i]==1)
    dfs(a,n,ch,i,c);
}        
void clear(int *ch,int n)
{
	for(int i=0;i<n;i++)
	ch[i]=-1;
}
bool clean(int *ch,int n)
{
	for(int i=0;i<n;i++)
	{
		if(ch[i]==-1)
		return false;
	}
	return true;
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
    }int flag=0;
    for(int i=0;i<n;i++)
    {
    	int t=0;
    	clear(ch,n);
    	int c=0;
    	dfs(a,n,ch,i,c);
    	if(c<n)
    	flag=1;
    }
    if(flag==0)
    cout<<"strongly connected"<<endl;
    else
    {
    	int i;
    	int **b;
	b=new int*[n];
	for(int i=0;i<n;i++)
	b[i]=new int[n];
    	for( i=0;i<n;i++)
		for(int j=0;j<n;j++)
		if(a[i][j]==1)
	    {
	    	b[i][j]=1;
	    	b[j][i]=1;
	    }
	    cout<<endl;
    	clear(ch,n);i--;
    	int c=0;
    	dfs(a,n,ch,i,c);
    	if(c<n)
    	cout<<" disconnected";
    	else
        cout<<"weakly connected"<<endl;
    }
    
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

