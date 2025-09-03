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
    
    int save = 0;
    int inhand = 0;
    int pre = 0;
    for (int i = 0; i < 12; i++) {
        cin >> pre;
        inhand += 300;
        inhand -= pre;
        
        if (inhand < 0) {
            cout << -(i + 1) << endl;
            return 0;
        }
        
        save += inhand / 100 * 100;
        inhand %= 100;
    }
    cout << inhand + save * 1.2 << endl;

    return 0;
}