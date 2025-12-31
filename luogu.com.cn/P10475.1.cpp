#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main () {
	int R, C;
	cin >> R >> C;
	char bacas[10010][80] = {};
	//
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			cin >> bacas[i][j];
		}
	}
	//
	int Rans = 1, Cans = 1;
	for (int j = 1; j <= C; j++) {
        bool valid_found = false;
		for (int sit = Rans; sit <= R; sit += Rans) {
			bool flag = true;
			for (int i = sit + 1; i <= R; i++) {
				int compare = i % sit;
				if (compare == 0) {
					compare = sit;
				}
				if (bacas[i][j] != bacas[compare][j]) {
					flag = false;
					break;
				}
			}
			if (flag) {
				// valid row, process other rows
				Rans = sit;
                valid_found = true;
                // cout << "valid col: " << j << " with width " << sit << endl;
				break;
			} else {
				// invalid row, jump to next sit
			}
		}
        
        if (!valid_found) {
            Rans = R;
            // cout << "valid col: " << j << " with width " << Rans << endl;
        }
	}

	for (int i = 1; i <= R; i++) {
        bool valid_found = false;
		for (int sit = Cans; sit <= C; sit += Cans) {
			bool flag = true;
			for (int j = sit + 1; j <= C; j++) {
				int compare = j % sit;
				if (compare == 0) {
					compare = sit;
				}
				if (bacas[i][j] != bacas[i][compare]) {
					flag = false;
					break;
				}
			}
			if (flag) {
				Cans = sit;
                // cout << "valid row: " << i << " with width " << sit << endl;
                valid_found = true;
				break;
			} else {
                // cout << "invalid row: " << i << " with width " << sit << endl;
			}
		}
        if (!valid_found) {
            Cans = C;
            // cout << "valid row: " << i << " with width " << Cans << endl;
        }
	}
	//
	cout << Rans * Cans;
	return 0;
}