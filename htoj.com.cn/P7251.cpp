#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main () {
	int n;
	cin >> n;

    int ai;
	int f[110] = {};
	for (int i = 1; i <= n; i++) {
        cin >> ai;
        f[i] = max(
            (i > 3 ? f[i - 3] : 0) + ai, 
            (i > 1 ? f[i - 1] : 0)
        );
	}
	
	cout << f[n];
	return 0;
}

	