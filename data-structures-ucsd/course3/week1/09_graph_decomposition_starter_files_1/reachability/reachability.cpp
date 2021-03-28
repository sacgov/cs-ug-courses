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
#define FE(i, x) for (auto i = begin(x); i != end(x); ++i)
#define allset(a,c) memset(a,c,sizeof a)
#define ll long long int
#define setbit(x, i) (x |= (1 << i))
#define MIN(a,b) (a>b?b:a)
#define MAX(a,b) (a>b?a:b)
#define PI acos(-1.0)

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
    int dfsutilpath(int v,int u,bool visited[])
    {
        visited[v] = true;
        if(v == u)
            return 1;
        else
        {
            std::vector<int> :: iterator it;
            for(it = adj[v].begin();it!=adj[v].end();it++)
            {
                if(!visited[*it])
                    if(dfsutilpath(*it,u,visited))
                        return 1;
            }
        }
        return 0;
 
    }
    int ispath(int u , int v)
    {
        bool visited[n];
        REP(i,n)
            visited[i]= false;
        return dfsutilpath(u,v,visited);

    }
    void edge(int a,int b)
    {
        adj[a-1].push_back(b-1);
        adj[b-1].push_back(a-1);
    //  cout<<"Edge Added :("<<a-1<<", "<<b-1<<" ) "<<endl;
    }
    
};
int main()
{
    int n;
    cin>>n;
    graph g(n);
    int m;
    cin>>m;
    REP(i,m)
    {
        int a,b;
        cin>>a>>b;
        g.edge(a,b);
    }
    int u,v;
    cin>>u>>v;
    cout<<g.ispath(u-1,v-1);
}