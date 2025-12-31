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

    int T, M;
    cin >> T >> M;
    int w[1010], v[1010];
    for(int i = 1; i <= M; i++) {
        cin >> w[i] >> v[i];
    }

    int dp[1010] = {};
    dp[0] = 0;
    for(int i = 1; i <= M; i++) {
        for (int j = T; j >= w[i]; j--) {
            dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
        }
    }

    cout << dp[T] << endl;
    return 0;
}