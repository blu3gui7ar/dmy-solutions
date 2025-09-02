#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 998244353;

template<typename T> T gcd(T a, T b) {
    if (a < 0) a = -a;  // 处理负数
    if (b < 0) b = -b;  // 处理负数
    // 递归终止条件：当b为0时，a就是GCD
    // 否则继续计算gcd(b, a % b)
    return b == 0 ? a : gcd(b, a % b);
}

template<typename T> map<T, T> factorize(T n) {
    map<T, T> factors;
    if (n < 2) return factors;  // 小于2的数没有质因数
    
    for (T i = 2; i * i <= n; ++i) {
        if (n % i == 0) {       // 发现一个质因数
            factors[i] = 0;     // 初始化幂次为0
            while (n % i == 0) { // 计算该质因数的幂次
                n /= i;
                factors[i]++;   // 幂次加1
            }
        }
    }
    
    if (n > 1) factors[n] = 1; // 处理最后剩下的质数
    return factors;
}

int main (int argc, char const *argv[]) {
    // ios_base::sync_with_stdio(false);
    // cin.tie(nullptr);
    // solve the io redirect problem for vscode
    if (argc > 1){
        if (argv[1][0] == '<') {
            freopen(argv[2], "r", stdin);
        } else {
            freopen(argv[1], "r", stdin);
        }
    }
    
    int T;
    cin >> T;
    while (T--) {
        ll X, Y;
        cin >> X >> Y;
    
        map<ll, ll> factors = factorize(X);
        map<ll, ll> y_factors = factorize(Y);
        
        for (auto it = y_factors.begin(); it != y_factors.end(); ++it) {
            if(factors.count(it->first)) {
                factors[it->first] += it->second;
            } else {
                factors[it->first] = it->second;
            }
        }

        ll a = 1;
        ll b= 0;
        for (auto it = factors.begin(); it != factors.end(); ++it) {
            ll b1 = it->second;
            if (b == 0) {
                b = b1;
            } else {
                b = gcd(b, b1);
            }
        }
        for (auto it = factors.begin(); it != factors.end(); ++it) {
            ll t = it->second / b;
            for (ll i = 0; i < t; i++) {
                a *= it->first;
            }
        }
        
        cout << a << " " << b << endl;
    }

    return 0;
}