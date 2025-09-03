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
    
    double x = (-1 + sqrt(1 + 8 * n)) / 2;
    int xi = static_cast<int>(x);
    
    
    int delta = n - xi * (xi + 1) / 2;

    if (delta == 0) {
        if (xi % 2 == 0) {
            cout << xi << '/' << 1 << endl;
        } else {
            cout << 1 << '/' << xi << endl; 
        }
    } else if (delta > 0){
        if (xi % 2 == 0) {
            cout << xi + 2 - delta << '/' << delta << endl;
        } else {
            cout << delta << '/' << xi + 2 - delta << endl;
        }
    } else {
        assert(false);
    }
    return 0;
}