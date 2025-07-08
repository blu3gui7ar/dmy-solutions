#include <bits/stdc++.h>
using namespace std;
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
        int a, b;
        cin >> a >> b;

        int zeros = min(a, b);
        int twos[] = {1, 2, 4, 8, 16, 32, 64, 128};
        int fives[] = {1, 5, 25, 125, 625, 3125, 15625, 78125};

        if (a > b) {
            cout << twos[a - b];
        } else if (b > a) {
            cout << fives[b - a];
        } else {
            cout << 1;
        }
        
        for (int i = 0; i < zeros; i++) {
            cout << '0';
        }
        
        cout << endl;
    }

    return 0;
}