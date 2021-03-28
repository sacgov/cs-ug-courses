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
    void edge(int a,int b)
    {
        adj[a-1].push_back(b-1);
        adj[b-1].push_back(a-1);
    //  cout<<"Edge Added :("<<a-1<<", "<<b-1<<" ) "<<endl;
    }


    void dedge(int a,int b)
    {
        adj[a-1].push_back(b-1);
    //  cout<<"Edge Added :("<<a-1<<", "<<b-1<<" ) "<<endl;
    }
};
struct edges
{
    int u;
    int v;
    int wt;
};

void bellmanford()
{
    int n;
    cin>>n;
    graph g(n);
    int m;
    cin>>m;
    int a,b,w;
    edges e[m];
    REP(i,m)
    {
        cin>>a>>b>>w;
        e[i].u = a-1;
        e[i].v = b-1;
        e[i].wt = w;
        g.dedge(a,b);
    }
    long long int dist[n];
    REP(i,n) dist[i] = INT_MAX;

    int src;
    cin>>src;
    dist[src-1] = 0;
    //dist[0] = 0;
     //cout<<"hel";
    REP(j,n-1)
    REP(i,m)
    {
        if(dist[e[i].u]!= INT_MAX && dist[e[i].v] > dist[e[i].u]+e[i].wt )
        {
            dist[e[i].v] = dist[e[i].u]+e[i].wt;
            //<<e[i].v<<" "<<dist[e[i].v]<<endl;
        }
        
    }
    //neg cycle
    queue<int>q;
    bool visited[n];
    REP(i,n) visited[i] = false;
    REP(i,m)
    {
        if(dist[e[i].u]!= INT_MAX && dist[e[i].v] > dist[e[i].u]+e[i].wt )
        {
            dist[e[i].v] = dist[e[i].u]+e[i].wt;
            q.push(e[i].v);
        }
    }
    set<int> s;
    while(!q.empty())
    {
        int d = q.front();
        visited[d] = true;
        s.insert(d);
        q.pop();
        REP(i,g.adj[d].size())
        if(!visited[g.adj[d][i]])
            q.push(g.adj[d][i]);
    }
    set<int>:: iterator it;
    REP(i,n)
    {
        if(s.find(i)!=s.end())
            cout<<"-"<<endl;
        else if(dist[i] == INT_MAX)
            cout<<"*"<<endl;
        else
            cout<<dist[i]<<endl;
    }

    //return 0;
}
int main()
{
    bellmanford();
    return 0;
}