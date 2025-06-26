#include <bits/stdc++.h>
using namespace std;
int main () {
    int n;
    cin >> n;
    int ai, ai1, ai2;
    cin >> ai;
    cin >> ai1;
    int cnt = 0;
    for (int i2 = 3; i2 <= n; i2++) {
        cin >> ai2;
        if (ai > ai1 && ai1 > ai2) {
            cnt++;
        }
        ai = ai1;
        ai1 = ai2;
    }
    cout << cnt << endl;
    return 0;
}