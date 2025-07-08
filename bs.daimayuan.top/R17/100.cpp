#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
const int MAXN = 100000;

int main(int argc, char const* argv[]) {
    // ios_base::sync_with_stdio(false);
    // cin.tie(nullptr);
    // solve the io redirect problem for vscode
    if (argc > 1) {
        if (argv[1][0] == '<') {
            freopen(argv[2], "r", stdin);
        }
        else {
            freopen(argv[1], "r", stdin);
        }
    }

    int n;
    cin >> n;
    long long a[MAXN + 1] = {};
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    long long maxx[MAXN + 1] = {};
    long long minx[MAXN + 1] = {};

    maxx[0] = 0;
    minx[0] = 0;
    for (int i = 1; i <= n; i++) {
        maxx[i] = max(maxx[i - 1], 2 * a[i] - minx[i - 1]);
        minx[i] = min(minx[i - 1], 2 * a[i] - maxx[i - 1]);
    }

    cout << maxx[n] << endl;
    return 0;
}