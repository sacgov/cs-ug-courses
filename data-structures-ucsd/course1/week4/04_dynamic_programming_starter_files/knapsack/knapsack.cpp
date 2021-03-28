#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
using std::vector;

int knapSack(int W, int wt[], int val[], int n)
{
   int i, w;
   int K[n+1][W+1];
 
   // Build table K[][] in bottom up manner
   for (i = 0; i <= n; i++)
   {
       for (w = 0; w <= W; w++)
       {
           if (i==0 || w==0)
               K[i][w] = 0;
           else if (wt[i-1] <= w)
                 K[i][w] = max(val[i-1] + K[i-1][w-wt[i-1]],  K[i-1][w]);
           else
                 K[i][w] = K[i-1][w];
       }
   }
 
   return K[n][W];
}

int main() {
  int n, W;
  std::cin >> W >> n;
  int w[n];
  int val[n];
  for (int i = 0; i < n; i++) {
    std::cin >> w[i];
    val[i] = w[i];
  }
  std::cout << knapSack(W, w,val,n) << '\n';
}
