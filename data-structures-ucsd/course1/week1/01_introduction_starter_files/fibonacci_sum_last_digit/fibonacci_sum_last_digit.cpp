#include <iostream>
using namespace std;

long long int fibonacci_fast(int n) {
    // write your code here
    if(n <= 1)
        return n;
    long long int ans = 1;
    long long int prev = 1;
    for(int i =0 ;i<n-2;i++)
    {
        long long int temp = ans;
        ans = ans + prev;
        prev = temp;
    }
    return ans;
}
long long int fibonacci_sum_naive(long long int n) {

    int k =  fibonacci_fast(n+2) % 10;
    if(k == 0)
        return 9;
    return k-1;
}


int main() {
    long long n = 0;
    std::cin >> n;
    std::cout << fibonacci_sum_naive(n%60);
}
