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
    void isbipartiteutil(int v,int visited[],int color[],int &check)
    {
        int colornow = 0;
        visited[v] = 1;
        color[v] = 0;
        queue<int> q;
        q.push(v);
        while(!q.empty())
        {
            int d = q.front();
            visited[d] = 1;
            q.pop();
            REP(i,adj[d].size())
            {
                if(visited[adj[d][i]]==0)
                {
                    q.push(adj[d][i]);
                }
                if(color[adj[d][i]] == -1)
                {
                    color[adj[d][i]] = color[d] ^ 1;
                }
                else if(color[adj[d][i]] == color[d])
                {
                    check = 0;
                    break;
                }
            }
        }

    }
    int isbipartite()
    {
        int color[n];
        int visited[n];
        int check = 1;
        REP(i,n) 
        {
            color[i] = -1;
            visited[i] = 0;
        }
        for(int i =0;i<n;i++)
        {
            if(visited[i] == 0)
            {
                isbipartiteutil(i,visited,color,check);
            }
        }
        return check;

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
    cout<<g.isbipartite();
}