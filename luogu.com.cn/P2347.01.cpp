#include <bits/stdc++.h>
using namespace std;


int main() {
	int weights[7] = {0, 1, 2, 3, 5, 10, 20};
	int counts[7] = {};
    int n = 0;
    int W = 0;
    int w[1010] = {};
	for (int i = 1; i <= 6; i++) {
		cin >> counts[i];
        for (int j = 1; j <= counts[i]; j++) {
            w[++n] = weights[i];
        }
        W += weights[i] * counts[i];
	}
	bool dp[1010] = {};
    /*
     * 多重背包转01背包
        $$
    f_{i,j} = \max_{k=0}^{ki}(f_{i - 1, j - k * w_i} + v_i * k)
        $$
     * 01背包

        $$ 
        f_{i,j} = max(f_{i - 1, j}, f_{i - 1, j - w_i} + v_i)
        $$ 
    使用滚动数组优化空间复杂度, 每一轮i, f_{i,j} 只依赖于 f_{i - 1, j} 和 f_{i - 1, j - w_i}, 
    所以可以从大到小枚举j进行滚动更新, 从而避免覆盖f_{i - 1, j} 的值.
    $$ 
        f_{j(current)} = max(f_{j(last)}, f_{j - w_i(last)} + v_i)
    $$ 
    */
    dp[0] = true;
    for (int i = 1; i <= n; i++) {
        for (int v = W; v >= w[i]; v--) {
            dp[v] = dp[v] || dp[v - w[i]];
        }
    }
	
	int sum = 0;
    for (int i = 1; i <= W; i++) {
        if (dp[i]) {
            sum++;
        }
    }
	cout << "Total = " << sum;
	return 0;
} 