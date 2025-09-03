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
    

    for (int i = 123; i <= 987 / 3; i++) {
        bool valid = true;
        bool flag[11] = {false};
        for (int n = i; n <= i * 3; n += i) {
            for (int m = n; m > 0; m /= 10) {
                if (m % 10 == 0 || flag[m % 10]) {
                    valid = false;
                    break;
                } else {
                    flag[m % 10] = true;
                }
            }
        }
        if (!valid) {
            continue;
        } else {
            cout << i << ' ' << i * 2 << ' ' << i * 3 << endl;
        }
    }

    return 0;
}