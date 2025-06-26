#include <bits/stdc++.h>
using namespace std;

// 计算最大公约数
long long gcd(long long a, long long b) {
    return b == 0 ? a : gcd(b, a % b);
}

// 获取一个数的所有因数
vector<long long> getFactors(long long n) {
    vector<long long> factors;
    for (long long i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            factors.push_back(i);
            if (i != n / i) {
                factors.push_back(n / i);
            }
        }
    }
    return factors;
}

int main () {
    long long a, b;
    cin >> a >> b;
    
    long long g = gcd(a, b);
    vector<long long> commonDivisors = getFactors(g);
    
    long long sum = accumulate(commonDivisors.begin(), commonDivisors.end(), 0LL);
    cout << sum << endl;
    
    return 0;
}