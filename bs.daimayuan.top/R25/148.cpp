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
    
    string a, b, b1 = "";
    cin >> a >> b;
    cout << a;
    
    bool leading_zero = true;
    for (auto it = b.rbegin(); it != b.rend(); it++) {
        char c = *it;
        if (c == '0' && leading_zero) {
            if (it == b.rend() - 1) {
                cout << c;
            }
            continue;
        }
        leading_zero = false;
        cout << c;
    }
    return 0;
}