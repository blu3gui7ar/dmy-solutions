#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main () {
	ll a , b, x, ans = 0;
	cin >> a >> b >> x;
	for (ll j = 0; j <= x / b; j++) {
		ans += (x - j * b) / a + 1;
	}
	cout << ans;
	return 0;
}