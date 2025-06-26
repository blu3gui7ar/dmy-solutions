#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MOD = 998244353;

// 高精度字符串转数字取模
int str_mod(const string& s, int mod) {
    int res = 0;
    for (char c : s) {
        res = (res * 10LL + (c - '0')) % mod;
    }
    return res;
}

// 快速幂 (a^b mod MOD)
long long power(long long a, long long b) {
    long long res = 1;
    a %= MOD;
    while (b > 0) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

int main() {
    string n_str;
    int k;
    cin >> n_str >> k;
    
    if (k == 1) {
        cout << 1 << endl;
        return 0;
    }
    
    // 使用欧拉定理降幂: a^b ≡ a^(b mod φ(MOD)) mod MOD (当a和MOD互质)
    // 由于MOD是质数，φ(MOD) = MOD-1
    long long n_mod = str_mod(n_str, MOD-1);
    long long total = power(k, n_mod);
    long long invalid = power(k - 1, n_mod);
    long long ans = (total - invalid + MOD) % MOD;
    
    cout << ans << endl;
    return 0;
}
