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

ll cmerge(int arr[],int temp[],int l,int mid,int h)
{
  ll count = 0;
  int i = l;
  int j= mid;
  int k = l;
  while(i<mid && j<=h)
  {
    if(arr[i]<=arr[j])
    {
      temp[k++] = arr[i++];
    }
    else
    {
      temp[k++] = arr[j++];
      count += mid - i;
    }
  }
  while(i<mid)
  temp[k++] = arr[i++];
  while(j<=h)
  temp[k++] = arr[j++];
  for(int i =l;i<=h;i++)
  arr[i] = temp[i];
  return count;
}
ll count_inversions(int arr[],int temp[],int l,int h)
{
  int mid = l + h;
  mid = mid/2;
  ll count = 0;
  if(h>l)
  {
    
    count = count_inversions(arr,temp,l,mid);
    count +=count_inversions(arr,temp,mid+1,h);
    count +=cmerge(arr,temp,l,mid+1,h);
  }
//  cout<<l<<" "<<h<<" "<<count<<endl;;
  return count;
}

int main() {
  int n;
  std::cin >> n;
  int a[n];
  for (size_t i = 0; i < n; i++) {
    std::cin >> a[i];
  }
  int b[n];
  std::cout << count_inversions(a, b, 0, n-1) << '\n';
}
