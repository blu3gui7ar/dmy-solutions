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
    ll rs = 0;
    for(int i = 0; i < n; i++) {
        char c;
        cin >> c;
        if (c == '1') {
            rs += 1LL;
        }
    }
    
    cout << rs * ((1LL << n) - 1) << endl;

    return 0;
}