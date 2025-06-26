#include <bits/stdc++.h>
#include <cmath>
using namespace std;

const int MAX = 1024;

int z_fill(int a[MAX][MAX], int x, int n, int row, int col, int val) {
    if (x == 1) {
        a[row][col] = val++;
        a[row][col+1] = val++;
        a[row+1][col] = val++;
        a[row+1][col+1] = val++;
        return val;
    }
    val = z_fill(a, x-1, n/2, row, col, val);
    val = z_fill(a, x-1, n/2, row, col + n/2, val);
    val = z_fill(a, x-1, n/2, row + n/2, col, val);
    val = z_fill(a, x-1, n/2, row + n/2, col + n/2, val);
    return val;
}

int main () {
    int x;
    cin >> x;
    int n = pow(2, x);
    int a[MAX][MAX] = {0};

    z_fill(a, x, n, 0, 0, 1);
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}