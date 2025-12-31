#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 998244353;

int main(int argc, char const* argv[]) {
    // ios_base::sync_with_stdio(false);
    // cin.tie(nullptr);
    // solve the io redirect problem for vscode
    if (argc > 1) {
        if (argv[1][0] == '<') {
            freopen(argv[2], "r", stdin);
        }
        else {
            freopen(argv[1], "r", stdin);
        }
    }
    
    /**
     * 等价问题：
     * 
     * 容量为n的背包，有n种物品，第i种物品重量为i，价值为a[i]
     * 
     * 物品个数无限（容易为n限制了总物品数量），完全背包
     */
    int n;
    cin >> n;
    int a[1010] = {};
    int dp[1010] = {}; // dp[i] 表示背包容量为i时的最大价值
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    
    // for (int i = 1; i <= n; i++) { // 枚举第i种物品
    //     for (int j = 0; j <= n; j++) { // 枚举背包容量
    //         for (int k = 1; k * i <= n; k++) {
    //             dp[j + k * i] = max(dp[j + k * i], dp[j] + k * a[i]);
    //         }
    //     }
    // }

    //优化版完全背包
    for (int i = 1; i <= n; i++) { // 枚举第i种物品
        for (int j = i; j <= n; j++) { // dp[j - i * k] 在前序计算中已经优化，可以直接使用
            dp[j] = max(dp[j], dp[j - i] + a[i]);
        }
    }
    
    int max = 0;
    for (int i = 1; i <= n; i++) {
        if (dp[i] > max) {
            max = dp[i];
        }
    }
    cout << max << endl;
    return 0;
}