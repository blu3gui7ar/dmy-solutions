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
    
    int n;
    cin >> n;

    string s;
    cin >> s;
    // for(int i = 0; i < n; i++) {
    //     cin >> s[i];
    // }

    int Q;
    cin >> Q;

    while(Q--) {
        int x; 
        char c;
        cin >> x >> c;
        int pos = -1;
        for(int i = 0; i < x; i++) {
            pos = s.find(c, pos+1);
        }
        s.erase(pos, 1);
        s.insert(s.begin(), c);
        // cout << s << endl;
    }

    cout << s << endl;
    return 0;
}