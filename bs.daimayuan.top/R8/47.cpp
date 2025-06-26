#include <bits/stdc++.h>
using namespace std;

/**
 *  mex(l,r) == i 的区间可以用通过找到排列中的包含 0 ~ i-1 所有数的最短区间，然后扩展区间，
 *  当区间即将达到 i 为止。 找出最长的这样的区间，计算最短区间和最长区间范围内的子区间个数。
 *
 */
int main () {
    int n;
    cin >> n;
    vector<pair<int, int>> a2idx(n + 1);
    for (int i = 0; i <= n; i++) {
        int a;
        cin >> a;
        a2idx[i] = {a, i};
    }
    
    sort(a2idx.begin(), a2idx.end(), [](pair<int, int> &a, pair<int, int> &b) {
        return a.first < b.first;
    });
    
    //i = 0 为特殊情况考虑
    int idx = a2idx[0].second;
    cout << 1LL * idx * (idx + 1) / 2 + 1LL * (n - idx) * (n - idx + 1) / 2 << " ";

    int begin = n, end = 0;
    for (int i = 1; i <= n; i++) {
        if (a2idx[i-1].second < begin) {
            begin = a2idx[i-1].second;
        }
        if (a2idx[i-1].second > end) {
            end = a2idx[i-1].second;
        }
        int extend_to = a2idx[i].second;
        
        long long num;
        if (extend_to < begin) {
            num = 1LL * (begin - extend_to) * (n - end + 1);
        } else if (extend_to > end) {
            num = 1LL * (begin + 1) * (extend_to - end);
        } else if (extend_to >= begin && extend_to <= end) {
            num = 0;
        }
        cout << num << ' ';
    }
    cout << endl;
    return 0;
}