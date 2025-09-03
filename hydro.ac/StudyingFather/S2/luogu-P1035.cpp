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
    
    
    int k;
    cin >> k;

    double sum = 0;
    int i = 1;
    for (; sum - k <= 0; i++ ){
        sum += 1.0 / i;
        // cout << setprecision(9) << sum << "," << i << ": " << sum - k << endl;
    }
    
    cout << i - 1 << endl;

    return 0;
}