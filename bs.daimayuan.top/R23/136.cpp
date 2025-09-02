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
    
    char c[16];
    for(int i = 0; i < 16; i++) {
        cin >> c[i];
    }

    string s;
    cin >> s;
    for(int i = 0; i < s.size(); i++) {
        if (s[i] >= '0' && s[i] <= '9') {
            cout << c[s[i] - '0'];
        } else {
            cout << c[s[i] - 'A' + 10];
        }
    }

    return 0;
}