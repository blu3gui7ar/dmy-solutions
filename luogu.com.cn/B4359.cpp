#include <bits/stdc++.h>
using namespace std;

int main () {
	int n;
	cin >> n;
	long long a = 0, last_a = 0, sum = 0;
	for (int i = 1; i <= n; i++) {
        cin >> a;
		if (a > last_a) {
			sum += a;
            last_a = a;
		} else {
			sum += last_a + 1;
			last_a+= 1;
		}
	}
	cout << sum;
	return 0;
} 