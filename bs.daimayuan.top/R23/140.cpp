#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    ull k;
    if (!(cin >> n >> k)) return 0;
    string s;
    cin >> s;

    // cap 用于将计数截断到 k + 1，避免溢出且足够判断大小关系
    ull cap = k + 1;

    // nxt[i][c] = 在位置 i 及之后，字符 c 首次出现的位置；不存在则为 -1
    vector<array<int,26>> nxt(n + 1);
    for (int c = 0; c < 26; c++) nxt[n][c] = -1;
    for (int i = n - 1; i >= 0; --i) {
        nxt[i] = nxt[i + 1];
        nxt[i][s[i] - 'a'] = i;
    }

    // dp[i] = 从位置 i 开始能形成的不同子序列数量（包含空序列），对 cap 截断
    vector<ull> dp(n + 1, 0);
    dp[n] = 1; // 只有空序列
    for (int i = n - 1; i >= 0; --i) {
        ull sum = 1; // 空序列
        for (int c = 0; c < 26; ++c) {
            int p = nxt[i][c];
            if (p != -1) {
                sum += dp[p + 1];
                if (sum > cap) { sum = cap; }
            }
        }
        dp[i] = sum;
    }

    // 构造第 k 小（1-based）的非空子序列
    string ans;
    int pos = 0;
    // k 是 1-based
    while (k > 0 && pos < n) {
        bool advanced = false;
        for (int c = 0; c < 26; ++c) {
            int p = nxt[pos][c];
            if (p == -1) continue;
            ull cnt = dp[p + 1]; // 以该字符开头的不同子序列数量（包含空后缀）
            if (cnt >= k) {
                // 选择此字符作为当前位置字符
                ans.push_back('a' + c);
                pos = p + 1;
                // 选中以当前字符单独构成的子序列（最短），因此消耗 1
                k -= 1;
                advanced = true;
                break;
            } else {
                k -= cnt;
            }
        }
        if (!advanced) break; // 无法继续（理论上若 k 合法不会到这里）
    }

    cout << ans << '\n';
    return 0;
}