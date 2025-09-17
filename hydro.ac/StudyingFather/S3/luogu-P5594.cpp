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
    
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> matches(k, vector<int>(m, 0));
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int a;
            cin >> a;
            matches[a-1][j] = 1;
        }
    }
    
    for (int i = 0; i < k; i++) {
        int m = accumulate(matches[i].begin(), matches[i].end(), 0);
        cout << m << ' ';
    }
    
    return 0;
}