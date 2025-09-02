#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 998244353;

ll fact[1005], inv[1005];

ll qpow(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

void init() {
    fact[0] = 1;
    for (int i = 1; i <= 1000; i++) {
        fact[i] = fact[i-1] * i % MOD;
    }
    inv[1000] = qpow(fact[1000], MOD-2);
    for (int i = 999; i >= 0; i--) {
        inv[i] = inv[i+1] * (i+1) % MOD;
    }
}

ll C(int n, int m) {
    if (n < m || m < 0) return 0;
    return fact[n] * inv[m] % MOD * inv[n-m] % MOD;
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
    
    init();
    int n, m, k;
    cin >> n >> m >> k;
    
    ll res = 0;
    for (int t = 1; t <= m; t++) {
        for (int s = 0; s <= n/k; s++) {
            ll sign = (s % 2 == 0) ? 1 : -1;
            ll ways = C(m, t) * C(t, s) % MOD;
            ll cnt = C(n - s*k + t - 1, t - 1) % MOD;
            res = (res + sign * ways * cnt % MOD + MOD) % MOD;
        }
    }
    
    cout << res << endl;
    return 0;
}