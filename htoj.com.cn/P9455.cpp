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
    int a[25] = {}, b[25] = {}, bc[25] = {};
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }
    
    sort(a + 1, a + n + 1);
    sort(b + 1, b + n + 1);
    
    int p = 1, q = 1;
    while (p <= n && q <= n) {
        if (b[q] >= a[p]) {
            if (p < n) {
                bc[q] = p;
                p++;
            } else {
                bc[q] = n;
                q++;
            }
        } else {
            q++;
        }
    }
    
    ll ans = 1;
    for (int i = 1; i <= n; i++) {
        // cout << bc[i] << ' ';
        ans *= bc[i] - i + 1; 
    }
    // cout << endl;
    cout << ans << endl;

    return 0;
}