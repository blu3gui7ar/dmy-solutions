#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void work () {
	int n, q, p;
	cin >> n >> p >> q;
	int pi[110], qi[110];
	for (int i = 1; i <= n; i++)
		cin >> pi[i] >> qi[i];
	int dp[50050] = {}, spend[50050] = {}, ans = INT_MAX;
	for (int i = 1; i <= n; i++) {
		for (int j = q; j >= qi[i]; j--) {
			int tool = dp[j - qi[i]] + pi[i];
			if (tool > dp[j]) {
				dp[j] = tool;
				spend[j] = spend[j - qi[i]] + qi[i];
			}
			if (dp[j] >= p) {
				if (spend[j] < ans) {
					ans = spend[j];
				}
			}
//			cout << dp[j] << ' ' << spend[j] << endl;
		}
	}
	if (ans == INT_MAX) {
		ans = -1;
	}
	cout << ans << endl;
};

int main () {
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++)
		work();
	return 0;
}