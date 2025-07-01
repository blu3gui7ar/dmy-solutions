#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353;

long dp(int n, int m, int limit) {
    long count = 0;
    if (n == 1 || m == n) {
        count = 1L;
    } else {
        int to = m - n + 1;
        int from = max(m / n + m % n, limit);
        for (int i = from; i <= to; i++) {
            count = (count + dp(n - 1, m - i, i)) % MOD;
        }
    }
    cout << n << ":" << m << " = " << count << endl;
    return count;
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

    int T;
    cin >> T;
    for(int i = 0; i < T; i++) {
        int n, m;
        cin >> n >> m;
        // vector<vector<long>> solutions = init(n, m);
        // cout << solutions[n][m] << endl;
        cout << dp(n, m, 1) << endl;
    }
    return 0;
}