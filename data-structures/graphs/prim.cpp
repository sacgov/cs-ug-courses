#include<iostream>
using namespace std;
struct prim
{
	int s=0;
	int d=0;
	int w=0;
};
void clear(int *ch,int n)
{
	for(int i=0;i<n;i++)
	ch[i]=-1;
}
bool clean(int*ch,int n)
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
	int c=0;
	prim p[100];
	while(1)
	{
		int k;
		cin>>k;
		if(k!=-1)
		{
			p[c].s=k;
			cin>>p[c].d;
		    cin>>p[c].w;
		    c++;
		}
		else 
		break;		
	}
	cout<<"enter the number of vertices"<<endl;
	int k;
	cin>>k;
	int ch[k];
	clear(ch,k);
	cout<<"node to strt"<<endl;
	int g;
	cin>>g;
	ch[g]=0;
	for(int j=0;j<c;j++)
	{
		prim min;int mi=g;
		min.w=1000;
		for(int i=0;i<c;i++)
		{
			if(ch[p[i].s]==0||ch[p[i].d]==0)
			{
				if(!(ch[p[i].s]==0&&ch[p[i].d]==0))
				{
					if(p[i].w<min.w)
					{
						min=p[i];mi=i;
					}
				}
			}
		}
		if(min.w==1000)
		{
			break;
		}
		ch[min.s]=0;
		ch[min.d]=0;
		cout<<min.w<<" "<<min.s<<" "<<min.d<<endl;
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
9
0
*/
