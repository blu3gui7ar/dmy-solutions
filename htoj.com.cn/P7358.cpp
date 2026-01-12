#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main () {
	int n;
	cin >> n;
	int a[2020], b[2020];
	for (int i = 1; i <= n; i++)
		cin >> b[i];
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	int ans = 0;
	sort(a + 1, a + n + 1);
	sort(b + 1, b + n + 1);
	int dh = 1, wh = 1, dt = n, wt = n;
	for (int i = 1; i <= n; i++) {
		if (b[wt] > a[dt]) {
			ans += 200;
			wt--;
			dt--;
		} else if (b[wt] < a[dt]) {
			ans -= 200;
			wh++;
			dt--;
		} else {
			if (b[wh] > a[dh]) {
				ans += 200;
				wh++;
				dh++;
			} else {
				if (b[wh] < a[dt]) {
					ans -= 200;
				}
				wh++;
				dt--;
			}
		}
//		cout << dh << ' ' << dt << ' ' << wh << ' ' << wt << endl;
	}
	cout << ans;
	return 0;
}