#include <iostream>
using namespace std;
long long fib(long long n, long long m) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    int num = 0;
    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous%m;
        previous = current%m;
        current = tmp_previous + current;
        current = current%m;
    }

    return current % m;
}
long long get_fibonacci_huge_naive(long long n, long long m) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    int num = 0;
    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous%m;
        previous = current%m;
        current = tmp_previous + current;
        current = current%m;
        if(previous == 0 && current == 1){
            num = i+1;
            break;
        }
    }
    if(num  != 0)
    {
        return fib(n%num,m);
    }
    


    return current % m;
}

int main() {
    long long n, m;
    std::cin >> n >> m;
    std::cout << get_fibonacci_huge_naive(n, m) << '\n';
}
