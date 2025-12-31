#include <bits/stdc++.h>
using namespace std;
int main () {
	int n;
	cin >> n;
	int right[1000][5], F[1000][5];
	for (int i = 0; i < n; i++) {
		for (int j = 1; j <= 4; j++) {
			cin >> right[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 1; j <= 4; j++) {
			cin >> F[i][j];
		}
	}
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= 4; j++) {
//			cout << right[i - 1][j] << ' ' << F[i - 1][j] << endl;
//		}
//	}
	for (int k = 0; k < n; k++) {
		int ans = 0, t = k;
		for (int i = 0; i < n; i++) {
			bool invalid = false, valid = true;
			for (int j = 1; j <= 4; j++) {
				if (right[t % n][j] == 0 && F[i][j] == 1) {
					invalid = true;
					break;
				} else if (right[t % n][j] == 1 && F[i][j] == 0) {
					valid = false;
				} 
			}
			if (invalid) {
				ans += 0;
//				cout << ans << ' ';
			} else if (!valid) {
				ans += 3;
//				cout << ans << ' ';
			} else {
				ans += 6;
//				cout << ans << ' ';
			}
			t++;
		}
		cout << ans << ' ';
	}
	return 0;
}