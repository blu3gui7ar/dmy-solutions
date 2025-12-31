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
    
    int m, n;
    cin >> m >> n;
    
    int a[1010] = {}, b[1010] = {};
    int groups[1010][1010] = {};
    int group_cnt[1010] = {};
    int max_group = 0;

    for (int i = 1; i <= n; i++) {
        int c;
        cin >> a[i] >> b[i] >> c;
        int cnt = ++group_cnt[c];
        groups[c][cnt] = i;
        if (max_group < c) {
            max_group = c;
        }
    }
    
    int dp[1010] = {};
    
    for(int g = 1; g <= max_group; g++) {
        for (int i = m; i >= 0; i--) {
            for (int j = 1; j <= group_cnt[g]; j++) {
                if (i >= a[groups[g][j]]) {
                    dp[i] = max(dp[i], dp[i - a[groups[g][j]]] + b[groups[g][j]]);
                }
            }
        }
    }
    
    cout << dp[m] << endl;
    return 0;
}