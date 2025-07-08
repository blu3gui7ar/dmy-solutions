#include <bits/stdc++.h>
using namespace std;
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
    long A, B, C;
    cin >> n >> A >> B;
    C = min(A, B);

    
    vector<int> c(n + 1);
    vector<long long> dp(n + 1);
    c[0] = -1;
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> c[i];
    }
    
    int posa = 0; // dup c
    int posb = 0; // incr c
    for(int i = 1; i <= n; i++) {
        if (c[i] == c[i - 1]) {
            dp[i] = min(dp[posa] + A, dp[i - 1] + C);
            posb = i - 1;
        } else if (c[i] == c[i - 1] + 1) {
            dp[i] = min(dp[posb] + B, dp[i - 1] + C);
            posa = i - 1;
        } else {
            dp[i] = dp[i - 1] + C;
            posa = posb = i - 1;
        }
    }
    
    cout << dp[n] << endl;
    return 0;
}