#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct box
{
  int wt;
  int val;
  double ratio;
};
bool comp(box one,box two)
{
  return one.ratio > two.ratio;
}
int main() {
  int n;
  int capacity;
  std::cin >> n >> capacity;
  box items[n];
  double d =0;
  for (int i = 0; i < n; i++) {
    std::cin >> items[i].val >> items[i].wt;
    d = items[i].wt;
    items[i].ratio = items[i].val/d;

  }
  sort(items,items +n,comp);

  double value = 0;
  int  k = 0;
  while(capacity > 0 && k < n)
  {
    value = value + (capacity<items[k].wt ? capacity:items[k].wt)*items[k].ratio;
    capacity -= items[k].wt;
    k++;
  }
  std::cout.precision(10);
  std::cout << value << std::endl;
  return 0;
}
