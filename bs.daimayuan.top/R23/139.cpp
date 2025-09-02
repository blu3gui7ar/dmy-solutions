#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 998244353;

long long sqrt_newton(long long x) {
    if (x <= 1) return x;  // 处理0和1的特殊情况
    
    // 初始猜测值，选择x/2作为起点
    long long guess = x / 2;
    // 牛顿迭代：guess = (guess + x/guess)/2
    while (guess > x / guess) {  // 当guess² > x时继续迭代
        guess = (guess + x / guess) / 2;
    }
    return guess;
}

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
    
    int T;
    cin >> T;
    while (T--) {
        ll x;
        cin >> x;
        
        ll r = sqrt_newton(x);
        ll shift = x - r * r;

        if (shift == 0) {
            cout << r << " " << r << endl;
        } else {
            ll col = (shift - 1) % r + 1;
            if (col == 0) col = r;
            ll row = (shift - 1) / r + 1 + 2 * r - col;
            cout << row << " " << col << endl;
        }
    }

    return 0;
}