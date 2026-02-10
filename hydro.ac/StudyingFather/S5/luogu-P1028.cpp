#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 998244353;

int cache[1000] = {};

int valid(int n) {
    if (cache[n] != 0) {
        return cache[n];
    }

    if (n == 1) return 1;
    int cnt = 1;
    for (int i = 1; i <= n / 2; ++i) {
        cnt += valid(i);
        
    }
    cache[n] = cnt;
    return cnt;
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

    int n;
    cin >> n;

    cout << valid(n);

    return 0;
}
