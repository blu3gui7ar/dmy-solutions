#include <bits/stdc++.h>
using namespace std;

bool valid(long long target, long long n, long long k, long long a[]) {
	long long t = 0;
	for (int i = 1; i <= n; i++) {
		t += a[i] / target;
		if (t >= k) {
			break;
		}
	}
	return t >= k;
}

int main () {
	long long n, k;
	cin >> n >> k;
	long long a[100010], sum = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		sum += a[i];
	}
	long long max = sum / k + 1;
    long long min = 1;
    while (min < max) {
        long long mid = (min + max) / 2;
        if (valid(mid, n, k, a)) {
            min = mid + 1;
        } else {
            max = mid;
        }
    }
	cout << min - 1;
	return 0;
} 