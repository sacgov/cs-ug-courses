#include <iostream>
#include <vector>
using std::vector;
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
long long get_fibonacci_partial_sum_naive(long long from, long long to) {
    int one = fibonacci_sum_naive(from%60);
    int two = fibonacci_sum_naive(to%60);
    //cout<<two<<" "<<one;
    two = two - one;
    if(two < 0)
        two = 10 + two;
    return two;
}

int main() {
    long long from, to;
    std::cin >> from >> to;
    std::cout << get_fibonacci_partial_sum_naive(--from, to) << '\n';
}
