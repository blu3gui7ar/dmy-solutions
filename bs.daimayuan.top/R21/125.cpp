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
    
    int n, k;
    cin >> n >> k;
    ll l = 1LL << n;
    k--;
    ll g = l >> k;
    ll p = 1LL << k;
    cout << g << endl;
    for (ll i = 0; i < g; i++) {
        int max = 0;
        int maxi = 0;
        for(ll j = 1; j <= p; j++) {
            int f;
            cin >> f;
            if (f > max) {
                max = f;
                maxi = i * p + j;
            }
        }
        cout << maxi << ' ';
    }
    cout << endl;

    return 0;
}