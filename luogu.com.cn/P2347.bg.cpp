#include <bits/stdc++.h>
using namespace std;

struct State {
    bool valid = false;
    int counts[7] = {};
};

int main() {
	int weights[7] = {0, 1, 2, 3, 5, 10, 20};
	int counts[7] = {};
    size_t cs = sizeof(counts);
    // dp[i][j] 表示是否能组成重量为 i 且最后一个法码为 j 的状态
    // dp[i][j].valid 表示能否
    // dp[i][j].counts 表示组成重量为 i 且最后一个法码为 j 的状态时，每个法码剩余数量
	State dp[1010][7] = {};
	for (int i = 1; i <= 6; i++) {
		cin >> counts[i];
	}
    for (int i = 1; i <= 6; i++) {
        if (counts[i] > 0) {
            dp[weights[i]][i].valid = true;
            memcpy(dp[weights[i]][i].counts, counts, cs);
            dp[weights[i]][i].counts[i] -= 1;
        }
    }

    /**
     * dp[i][j] 表示是否能组成重量为 i 且最后一个物品为 j 的状态
     * 
     * dp[i][j].valid = weights.slice(1, j + 1).some(w => dp[i - w][j].valid)
     *
     */

    for (int i = 1; i <= 1000; i++) {
        for (int j = 1; j <= 6; j++) {
            if (dp[i][j].valid) {
                for (int k = 1; k <= 6; k++) {
                    if (dp[i][j].counts[k] > 0) {
                        dp[i + weights[k]][k].valid = true;
                        memcpy(dp[i + weights[k]][k].counts, dp[i][j].counts, cs);
                        dp[i + weights[k]][k].counts[k] = dp[i][j].counts[k] - 1;
                    }
                }
            }
        }
    }
	
	int sum = 0;
	for (int i = 1; i <= 1000; i++) {
        for (int j = 1; j <= 6; j++) {
            if (dp[i][j].valid) {
                sum++;
                break;
            }
        }
	}
	cout << "Total = " << sum;
	return 0;
} 