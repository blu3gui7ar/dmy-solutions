#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
const int BASE = 911382629; // or 1e9 + 7 进制基数取大质数
//const int MOD = ULLONG_MAX; // 取模值取 2^64 - 1(直接依赖举出取模) or 1e9+9、1e18+3等大质数

const int N = 10005, M = 75;
//KMP
void prefix_pi(ull *hashes, int *pi, int n) {
	pi[0] = 0;
	for(int i = 1; i <= n; i++){
		int j = pi[i - 1];
		while(j && hashes[i] != hashes[j]) j = pi[j - 1];
		if(hashes[i] == hashes[j]) j++;
		pi[i] = j;
	}
}

int main() {
	int r, c;
	cin >> r >> c;
	char bacas[M][N] = {};
	char ch;
	ull row_hashes[M] = {};
	ull col_hashes[N] = {};
	for(int i = 1; i <= r; i++){
		for(int j = 1; j <= c; j++){
			cin >> ch;
			bacas[i][j] = ch;
			int n = ch - 'A';
			//HASH row and col
			row_hashes[i] = row_hashes[i] * BASE + n; //省略取模操作（2^64 - 1 自动取模）
			col_hashes[j] = col_hashes[j] * BASE + n; //省略取模操作（2^64 - 1 自动取模）
		}
	}
	
	// for(int i = 1; i <= r; i++){
	// 	for(int j = 1; j <= c; j++){
	// 		cout << bacas[i][j];
	// 	}
	// 	cout << endl;
	// }
	// cout << "-----------------" << endl;
	
	// for (int i = 1; i <= r; i++) {
	// 	cout << row_hashes[i] << endl;
	// }
	
	// cout << "-----------------" << endl;

	// for (int i = 1; i <= c; i++) {
	// 	cout << col_hashes[i] << endl;
	// }
	// cout << "-----------------" << endl;
	
	int row_pi[M] = {};
	prefix_pi(row_hashes + 1, row_pi + 1, r); // CAUTION: 1-based index
	int r_unit = r - row_pi[r];

	// for (int i = 1; i <= r; i++) {
	// 	cout << row_pi[i] << ' ';
	// }
	// cout << endl << "-----------------" << endl;

	int col_pi[N] = {};
	prefix_pi(col_hashes + 1, col_pi + 1, c); // CAUTION: 1-based index
	int c_unit = c - col_pi[c];
	// for (int i = 1; i <= c; i++) {
	// 	cout << col_pi[i] << ' ';
	// }
	// cout << endl << "-----------------" << endl;
	cout << r_unit * c_unit << endl;
	return 0;
}
