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
    
    string s;
    cin >> s;

    int cd = 0, cm = 0, cy = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'd') {
            cd++;
        } else if (s[i] == 'm') {
            cm++;
        } else if (s[i] == 'y') {
            cy++;
        }
    }
    cout << cd << ' ' << cm << ' ' << cy << endl;

    return 0;
}