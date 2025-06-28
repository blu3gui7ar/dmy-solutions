#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
int main (int argc, char const *argv[]) {
    if (argc > 1){
        if (argv[1][0] == '<') {
            freopen(argv[2], "r", stdin);
        } else {
            freopen(argv[1], "r", stdin);
        }
    }

    int n, m;
    cin >> n >> m;
    vector<int> a(m+1);
    for (int i = 1; i <= n; i++) {
        int color;
        cin >> color;
        if (a[color] == 0) {
            a[color] = i;
        }
    }
    
    sort(a.begin()+1, a.end());
    
    for (int i = 1; i <= m; i++) {
        if (a[i] != 0) {
            cout << a[i] << " ";
        }
    }
    cout << endl;
    return 0;
}