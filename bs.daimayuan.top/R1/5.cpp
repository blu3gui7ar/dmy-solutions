#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 998244353;
int main (int argc, char const *argv[]) {
    // ios_base::sync_with_stdio(false);
    // cin.tie(nullptr);
    // solve the io redirect problem for vscode
    if (argc > 1){
        if (argv[1][0] == '<') {
            freopen(argv[2], "r", stdin);
        } else {
            freopen(argv[1], "r", stdin);
        }
    }
    int n, k, x;
    cin >> n >> k >> x;
    
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    ll count = 0;
    // 枚举左端点
    for (int l = 0; l < n; l++) {
        // 如果子区间中第k小的数大于等于x，我们称这个子区间是“过分的”。
        // 等价于子区间中小于x的数的个数小于k
        int lessThanX = 0;
        // 枚举右端点
        for (int r = l; r < n; r++) {
            if (a[r] < x) {
                lessThanX++;
            }
            if (lessThanX < k) {
                // 子区间是过分的
                count++;
            } else {
                // 后续子区间都不是过分的，提前跳出
                break;
            }
        }
    }
    
    cout << count << endl;
    return 0;
}