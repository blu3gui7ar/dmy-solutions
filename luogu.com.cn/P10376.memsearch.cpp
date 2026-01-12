#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;

int cache[200050] = {};

ll dp(int i, int a, int b, int c) {
    if (i <= c) {
        return 1;
    }
    if (cache[i] != -1) {
        return cache[i];
    }
    
    cache[i] = (dp(i - a, a, b, c) + dp(i - b, a, b, c)) % MOD;
    
    return cache[i];
}

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
    
    memset(cache,-1,sizeof cache);

    int n, a, b, c;
    cin >> n >> a >> b >> c;
    
    
    cout << dp(n, a, b, c);

    return 0;
}