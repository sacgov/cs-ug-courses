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
    int singledist(int u,int v)
    {
        int ans = 0;
        u = u-1;
        v = v-1;
        queue<int> q;
        q.push(u);
        q.push(-1);
        int visited[n] ;
        REP(i,n)visited[i] = 0;
        visited[u] = 1;
        //cout<<q.front();

        while(!q.empty())
        {
            int d = q.front();
            //cout<<d;
            q.pop();
            if(d == -1)
            {
                if(q.front()==-1||q.empty())
                break;
                q.push(-1);
                ans++;
            }
            else if(d == v)
            {
                return ans;
            }
            else
            {
                REP(i,adj[d].size())
                if(visited[adj[d][i]]==0)
                {
                    q.push(adj[d][i]);
                    visited[adj[d][i]] = 1;
                }
            }
        }
        return -1;
    }
      
    
    

    
};
int main()
{
    int n;
    cin>>n;
    graph g(n);
    int m;
    cin>>m;
    int a,b;
    REP(i,m)
    {
        cin>>a>>b;
        //cout<<a<<b<<endl;;
        g.edge(a,b);
    }
    int u,v;
    cin>>u>>v;
    //cout<<u<<endl<<v;
   cout<<g.singledist(u,v);
}