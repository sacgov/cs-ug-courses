#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
    int n;
    cin >> n;
    vector<int> numbers(n);
    for (int i = 0; i < n; ++i) {
        cin >> numbers[i];
    }
    sort(numbers.begin(),numbers.end());
    long long int a,b;
    a = numbers[n-2];
    b = numbers[n-1];
    long long int result = a*b;
    long long result2= numbers[0]*numbers[1];
    cout << (result>result2 ? result:result2 )<< "\n";
    return 0;
}
