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

    int n;
    cin >> n;
    int v[110] = {};
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }
    
    bool dp[110] = {};
    dp[0] = true;

    for (int i = 1; i <= n; i++) {
        for (int j = 100; j >= v[i]; j--) {
            dp[j] = dp[j] || dp[j - v[i]];
        }
    }
    
    int cnt = 0;
    for (int i = 1; i <= 100; i++) {
        if (!dp[i]) {
            cnt++;
        }
    }
    cout << cnt << endl;

    return 0;
}