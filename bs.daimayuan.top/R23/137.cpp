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
    
    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        
        int ones = 0;
        int zeros = 0;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            if (x == 1) {
                ones++;
            } else {
                zeros++;
            }
        }
        
        if (k < ones) {
            cout << "No" << endl;
        } else {
            if ((k - ones) % 2 == 0) {
                cout << "Yes" << endl;
            } else {
                cout << "No" << endl;
            }
        }
    }

    return 0;
}