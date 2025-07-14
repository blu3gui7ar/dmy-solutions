#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

template<typename T> T gcd(T a, T b) {
    if (a < 0) a = -a;  // 处理负数
    if (b < 0) b = -b;  // 处理负数
    // 递归终止条件：当b为0时，a就是GCD
    // 否则继续计算gcd(b, a % b)
    return b == 0 ? a : gcd(b, a % b);
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
    
    int n;
    cin >> n;
    while(n--) {
        ll X, Y;
        cin >> X >> Y;
        
        /*
        $$
        \begin{align}
        A - B = X \\
        \frac{lcm(A, B)}{gcd(A, B)} = Y \\

        A = gcd(A, B) * a \\
        B = gcd(A, B) * b \\
        
        a - b = X / gcd(A, B) \\
        a * b = Y

        \end{align}
        
        $$
        思路: Y分解因数成a * b, 求可能的gcd(A, B)
        */
        
        vector<pair<ll, ll>> rs;
        for (ll b = 1; b * b <= Y; ++b) {
            if (Y % b != 0) {
                continue;
            } 
            ll a = Y / b; 
            if (a == b) {
                continue;
            } else {
                if (gcd(a, b) != 1) {
                    continue;
                } 
                
                if (X % (a - b) == 0) {
                    ll gcd = X / (a - b);
                    rs.push_back(make_pair(gcd * a, gcd * b));
                }
            }
        }
        sort(rs.begin(), rs.end(), [](pair<int, int> a, pair<int, int> b) { return a.first < b.first;});
        cout << rs.size() << endl;
        for (auto it = rs.begin(); it != rs.end(); ++it) {
            cout << it->first << " " << it->second << endl;
        }
    }

    return 0;
}