#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Zero {
    int x = 0;
    int y = 0;
};

int main() {
    int n;
    cin >> n;
    int a[1010][1010];
    Zero zeros[10010] = {};
    int t = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];

            if (a[i][j] == 0) {
                zeros[t].x = i;
                zeros[t].y = j;
                t++;
            }
        }
    }

    if (zeros[1].x == 0) {
        cout << "Bad Game!";
        return 0;
    }

    int ans = 0, maxans = 0;
    for (int k = 1; k <= 10000; k++) {
        if (zeros[k].x == 0) {
            break;
        }

        for (int i = 1; i <= n; i++) {
            if (a[zeros[k].x][i] != 0) {
                ans += a[zeros[k].x][i];
            }
        }
        for (int j = 1; j <= n; j++) {
            if (a[j][zeros[k].y] != 0) {
                ans += a[j][zeros[k].y];
            }
        }
        if (maxans < ans) {
            maxans = ans;
        }
        ans = 0;
    }
    cout << maxans;
    return 0;
}
