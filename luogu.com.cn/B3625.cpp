#include <bits/stdc++.h>
using namespace std;
int n, m;
char a[110][110];
int dp[110][110] = {};
void print_dp() {
    for (int i = 0; i <= n + 1; ++i) {
        for (int j = 0; j <= m + 1; ++j) {
            cout << dp[i][j];
        }
        cout << endl;
    }
}
void print_a() {
    for (int i = 0; i <= n + 1; ++i) {
        for (int j = 0; j <= m + 1; ++j) {
            cout << a[i][j];
        }
        cout << endl;
    }
}

int main () {
    cin >> n >> m;
    for (int i = 0; i <= n + 1; i++) {
        for (int j = 0; j <= m + 1; j++) {
            if (i == 0 || j == 0 || i > n || j > m) {
                a[i][j] = '#';
            } else {
                cin >> a[i][j];
            }
        }
    }
    // print_a();

    dp[1][1] = 1;
    for (int k = 1; k <= n * m ;k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (dp[i][j] == k) {
                    if (a[i - 1][j] != '#' && dp[i - 1][j] == 0) {
                        dp[i - 1][j] = k + 1;
                        if (i - 1 == n && j == m) {
                            // print_dp();
                            cout << "Yes";
                            return 0;
                        }
                    }
                    if (a[i][j - 1] != '#' && dp[i][j - 1] == 0) {
                        dp[i][j - 1] = k + 1;
                        if (i == n && j - 1 == m) {
                            // print_dp();
                            cout << "Yes";
                            return 0;
                        }
                    }
                    if (a[i + 1][j] != '#' && dp[i + 1][j] == 0) {
                        dp[i + 1][j] = k + 1;
                        if (i + 1 == n && j == m) {
                            // print_dp();
                            cout << "Yes";
                            return 0;
                        }
                    }
                    if (a[i][j + 1] != '#' && dp[i][j + 1] == 0) {
                        dp[i][j + 1] = k + 1;
                        if (i == n && j + 1 == m) {
                            // print_dp();
                            cout << "Yes";
                            return 0;
                        }
                    }
                }
            }
        }
    }

    if(dp[n][m] == 0) {
        cout << "No";
    } else {
        cout << "Yes";
    }
    return 0;
}