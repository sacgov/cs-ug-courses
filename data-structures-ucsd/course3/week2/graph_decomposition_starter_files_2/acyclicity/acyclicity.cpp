#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define lld I64d
#define all(v) (v).begin(),(v).end() 
#define mod 1000000007
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define RFOR(i,a,b) for(int i=(b-1);i>=(a);i--)
#define REP(i,n) for(int i=0;i<(n);i++)
#define RREP(i,n) for(int i=(n)-1;i>=0;i--)
#define allset(a,c) memset(a,c,sizeof a)
#define ll long long int
#define setbit(x, i) (x |= (1 << i))
#define MIN(a,b) (a>b?b:a)
#define MAX(a,b) (a>b?a:b)
#define PI acos(-1.0)space std;
class graph
{
public:
    int n;
    std::vector<std::vector<int> > adj;
    graph(int k)
    {
        n = k;
        std::vector<int> filler;
        REP(i,k)adj.pb(filler);

    }
    void dedge(int a,int b)
    {
        adj[a-1].push_back(b-1);
    //  cout<<"Edge Added :("<<a-1<<", "<<b-1<<" ) "<<endl;
    }
    void isacyclicutil(int v,bool visited[],bool &res,bool recstack[])
	{
		visited[v] = true;
		recstack[v] = true;
		std::vector<int> :: iterator it;
		for(it = adj[v].begin();it!=adj[v].end();it++)
		{
			if(!visited[*it])
				isacyclicutil(*it,visited,res,recstack);
			else if(recstack[*it])
			{
				res = true;
				return;
			}
		}
		recstack[v] = false;
	}
    bool isacyclic()
    {
    	bool visited[n];
    	bool recstack[n];
    	REP(i,n)
    	{
    		visited[i] = false;
    		recstack[i] = false;
    	}
    	bool res = false;
    	REP(i,n)
    	{
    		if(!visited[i])
    		isacyclicutil(i,visited,res,recstack);
    	}
    	return res;


    }
    
    
    
};

int main()
{
	int n;
	cin>>n;
	graph g(n);
	int m;
	cin>>m;
	REP(i,n)
	{
		int a,b;
		cin>>a>>b;
		g.dedge(a,b);
	}
	cout<<g.isacyclic();

}