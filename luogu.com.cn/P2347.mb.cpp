#include <bits/stdc++.h>
using namespace std;


int main() {
	int weights[7] = {0, 1, 2, 3, 5, 10, 20};
	int counts[7] = {};
    int W = 0;
	bool dp[1010] = {};
	for (int i = 1; i <= 6; i++) {
		cin >> counts[i];
        W += weights[i] * counts[i];
	}
    /*
     * 多重背包转01背包
        $$
    f_{i,j} = \max_{k=0}^{ki}(f_{i - 1, j - k * w_i} + v_i * k)
        $$
    使用滚动数组优化空间复杂度, 每一轮i, f_{i,j} 只依赖于上一轮(i - 1)的值，
    所以可以只使用一维数组进行滚动更新, 
    但是要注意从大到小枚举j, 从而避免覆盖f_{i - 1, j} 的值。
    $$ 
        f_{j(current)} = max(f_{j(last)}, f_{j - w_i(last)} + v_i)
    $$ 
    */
    dp[0] = true;
    for (int i = 1; i <= 6; i++) {
        for (int v = W; v >= weights[i]; v--) {
            for (int k = 1; k <= counts[i] && v >= k * weights[i]; k++) {
                dp[v] = dp[v] || dp[v - k * weights[i]];
            }
        }
    }
	
	int sum = 0;
    for (int i = 1; i <= W; i++) {
        if (dp[i]) {
            sum++;
        }
    }
	cout << "Total=" << sum;
	return 0;
} 