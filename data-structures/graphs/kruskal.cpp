#include<iostream>
using namespace std;
void clear(int *ch,int n)
{
	for(int i=0;i<n;i++)
	ch[i]=-1;
}
int s[100];
int find(int x)
{
	if(s[x]==-1)
		return x;
	else
		return find(s[x]);
}
void u(int x, int y)
{
	if(s[x]==-1)
		s[x] = y;
	else if(s[y]==-1)
		s[y] = x;
	else
		u(s[x],y);
}
int main()
{

	int c=0;
	int so[100],d[100],w[100];
	cout<<"enter source destination and weight until you want to stop to stop enter source as -1"<<endl;
	while(1)
	{
		int k;
		cin>>k;
		if(k!=-1)
		{
			so[c]=k;
			cin>>d[c];
		    cin>>w[c];
		    c++;
		}
		else 
		break;
	}

	for(int i=0;i<c;i++)
	{
		for(int j=i+1 ;j<c;j++)
		{
			if(w[i]>w[j])
			{
				int tw=w[i];
				int td=d[i];
				int ts=so[i];
				w[i]=w[j];
				so[i]=so[j];
				d[i]=d[j];
				w[j]=tw;
				so[j]=ts;
				d[j]=td;
			}
		}
	}
	int treec[c];
	clear(treec,c);
	clear(s,c);
	for(int i=0;i<c;i++)
	{
		if(find(so[i])!=find(d[i]))
		{
			cout<<w[i]<<" "<<so[i]<<" "<<d[i]<<endl;
			u(so[i],d[i]);
			treec[i] = 1;
		}
		if(treec[i])
		{
			cout<<" the edge "<<"("<<so[i]<<","<<d[i]<<")"<<" was added"<<endl;
			cout<<"************min spanning tree***************"<<endl;
			for(int j=0;j<c;j++)
				if(treec[j] == 1)
					cout<<"("<<so[j]<<","<<d[j]<<")"<<endl;
		}
		else
		{
			cout<<" the edge "<<"("<<so[i]<<","<<d[i]<<")"<<" was not added"<<endl;
			cout<<"************min spanning tree***************"<<endl;
			for(int j=0;j<c;j++)
				if(treec[j] == 1)
					cout<<"("<<so[j]<<","<<d[j]<<")"<<endl;
		}


	}	
}

/*
0
1
4
0
7
8
7
1
11
1
2
8
7
8
7
6
7
1
8
6
6
8
2
2
2
3
7
6
5
2
2
5
4
3
5
14
3
4
9
5
4
10
-1
*/

