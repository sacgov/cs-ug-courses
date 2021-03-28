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
    void dfsutil(int v,bool visited[])
    {
        visited[v] = true;
        std::vector<int> :: iterator it;
        for(it = adj[v].begin();it!=adj[v].end();it++)
        {
            if(!visited[*it])
                dfsutil(*it,visited);
            //cout<<endl;
        }


    }
    void sconnComponentsfillstack(int v,bool visited[],stack<int> &numstack)
    {
        visited[v] = true;
        std::vector<int> :: iterator it;
        for(it = adj[v].begin();it!=adj[v].end();it++)
        {
            if(!visited[*it])
                sconnComponentsfillstack(*it,visited,numstack);
            //cout<<endl;
        }
        numstack.push(v);
 
    }

    int sconnComponents()
    {
        
        bool visited[n];
        REP(i,n)visited[i] = false;
        stack<int> numstack;
        REP(i,n)
        {
            if(!visited[i])
            {
                //cout<<i<<" ";
                sconnComponentsfillstack(i,visited,numstack);
            }
        }
        graph newgraph(n);
        //cout<<n;
        REP(i,adj.size())
        REP(j,adj[i].size())
        {
            //cout<<i<<" "<<j<<endl;
            newgraph.dedge(adj[i][j]+1,i+1);
        }
        REP(i,n)visited[i] = false;
        int count = 0;
        while(!numstack.empty())
        {
            int v = numstack.top();
            numstack.pop();
            if(!visited[v])
            {
                count++;
                newgraph.dfsutil(v,visited);
            }
        }
        return count;
        
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
        g.dedge(a,b);
    }
    //cout<<"hi";
    cout<<g.sconnComponents();

}