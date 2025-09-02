#include <bits/stdc++.h>
using namespace std;
int main () {
	int A, B, T, a1, a2, a3;
	cin >> A >> B >> T >> a1 >> a2 >> a3;
	if (T <= A) {
		cout << a1;
	} else if (T <= B) {
		cout << a1 + (T - A) * a2;
	} else {
		cout << a1 + (B - A) * a2 + (T - B) * a3;
	}
	return 0;
}