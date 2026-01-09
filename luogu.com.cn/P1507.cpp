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
    
    int H, T;
    cin >> H >> T;
    int n;
    cin >> n;
    int h[55] = {}, t[55] = {}, k[55] = {};
    for (int i = 1; i <= n; i++) {
        cin >> h[i] >> t[i] >> k[i];
    }
    
    int dp[450][450] = {};
    
    for (int i = 1; i <= n; i++) {
        for (int j = H; j >= h[i]; j--) {
            for (int l = T; l >= t[i]; l--) {
                dp[j][l] = max(dp[j][l], dp[j - h[i]][l - t[i]] + k[i]);
            }
        }
    }

    cout << dp[H][T];

    return 0;
}