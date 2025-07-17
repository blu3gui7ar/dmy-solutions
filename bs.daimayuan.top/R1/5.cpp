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
    vector<ll> prefixCnt(n+1, 0); //小于x的个数前缀和
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        prefixCnt[i+1] = prefixCnt[i] + (a[i] < x ? 1 : 0);
    }
    
    // 如果子区间中第k小的数大于等于x，我们称这个子区间是“过分的”。
    // 等价于子区间中小于x的数的个数小于k
    ll count = 0;
    for (int l = 0; l < n; l++) {
        int left = l, right = n - 1;
        int rs = -1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (prefixCnt[mid + 1] - prefixCnt[l] < k) {
                rs = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        if (rs != -1) {
            count += (rs - l + 1);
        }
    }
    
    cout << count << endl;
    return 0;
}