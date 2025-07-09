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
    
    unsigned long long num = 0;
    int i = 0;
    while(i < s.size()) {
        char c = s[i++];
        if (c == '.') {
            cout << (num >> 1) << '.';
            break;
        } else {
            num += c - '0';
        }
        num <<= 1;
    }

    int base = 2;
    int TIMES = 1000;
    num = 0;
    while(i < s.size()) {
        char c = s[i++];
        num += (c - '0') * TIMES / base;
        base <<= 1;
    }
    if (num == 0) {
        cout << "000" << endl;
    } else {
        cout << num << endl;
    }
    return 0;
}