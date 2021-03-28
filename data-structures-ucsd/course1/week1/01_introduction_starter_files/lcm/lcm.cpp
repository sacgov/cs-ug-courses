#include <iostream>
using namespace std;

int gcd_naive(int a, int b) {
  if(b == 0)
    return a;
  else
    return gcd_naive(b,a%b);
}
long long int lcm_naive(int a, int b) 
{ 
	long long int g = gcd_naive(a,b);
	long long int k = a;
	long long int k2 = b;
	k = k*k2;
	k = k/g;
	return k;
  
}



int main() {
  int a, b;
  std::cin >> a >> b;
  std::cout << lcm_naive(a, b) << std::endl;
  return 0;
}
