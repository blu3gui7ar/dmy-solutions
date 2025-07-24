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
    
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n));
    
    int k = 1;
    for(int loop = 0; loop <= n / 2; loop++) {
        for (int i = loop; i < n - loop - 1; i++) {
            a[i][loop] = k++;
        }
        for (int j = loop; j < n - loop - 1; j++) {
            a[n - loop - 1][j] = k++;
        }
        for (int i = n - loop - 1; i > loop; i--) {
            a[i][n - loop - 1] = k++;
        }
        for (int j = n - loop - 1; j > loop; j--) {
            a[loop][j] = k++;
        }
    }
    if (n % 2 == 1) {
        a[n / 2][n / 2] = k++;
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (j == 0) {
                cout << a[i][j];
            } else {
                cout << ' ' << a[i][j];
            }
        }
        cout << endl;
    }

    return 0;
}