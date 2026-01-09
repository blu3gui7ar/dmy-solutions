#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
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
    
    int n, a, b, c;
    cin >> n >> a >> b >> c;
    
    int dp[200000] = {};
    
    for (int i = 1; i <= n; i++) {
        if (i == c) {
            dp[i] = 1;
        }
        if (i > c && i <= c + a) {
            dp[i] =  (dp[i] + 1) % MOD;
        }
        if (i > c && i <= c + b) {
            dp[i] =  (dp[i] + 1) % MOD;
        }

        if (i > c + a) {
            dp[i] = (dp[i - a] + dp[i]) % MOD;
        }
        if (i > c + b) {
            dp[i] = (dp[i - b] + dp[i]) % MOD;
        }
    }
    
    cout << dp[n];

    return 0;
}