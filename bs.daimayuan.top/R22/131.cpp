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
        int n;
        cin >> n;
        int status = 0;
        for(int i = 0; i < n; i++) {
            int a;
            cin >> a;
            if (a % 2 == 1) {
                if (status == 0) {
                    status = 1;
                } else if (status == 3) {
                    status = 4;
                }
            } else if (a % 2 == 0) {
                if (status == 1) {
                    status = 2;
                } else if (status == 2) {
                    status = 3;
                }
            } else {
                assert(false);
            }
        }
        
        if (status == 4) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }

    return 0;
}