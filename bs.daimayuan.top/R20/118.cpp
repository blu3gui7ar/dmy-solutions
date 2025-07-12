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
    vector<vector<char>> a(n+1, vector<char>(m+1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }
    
    int Q;
    cin >> Q;
    while(Q--) {
        int t, l, r, k;
        cin >> t >> l >> r >> k;
        
        if (t == 1) { 
            k %= m;
            vector<char> tmp(m+1);
            for (int i = l; i <= r; i++) {
                for (int j = 1; j <= m; j++) {
                    int from = j > k ? j - k : m + j - k;
                    tmp[j] = a[i][from];
                }
                a[i] = tmp;
            }
        } else if (t == 2) {
            k %= n;
            vector<char> tmp(n+1);
            for (int j = l; j <= r; j++) {
                for (int i = 1; i <= n; i++) {
                    int from = i > k ? i - k : n + i - k;
                    tmp[i] = a[from][j];
                }
                for (int i = 1; i <= n; i++) {
                    a[i][j] = tmp[i];
                }
            }
        } else {
            assert(false);
        }
    }
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cout << a[i][j];
        }
        cout << endl;
    }
    return 0;
}