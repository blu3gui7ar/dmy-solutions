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
    unordered_set<int> a(n);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a.insert(x);
    }
    
    unordered_set<int> r;
    for (auto x : a) {
        for (auto y : a) {
            if (x != y && a.find(x + y) != a.end()) {
                r.insert(x + y);
            }
        }
    }
    
    cout << r.size() << endl;
    
    return 0;
}