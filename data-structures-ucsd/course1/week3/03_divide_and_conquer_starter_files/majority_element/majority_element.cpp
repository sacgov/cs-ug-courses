#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using std::vector;

int get_majority_element(vector<int> &a, int left, int right) {
  int count = 1;
  int index = 0;
  for(int i=1;i<right;i++)
  {
    if(a[i] == a[index])
      count++;
    else
    {
      count--;
    }
    if(count == 0)
    {
      index = i;
      count = 1;
    }
  }
  //cout<<a[index];
  count  = 0;
  for(int i=0;i<right;i++)
    if(a[index] == a[i])
      count++;
  if(count > (right/2))
    return 1;
  else
  return 0;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  std::cout << get_majority_element(a, 0, a.size()) << '\n';
}
