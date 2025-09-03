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

    int n, x;
    cin >> n >> x;
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        int k = i;
        while (k > 0) {
            if (k % 10 == x) {
                cnt++;
            }
            k /= 10;
        }
    }
    cout << cnt << endl;

    return 0;
}