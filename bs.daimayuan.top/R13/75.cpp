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

    char seq[100];
    int end = 1;
    int pos[26] = {};
    for(int i = 1; i <= n; i++) {
        char c;
        cin >> c;
        int cpos = pos[c - 'a'];
        if (cpos > 0) {
            int cnt = 0;
            for (int j = 0; j < 26; j++) {
                if (cnt >= end - cpos) {
                    break;
                }
                if (pos[j] >= cpos) {
                    pos[j] = 0;
                    cnt++;
                }
            }
            end = cpos;
        } else {
            seq[end] = c;
            pos[c - 'a'] = end;
            end++;
        }
    }
    
    for(int i = 1; i < end; i++) {
        cout << seq[i];
    }
    cout << endl;

    return 0;
}