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
    
    string isbn;
    getline(cin, isbn);
    
    int i = 1;
    int code = 0;
    for (char c : isbn) {
        if (c == '-') {
            continue;
        } else if (i <= 9) {
            code += (c - '0') * i++;
        } else {
            int m = code % 11;
            if (m == 10) {
                if (c == 'X') {
                    cout << "Right" << endl;
                } else {
                    cout << isbn.substr(0, isbn.size() - 1) << "X" << endl;
                }
            } else {
                if (m == c - '0') {
                    cout << "Right" << endl;
                } else {
                    cout << isbn.substr(0, isbn.size() - 1) << m << endl;
                }
            }
            break;
        }
    }
    
    return 0;
}