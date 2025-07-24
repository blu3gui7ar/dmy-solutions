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
    vector<vector<int>> a(n, vector<int>(n, 0));
    
    int k = 1;
    int i = 0, j = 0;
    int x = 1, y = 0;
    
    for (int k = 1; k <= n * n;) {
        if (i >= 0 && i < n && j >= 0 && j < n && a[i][j] == 0) {
            //valid position
            a[i][j] = k++;
            i += x;
            j += y;
        } else {
            //step back and go left
            i -= x;
            j -= y;
            if(x == 1 && y == 0) {
                x = 0;
                y = 1;
            } else if (x == 0 && y == 1) {
                x = -1;
                y = 0;
            } else if (x == -1 && y == 0) {
                x = 0;
                y = -1;
            } else if (x == 0 && y == -1) {
                x = 1;
                y = 0;
            }
            i += x;
            j += y;
        }
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