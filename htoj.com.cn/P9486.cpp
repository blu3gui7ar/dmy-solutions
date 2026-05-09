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
    int c[100010] = {};
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> c[i];
    }
    
    sort(c + 1, c + n + 1);


    // for (int i = 1; i <= n; ++i) {
    //     cout << c[i] << ' ';
    // }
    // cout << endl;

    for (int i = n; i >= 1; i--) {
        if(c[n - i + 1] >= i) {
            cout << i;
            break;
        }
    }
    return 0;
}