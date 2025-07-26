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
    vector<vector<int>> a(n + 2, vector<int>(n + 2, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        int begin = 0;
        vector<int> parts;
        for (int j = 1; j <= n + 1; j++) {
            if (a[i][j] == 1 && a[i][j - 1] == 0) {
                begin = j;
            } else if (a[i][j] == 0 && a[i][j - 1] == 1) {
                parts.push_back(j - begin);
            }
        }
        cout << parts.size();
        for(auto part : parts) {
            cout << " " << part;
        }
        cout << endl;
    }
    for (int j = 1; j <= n; j++) {
        int begin = 0;
        vector<int> parts;
        for (int i = 1; i <= n + 1; i++) {
            if (a[i][j] == 1 && a[i - 1][j] == 0) {
                begin = i;
            } else if (a[i][j] == 0 && a[i - 1][j] == 1) {
                parts.push_back(i - begin);
            }
        }
        cout << parts.size();
        for(auto part : parts) {
            cout << " " << part;
        }
        cout << endl;
    }
    return 0;
}