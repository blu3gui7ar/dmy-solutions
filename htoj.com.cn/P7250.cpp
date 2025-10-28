#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main () {
	int n, a, b;
	cin >> n >> a >> b;

	int f[110] = {};
    f[a] += 1;
    f[b] += 1;
	for (int i = 1; i <= n; i++) {
		if (i + a <= n) {
        	f[i + a] += f[i];
		}
		if (i + b <= n) {
        	f[i + b] += f[i];
		}
	}
	
	cout << f[n];
	return 0;
}

	