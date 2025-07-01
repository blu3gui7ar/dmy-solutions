#include <bits/stdc++.h>
using namespace std;
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
    for (int i = 0; i < T; i++) {
        int a, b, n, k;
        cin >> a >> b >> n >> k;

        if (a == b) {
            if (k % a == 0) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        }
        else {
            if ((k - b * n) % (a - b) == 0) {
                cout << "YES" << endl;
            }
            else {
                cout << "NO" << endl;
            }
        }
    }
    return 0;
}