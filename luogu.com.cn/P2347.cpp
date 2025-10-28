#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	ll tWeight = 0;
	int weights[7] = {0, 1, 2, 3, 5, 10, 20};
	int counts[7];
	for (int i = 1; i <= 6; i++) {
		cin >> counts[i];
	}
	bool dp[1001] = {false};
	for (int i = 1; i <= 6; i++) {
		tWeight += weights[i] * counts[i];
	}
	
    dp[0] = true;
	for (int i = 1; i <= 6; i++) {
		for (ll k = tWeight; k >= weights[i]; k--) {
			ll n = counts[i];
			for (ll j = 1; j <= n; j++) {
				if (j * weights[i] <= k)
					dp[k] = dp[k - j * weights[i]] || dp[k];
			}
		}
	}
	
	ll sum = 0;
	for (int i = 1; i <= tWeight; i++) {
		if (dp[i]) {
			sum++;
        }
	}
	cout << "Total=" << sum;
	return 0;
}