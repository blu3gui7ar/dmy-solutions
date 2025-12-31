#include <bits/stdc++.h>
using namespace std;

int main () {
	int m, n;
	cin >> m >> n;
	
	bool sushu[100010] = {};
	for (int i = 2; i < 100000; i++) {
		bool valid = true;
		for (int k = 2; k * k < i; k++) {
			if (i % k == 0) {
				valid = false;
				break;
			}
		}
		sushu[i] = valid;
		// cout << sushu[i] << ' ';
	}
    
	bool zss[100010] = {};
	for (int i = 1; i < 100000; i++) {
		if (i / 10 == 0) {//一位数 
			zss[i] = sushu[i];
		} else if (i / 100 == 0) {//两位数 
			zss[i] = sushu[i] && sushu[i % 10 * 10 + i / 10];
		} else if (i / 1000 == 0) {//三位数 
			zss[i] = sushu[i] && sushu[i % 10 * 100 + i / 10 % 10 * 10 + i / 100];
		} else if (i / 10000 == 0) {//四位数
			zss[i] = sushu[i] && sushu[i % 10 * 1000 + i / 10 % 10 * 100 + i / 100 % 10 * 10 + i / 1000];
		} else {//五位数 
			zss[i] = sushu[i] && sushu[i % 10 * 10000 + i / 10 % 10 * 1000 + i / 100 % 10 * 100 + i / 1000 % 10 * 10 + i / 10000];
		}
	}
	
	bool No = true, first = true;
	for (int i = m; i <= n; i++) {
		if (zss[i]) {
			if (first) {
				cout << i;
				first = false;
			} else {
				cout << ',' << i;
			}
			No = false;
		}
	}
	if (No)
		cout << "No";
	return 0;
}