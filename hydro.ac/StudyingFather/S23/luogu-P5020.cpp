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
    
    int T;
    cin >> T;
    for (int i = 1; i <= T; i++) {
        int n;
        cin >> n;
        int a[110];
        for (int j = 1; j <= n; j++) {
            cin >>  a[j];
        }
        sort(a + 1, a + n + 1, [](int &x, int &y) {
            return x < y;
        });
        int max_a = a[n];
        // for (int k = 1; k <= n; k++) {
        //     cout << a[k] << ", ";
        // }
        // cout << endl;
        
        int required = 0;
        bool dp[25010] = {};
        for (int p = 1; p <= n; p++) {
            if(!dp[a[p]]) {
                dp[a[p]] = true;
                required++;
                for (int q = a[p] + 1; q <= max_a; q++) {
                    dp[q] = dp[q] || dp[q - a[p]];
                }
            }
        }
        
        cout << required << endl;
    }
    
    return 0;
}