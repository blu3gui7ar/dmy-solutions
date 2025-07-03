#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
const int MAXN = 8005;

int p[MAXN][MAXN]; 
/**
 * 动态规划递推：
 * 
 * 状态转移方程
 * p[i][j] = p[i-j][j] + p[i-1][j-1]
 * 
 * 对于将整数 i 划分为 j 个正整数的和（即 p[i][j]），每个划分必然属于以下两种互斥情况之一：
 * 
 * 情况1：划分中至少有一个1
 *   去掉这个1，问题转化为 将 i-1 划分成 j-1 个正整数, 即 p[i-1][j-1]
 * 情况2：划分中所有数都 ≥2
 *   所有数减1，问题转化为 将 i-j 划分成 j 个正整数, 即 p[i-j][j]
 */
int dp_solution(int n, int m) {
    p[0][0] = 1;

    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (i - j >= 0)             {
                p[i][j] = (p[i - j][j] + p[i - 1][j - 1]) % MOD; /*p[i-1][j-1]至少有一个部分为1。*/
            }
        }
    }

    return p[m][n];
}

//整数划分问题: k部分拆w
int main(int argc, char const* argv[]) {
    if (argc > 1) {
        if (argv[1][0] == '<') {
            freopen(argv[2], "r", stdin);
        }
        else {
            freopen(argv[1], "r", stdin);
        }
    }

    memset(p, 0, sizeof(p));
    dp_solution(MAXN - 1, MAXN - 1);
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        cout << p[m][n] << endl;
    }
    return 0;
}