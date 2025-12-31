#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 998244353;
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
    int v[30], p[30];
    for(int i = 1; i <= m; i++) {
        cin >> v[i] >> p[i];
    }
    
    int dp[30010] = {};
    dp[0] = 0;
    
    for (int i = 1; i <= m; i++) {
        for (int j = n; j >= v[i]; j--) {
            dp[j] = max(dp[j], dp[j - v[i]] + v[i] * p[i]);
        }
    }

    cout << dp[n] << endl;
    return 0;
}