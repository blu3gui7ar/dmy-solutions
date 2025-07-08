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
    
    string s;
    cin >> s;
    
    int num = 0;
    int i = 0;
    while(i < s.size()) {
        char c = s[i++];
        if (c == '1') {
            num += 1;
        } else if (c == '.') {
            cout << (num >> 1) << '.';
            break;
        }
        num <<= 1;
    }


    int base = 2;
    int TIMES = 1000;
    while(i < s.size()) {
        if (s[i] == '1') {
            num = TIMES / base;
            i++;
        } else if (s[i] == '0') {
            i++;
        }
        base <<= 1;
    }
    cout << num << endl;
    return 0;
}