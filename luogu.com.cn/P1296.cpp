#include <bits/stdc++.h>
using namespace std;
int p[1000010] = {};
int main () {
	int n, d;
	cin >> n >> d;
	for (int i = 1; i <= n; i++) {
		cin >> p[i];
	}
	sort (p + 1, p + n + 1);
	long long ans = 0;
	for (int i = 1; i < n; i++) {
        // ans += upper_bound(p + i + 1, p + n + 1, p[i] + d) - (p + i + 1);
        int min = i + 1;
        int max = n + 1; // n + 1 to cover p[n] <= p[i] + d case (min == n + 1)
        while(min < max) {
            int mid = (min + max) / 2;
            if (p[mid] - p[i] <= d) {
                min = mid + 1;
            } else {
                max = mid;
            }
        }
        ans += min - i - 1;
	}
	cout << ans;
	return 0;
}