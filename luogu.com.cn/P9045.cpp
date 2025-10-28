#include <bits/stdc++.h>
using namespace std;

int main () {
	int n, k;
	cin >> n >> k;
	int a;
	bool t[500050] = {};
	long long ans = 0, tool = 0;
	for (int i = 1; i <= n; i++) {
        cin >> a;
		if (t[a] == false) {
			ans += (i - tool - 1);
			t[a] = true;
			tool++;
		}
        
        if (tool == k) {
            break;
        }
	}
	
	if (tool < k) {
		cout << -1;
	} else {
		cout << ans;
	}
	return 0;
}