#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
using namespace std;
using std::vector;
using std::swap;



int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
 }
  sort(a.begin(), a.end());
  for (size_t i = 0; i < a.size(); ++i) {
    std::cout << a[i] << ' ';
  }
}
