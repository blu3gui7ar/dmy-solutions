#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 998244353;


int floodfill(size_t i, size_t j, vector<vector<int>>& a, vector<vector<int>>& h, int step) {
    if (i < 0 || i >= a.size() || j < 0 || j >= a[0].size()) {
        return step;
    }

    if (h[i][j] < step) {
        h[i][j] = step;

        int m = step;

        if (i > 0 && a[i][j] < a[i - 1][j]) {
            m = max(m, floodfill(i - 1, j, a, h, step + 1));
        }
        if (i < a.size() - 1 && a[i][j] < a[i + 1][j]) {
            m = max(m, floodfill(i + 1, j, a, h, step + 1));
        }
        if (j > 0 && a[i][j] < a[i][j - 1]) {
            m = max(m, floodfill(i, j - 1, a, h, step + 1));
        }
        if (j < a[0].size() - 1 && a[i][j] < a[i][j + 1]) {
            m = max(m, floodfill(i, j + 1, a, h, step + 1));
        }
        return m;
    } else {
        return h[i][j];
    }
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
    
    int R, C;
    cin >> R >> C;
    vector<vector<int>> a(R, vector<int>(C));
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> a[i][j];
        }
    }

    int mm = 0;
    vector<vector<int>> h(R, vector<int>(C, 0));
    for (size_t i = 0; i < R; i++) {
        for (size_t j = 0; j < C; j++) {
            mm = max(mm, floodfill(i, j, a, h, 1));
        }
    }
    
    cout << mm;
    return 0;
}