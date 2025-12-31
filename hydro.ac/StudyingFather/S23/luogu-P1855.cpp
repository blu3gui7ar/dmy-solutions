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
    
    /**
     * 二维费用背包
     */
    int n, M, T;
    cin >> n >> M >> T;
    int t[110], m[110];

    for(int i = 1; i <= M; i++) {
        cin >> m[i] >> t[i];
    }
    
    int dp[210][210] = {};
    for(int i = 1; i <= n; i++) {
        for(int j = T; j >= t[i]; j--) {
            for (int k = M; k >= m[i]; k--) {
                dp[j][k] = max(dp[j][k], dp[j - t[i]][k - m[i]] + 1);
            }
        }
    }

    cout << dp[T][M] << endl;
    return 0;
}