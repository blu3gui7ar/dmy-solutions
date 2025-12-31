#include <bits/stdc++.h>
using namespace std;

int main () {
	int X, M;
	cin >> X >> M;
	char s[10000] = {};
    int i = 1;
	while(X > 0) {
        int tail = X % M;
        X /= M;
		if (tail < 10)
			s[i++] = '0' + tail;
		else
			s[i++] = 'A' + tail - 10;
	}
	long long l = strlen(s + 1);
	for (int i = l; i >= 1; i--) {
		cout << s[i];
	}
	return 0;
} 