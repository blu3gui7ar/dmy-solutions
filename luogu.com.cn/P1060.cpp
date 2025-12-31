#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main () {
	int n, m;
	cin >> n >> m;
	int w[30] = {}; //价格
    int v[30] = {}; //重要度
	for (int i = 1; i <= m; i++) {
		cin >> w[i] >> v[i];
	}
    ll dp[30030] = {};
	for (int i = 1; i <= m; i++) { //第i个物品
		for (int j = n; j >= w[i]; j--) { //当前总金额
            dp[j] = max(dp[j], dp[j - w[i]] + w[i] * v[i]);
		}
	}
    cout << dp[n];
	return 0;
}