#include <bits/stdc++.h>
using namespace std;
const long long MOD = 998244353;
vector<int> hp_input(istream& input) {
    string s;
    input >> s;
    vector<int> num;
    for (int i = static_cast<int>(s.size()) - 1; i >= 0; --i) {
        num.push_back(s[i] - '0');
    }
    return num;
}

long long hhp_mod(const vector<int>& a, long long b) {
    long long remainder = 0;
    for (int i = static_cast<int>(a.size()) - 1; i >= 0; --i) {
        remainder = remainder * 10 + a[i];
        remainder %= b;
    }
    return remainder;
}


// 快速幂取模
template<typename T> T power_mod(T base, T exp) {
    T result = 1;
    base %= MOD;
    while (exp > 0) {
        if (exp & 1) {
            result = (result * base) % MOD;
        }
        base = (base * base) % MOD;
        exp >>= 1;
    }
    return result;
}

int main () {
    vector<int> hp_n = hp_input(cin);
    long long k;
    cin >> k;
    
    // 使用欧拉定理降幂: a^b ≡ a^(b mod φ(MOD)) mod MOD (当a和MOD互质)
    // 由于MOD是质数，φ(MOD) = MOD-1
    long long n = hhp_mod(hp_n, MOD - 1);
    long long all = power_mod(k, n);
    long long illegal = power_mod(k - 1, n);
    
    long long legal = (all - illegal + MOD) % MOD;
    cout << legal << endl;
    return 0;
}