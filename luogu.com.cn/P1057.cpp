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
    int a[40][40] = {0};
    a[0][1] = 1;
    a[0][n+1] = 1;
    for (int i = 1; i <= m; i++) {
        cout << a[i][0] << ' ';
        for (int j = 1; j <= n; j++) {
            a[i][j] = a[i - 1][j - 1] + a[i - 1][j + 1];
            cout << a[i][j] << ' ';
        }
        cout << a[i][n+1] << endl;
        a[i][0] = a[i-1][n];
        a[i][n+1] = a[i-1][1];
    }
    cout << a[m][1] << endl;
    return 0;
}