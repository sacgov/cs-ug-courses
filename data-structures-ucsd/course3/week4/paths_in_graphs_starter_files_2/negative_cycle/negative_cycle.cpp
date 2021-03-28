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


struct edges
{
    int u;
    int v;
    int wt;
};

int bellmanford()
{
    int n;
    cin>>n;
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
    }
    //REP(src,n)
    //{
        int count =0;
        int dist[n];
        REP(i,n) dist[i] = 90000;
        dist[0] = 0;
        REP(j,n-1)
        {
            REP(i,m)
            {
                if(dist[e[i].v] > dist[e[i].u]+e[i].wt )
                    dist[e[i].v] = dist[e[i].u]+e[i].wt;   
            }
        }
        REP(i,m)
            {
                if(dist[e[i].v] > dist[e[i].u]+e[i].wt )
                    return 1;
            }
   // }
    return 0;
}
int main()
{
    cout<<bellmanford();
    return 0;
}