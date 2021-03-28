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


class graphmat
{
public:
    int n;
    std::vector<std::vector<int> > adj;
    graphmat(int k)
    {
        n = k;
        std::vector<int> filler(n,0);
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
    void wedge(int a,int b,int w)
    {
        adj[a-1][b-1] = w;
    }
    void dijkstra(int src)
    {
        int parent[n];
        bool visited[n];
        int dist[n];
        REP(i,n)
        visited[i] = false,dist[i] = INT_MAX,parent[i] = -1;
        dist[src] = 0;
        int lastvisited = src;
        for (int i = 0; i < n-1; ++i)
        {
            int minvertex = src;
            int min = INT_MAX;
            REP(j,n)
            {
                if(!visited[j] && dist[j]<=min)
                    min = dist[j],minvertex = j;
            }
            visited[minvertex] = true;
            parent[minvertex] = lastvisited;
            lastvisited = minvertex;
            REP(j,n)
            {
                if(!visited[j] && adj[minvertex][j] && dist[minvertex]!= INT_MAX && dist[minvertex] + adj[minvertex][j] < dist[j])
                    dist[j] = dist[minvertex] + adj[minvertex][j];
            }

        }
        int k;
        cin>>k;
        if(dist[k-1] == INT_MAX)dist[k-1]=-1;
        cout<<dist[k-1];

    }
    
};
int main()
{
    int n;
    cin>>n;
    graphmat g(n);
    int m;
    cin>>m;
    int a,b,w;
    REP(i,m)
    {
        cin>>a>>b>>w;
        //cout<<a<<b<<endl;;
        g.wedge(a,b,w);
    }
    int src;
    cin>>src;
    g.dijkstra(src-1);
}