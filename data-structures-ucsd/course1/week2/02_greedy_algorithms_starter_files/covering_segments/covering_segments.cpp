#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
using std::vector;


vector<int> optimal_points(std::vector<int> start,std::vector<int> end,int n) {
  vector<int> points;
  std::vector<int> ::iterator it;
  while(1)
  {
    it = min_element(end.begin(),end.end());
    if(*it == INT_MAX)
      return points;
    points.push_back(*it);
    int copy = *it;
    *it = INT_MAX;
    for(int i =0;i<n;i++)
    {
      if(end[i]!=INT_MAX && start[i]<=copy)
        end[i] = INT_MAX;

    }

  }
  

  return points;
}

int main() {
  int n;
  std::cin >> n;
  std::vector<int> start(n),end(n);
  for (size_t i = 0; i < start.size(); ++i) {
    std::cin >> start[i] >> end[i];
  }
  vector<int> points = optimal_points(start,end,n);
  std::cout << points.size() << "\n";
  for (size_t i = 0; i < points.size(); ++i) {
    std::cout << points[i] << " ";
  }
}
