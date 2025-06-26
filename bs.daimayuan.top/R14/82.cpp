#include <bits/stdc++.h>
using namespace std;
int main () {
    int n, m, q;
    cin >> n >> m >> q;
    
    vector<int> row(n + 1);
    vector<int> col(m + 1);
    iota(row.begin(), row.end(), 0);
    iota(col.begin(), col.end(), 0);
    
    for (int i = 0; i < q; i++) {
        int action, x, y;
        cin >> action >> x >> y;
        int t;
        switch (action) {
            case 1:
                t = row[x];
                row[x] = row[y];
                row[y] = t;
                break;
            case 2:
                t = col[x];
                col[x] = col[y];
                col[y] = t;
                break;
            case 3:
                cout << (1ll * row[x] - 1 ) * m + col[y] << endl;
                break;
        }

    }
    

    return 0;
}