#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
int main () {
    int n, m;
    cin >> n >> m;
    int a[m+1] = {0};
    for (int i = 1; i <= n; i++) {
        int color;
        cin >> color;
        if (a[color] == 0) {
            a[color] = i;
        }
    }
    
    sort(a+1, a+m+1);
    
    for (int i = 1; i <= m; i++) {
        if (a[i] != 0) {
            cout << a[i] << " ";
        }
    }
    cout << endl;
    return 0;
}