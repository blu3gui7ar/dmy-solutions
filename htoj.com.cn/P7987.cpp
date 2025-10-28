#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main () {
	int n, a, b, c;
	cin >> n >> a >> b >> c;

	int f[1010] = {};
    f[a] = a;
    f[b] = b;
    f[c] = c;
	for (int i = 1; i <= n; i++) {
        f[i] = max(
            i > a ? f[i - a] + a : 0, 
            max(
                i > b ? f[i - b] + b : 0, 
                i > c ? f[i - c] + c : 0
            )
        );
	}
	
	cout << f[n];
	return 0;
}

	