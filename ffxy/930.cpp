#include <bits/stdc++.h>
using namespace std;
const int N = 100009;
struct Bomb {
    int left, right;
};
Bomb b[N];
bool cmp(const Bomb& u, const Bomb& v) {
    return u.left < v.left;
}
int x[N], r[N];
int main() {
    // freopen("bomb.in", "r", stdin);
    // freopen("bomb.in", "w", stdout);
    int LEN, n;
    cin >> LEN >> n;
    for (int i = 1; i <= n; i++) cin >> x[i];
    for (int i = 1; i <= n; i++) cin >> r[i];
    for (int i = 1; i <= n; i++) {
        b[i].left = x[i] - r[i];
        b[i].right = x[i] + r[i];
    }
    sort(b + 1, b + n + 1, cmp);
    int ans = LEN;
    int f = 0, g = 0;
    for (int i = 1; i <= n; i++) {
        f = max(g, b[i].left);
        g = max(g, b[i].right);
        g = min(g, LEN);
        ans -= g - f;
    }
    cout << ans << endl;
    return 0;
}