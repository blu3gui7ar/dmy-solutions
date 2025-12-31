#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000007;
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
    
    int n, m;
    cin >> n >> m;
    int w[55] = {};
    for (int i = 1; i <= n; i++) {
        cin >> w[i];
    }

    int dp[10010] = {};
    dp[0] = 1;
    
    for (int i = 1; i <= n; i++) {
        for (int j = m; j >= w[i]; j--) {
            dp[j] += dp[j - w[i]] % MOD;
            dp[j] %= MOD;
        }
        // for (int i = 1; i <= m; i++) {
        //     cout << dp[i];
        // }
        // cout << endl;
    }
    
    int sum = 1;
    for (int i = 1; i <= m; i++) {
        sum = (sum + dp[i]) % MOD;
    }

    cout << sum << endl;
    return 0;
}