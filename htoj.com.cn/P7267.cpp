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
    
    int v[6] = {};
    for (int i = 1; i <= 5; i++) {
        cin >> v[i];
    }
    
    bool dp[110] = {};
    dp[0] = true;
    
    for (int i = 1; i <= 5; i++) {
        for (int j = 100; j >= v[i] ; j--) {
            dp[j] = dp[j] || dp[j - v[i]];
        }
    }
    
    for (int i = 100; i >= 1; i--) {
        if (dp[i]) {
            cout << i << endl;
            break;
        }
    }

    return 0;
}