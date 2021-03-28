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
    double wt;
};
bool rev(edges a,edges b)
{
    if(a.wt < b.wt)
        return true;
    else
        return false;
}
int find(int parent[],int x)
{
    if(parent[x] == -1)
        return x;
    else
        return find(parent,parent[x]);
}
void unionk(int x,int y,int parent[])
{
    int xset = find(parent,x);
    int yset = find(parent,y);
    parent[xset] = yset;
}
double krushkal()
{
    int n;
    cin>>n;
    int m;
    int a,b;
    double d;
    int st[n],ds[n];
    for(int i = 0;i<n;i++)
        cin>>st[i]>>ds[i];
    m = n*(n-1);
    m = m/2;
    int k =0;
    edges e[m];
    REP(i,n)
    for(int j =i+1;j<n;j++)
    {
        e[k].u = i;
        e[k].v = j;
        
        d = (st[i] - st[j])*(st[i] - st[j]);
        d = d + (ds[j] - ds[i])*(ds[j] - ds[i]);
        d = sqrt(d);
        e[k++].wt = d;
    }
    
    sort(e,e+m,rev);
    int parent[n];
    REP(i,n) parent[i] = -1;
    double ans = 0;
    REP(i,m)
    {
        int a = e[i].u;
        int b= e[i].v;
        if(find(parent,a) != find(parent,b))
        {
            ans = ans + e[i].wt;
            unionk(a,b,parent);
        }

    }

    
    return ans;

}
int main()
{
    std::cout << std::setprecision(10);
    cout<<krushkal();
    return 0;
}  
