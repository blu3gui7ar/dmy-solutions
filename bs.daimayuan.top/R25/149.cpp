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
    vector<string> s;
    cin >> n;
    size_t last_len = ULLONG_MAX;
    for (int i = 0; i < n; i++){
        string str;
        cin >> str;
        size_t len = str.size();
        if (len > last_len) {
            cout << "No" << endl;
            return 0;
        } else {
            last_len= len;
        }
        s.push_back(str);
    }
    
    cout << "Yes" << endl;
    if (!s.empty()) {
        size_t max_len = s[0].size();
        for (size_t i = 0; i < max_len; i++){
            for (size_t j = 0; j < s.size(); j++){
                if (i < s[j].size()) {
                    cout << s[j][i];
                }
            }
            cout << endl;
        }
    }

    return 0;
}