#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353;

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int main() {
    int n, m;
    cin >> n >> m;
    
    long long sum = 0;
    long long sum_n = 0, sum_m = 0;
    
    // 计算sum_n = ∑gcd(i,n) for i=1 to n
    for (int i = 1; i <= n; i++) {
        sum_n += gcd(i, n) % MOD;
    }
    
    // 计算sum_m = ∑gcd(j,m) for j=1 to m
    for (int j = 1; j <= m; j++) {
        sum_m += gcd(j, m) % MOD;
    }
    
    // 总和是sum_n * sum_m mod MOD
    sum = (sum_n % MOD) * (sum_m % MOD) % MOD;
    
    cout << sum << endl;
    return 0;
}