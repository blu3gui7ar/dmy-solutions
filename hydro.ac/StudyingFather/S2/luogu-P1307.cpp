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

    if (n == 0) {
        cout << 0 << endl;
        return 0;
    }
    
    if (n < 0) {
        cout << '-';
        n = -n;
    }
    
    bool zero = true;
    while (n > 0) {
        int b = n % 10;
        n /= 10;
        if ( b!=0 || !zero ) {
            zero = false;
            cout << b;
        }
    }

    return 0;
}