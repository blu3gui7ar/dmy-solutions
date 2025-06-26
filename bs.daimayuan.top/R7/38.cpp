#include <bits/stdc++.h>
using namespace std;
int main () {
    int n, m;
    cin >> n >> m;
    int matrix[1000][1000] = {0};
    
    int idx[][2] = {
        {-3, 0},
        {-2, -1}, {-2, 0}, {-2, 1},
        {-1, -2}, {-1, -1}, {-1, 0}, {-1, 1}, {-1, 2},
        {0, -3}, {0, -2}, {0, -1}, {0, 0}, {0, 1}, {0, 2}, {0, 3},
        {1, -2}, {1, -1}, {1, 0}, {1, 1}, {1, 2},
        {2, -1}, {2, 0}, {2, 1},
        {3, 0}
    };

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            char c;
            cin >> c;
            if (c == '@') {
                for(auto pq : idx) {
                    int p = i + pq[0];
                    int q = j + pq[1];
                    if (p >= 0 && p < n && q >=0 && q < m) {
                        matrix[p][q]++;
                    }
                }
                
            }
        }
    }
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}