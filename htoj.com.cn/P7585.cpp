#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 998244353;
int n, m;
int a[100010] = {};
bool ok (int x) {
	int t = 0;
	for (int i = 1; i <= n; i++) {
		int g = a[i] / x;
		if (t + g * (n - i + 1) >= m )
			return true;
		else
			t += a[i] / x;
	}
	return false;
}
int main (int argc, char const *argv[]) {
    // ios_base::sync_with_stdio(false);
    // cin.tie(nullptr);
    // solve the io redirect problem for vscode
    if (argc > 1){
        if (argv[1][0] == '<') {
            freopen(argv[2], "r", stdin);
        } else {
            freopen(argv[1], "r", stdin);
        }
    }

	cin >> n >> m;
	int max_a = 0;
	ll sum_a = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		sum_a += a[i];
		max_a = max(max_a, a[i]);
	}
	if (m > sum_a) {
		cout << "Failed";
		return 0;
	}

	sort(a + 1, a + n + 1);
	vector<int> range(max_a + 1);
	iota(range.begin(), range.end(), 0);

	auto it = upper_bound(range.begin() + 1, range.end(), 0, [&](int , int val) {
		return !ok(val);
	});
	if (it == range.begin() + 1) {
		cout << "Failed";
	} else {
		cout << *(it - 1);
	}
	return 0;
}
