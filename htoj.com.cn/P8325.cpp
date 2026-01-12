#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main () {
	int n;
	cin >> n;
	int difang[50050], wofang[50050];
	for (int i = 1; i <= n; i++)
		cin >> difang[i];
	int dk = 1, wk = 0;
	sort(difang + 1, difang + n + 1);
	for (int i = 1; i <= 2 * n; i++) {
		if (difang[dk] != i) {
			wofang[++wk] = i;
		} else {
			dk++;
		}
	}
	// for (int i = 1; i <= n; i++) 
	// 	cout << wofang[i] << ' ';
	// cout << endl;
	int ans = 0;
	int dh = 1, dt = n, wh = 1, wt = n;
	for (int i = 1; i <= n; i++) {
		if (difang[dh] < wofang[wh]) {
			ans++;
			dh++;
			wh++;
		} else if (difang[dt] < wofang[wt]) {
			ans++;
			dt--;
			wt--;
		} else {
			dt--;
			wh++;
		}
	}
	cout << ans;
	return 0;
}