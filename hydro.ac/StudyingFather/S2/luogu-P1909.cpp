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
    int a1, a2, b1, b2, c1, c2;
    cin >> n >> a1 >> a2 >> b1 >> b2 >> c1 >> c2;
    
    int a_cost = (n / a1 + (n % a1 > 0)) * a2;
    int b_cost = (n / b1 + (n % b1 > 0)) * b2;
    int c_cost = (n / c1 + (n % c1 > 0)) * c2;

    int min_cost = min(a_cost, min(b_cost, c_cost));
    cout << min_cost << endl;

    return 0;
}