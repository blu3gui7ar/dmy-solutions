#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    int right[1000][5], F[1000][5];
    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= 4; j++) {
            cin >> right[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= 4; j++) {
            cin >> F[i][j];
        }
    }
    //	for (int i = 1; i <= n; i++) {
    //		for (int j = 1; j <= 4; j++) {
    //			cout << right[i - 1][j] << ' ' << F[i - 1][j] << endl;
    //		}
    //	}
    for (int i = 0; i < n; i++) {
        int ans = 0;
        for (int k = 0; k < n; k++) {
            int wrong = 0, correct = 0, miss = 0, ignore = 0;
            for (int j = 1; j <= 4; j++) {
                int rightAns = right[(k + i) % n][j];
                int FAns = F[k][j];
                if (rightAns == 1) {
                    if (FAns == 0) {
                        miss++;
                    }
                    else {
                        correct++;
                    }
                }
                else {
                    if (FAns == 1) {
                        wrong++;
                    }
                    else {
                        ignore++;
                    }
                }
            }
            if (wrong > 0 || 4 == miss + ignore) {
                ans += 0;
            }
            else if (0 == wrong && correct > 0 && miss > 0) {
                ans += 3;
            }
            else if (0 == wrong && 0 == miss) {
                ans += 6;
            }
            // cout << ':' << ans << endl;
        }
        cout << ans << ' ';
    }
    return 0;
}