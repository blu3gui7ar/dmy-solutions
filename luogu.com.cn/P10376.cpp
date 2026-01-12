#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
int dp[200050] = {};

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
    
    int from = min(c - a, c - b);

    for (int i = min(from, 1); i <= n; i++) {
        int base = (i <= c ? 1 : dp[i]);
        if (i + a > c && i + a <= n) {
            dp[i + a] = (dp[i + a] + base) % MOD;
        }
        if (i + b > c && i + b <= n) {
            dp[i + b] = (dp[i + b] + base) % MOD;
        }
        
        // cout << dp[i] << ' ';
        // if (i % 20 == 0) {
        //     cout << endl;
        // }
    }
    // cout << endl;
    
    cout << (n > c ? dp[n] : 1);
    return 0;
}