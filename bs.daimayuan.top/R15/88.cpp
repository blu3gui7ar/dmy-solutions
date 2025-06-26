#include <bits/stdc++.h>
using namespace std;

int main () {
    int n, q;
    cin >> n >> q;
    vector<vector<int>> prefix_bit_count(n + 1, vector<int>(32, 0));
    for (int i = 1; i <= n; i++) {
        int a;
        cin >> a;
        for (int j = 0; j < 32; j++) {
            // 考虑从1~i的所有数的第j位, 1的个数为: 前缀1的个数 + 当前位是否为1
            prefix_bit_count[i][j] = prefix_bit_count[i - 1][j] + ((a >> j) & 1);
        }
    }
    
    for (int i = 1; i <= q; i++) {
        int l, r;
        cin >> l >> r;
        long long sum = 0;
        for(int j = 0; j < 32; j++) {
            // 从l~r的所有数的第j位, 1的个数为
            int bit_count = prefix_bit_count[r][j] - prefix_bit_count[l - 1][j];

            // xor 为 (0的个数 * 1的个数) * 2
            // 左移j位加入sum
            sum += (2LL * (r - l + 1 - bit_count) * bit_count) << j;
        }
        cout << sum << " ";
    }
    cout << endl;
    return 0;
}