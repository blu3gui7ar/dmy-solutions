#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
const int MAXN = 1e6 + 10;

long long fact[MAXN], inv_fact[MAXN];

long long qpow(long long a, long long b) {
    long long res = 1;
    while (b) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

void init() {
    fact[0] = 1;
    for (int i = 1; i < MAXN; i++) {
        fact[i] = fact[i-1] * i % MOD;
    }
    inv_fact[MAXN-1] = qpow(fact[MAXN-1], MOD-2);
    for (int i = MAXN-2; i >= 0; i--) {
        inv_fact[i] = inv_fact[i+1] * (i+1) % MOD;
    }
}

long long C(int n, int i) {
    if (i < 0 || i > n) return 0;
    return fact[n] * inv_fact[i] % MOD * inv_fact[n-i] % MOD;
}

long long P(int n, int i) {
    if (i < 0 || i > n) return 0;
    return fact[n] * inv_fact[n-i] % MOD;
}

/**
 * 例1: 3(G1~G3) 3(S1~S9) 5(P1~P9) 1(G?)
 * 分组G1(S1,S2,S3), G2(S4,S5,S6), G3(S7,S8,S9)
 * 
 * 0. 选出1个支持1的组 （G1, G2, G3 三种)
 * 1. 选出支持1的必备人 5选2 $$ P_5^2 / (2!)^1 = 10 $$ 种
 * 2. 选出支持2的必备人 4选4 $$ P_4^4 / (2!)^2 = 6 $$ 种
 * 3. 剩下3人,3人支持1，0人支持2，每组剩下1个位置 $$ P_3^3 = 6 $$ 种
 *    对于两个支持2的组，没有重复
 *    对于一个支持1的组，每种情况被重复了 $$ C_3^1 = 3 $$ 次
 * 
 * 所以 3 * 10 * 6 * 6 / 3 = 360 种
 * 
 * 例2: 5(G1~G5) 5(S1~S25) 8(P1~P25) 2(G?)
 * 
 * 0. 选出2个支持1的组 $$ C_5^2 = 10 $$, 如： G1, G2, 则选定位置为(S1~S3, S6~S8)
 * 1. 选出分配到 S1~S3,S6~S8 支持1排列数 $$ P_8^6 $$  // /(3!)^2
 * 2. 选出分配到 S11~S13, S16~S18, S21~S23  支持2的排列数 $$ P_{17}^9  $$  // /(3!)^3 = 40840800
 * 3. 剩下10人,2人支持1，8人支持2，每组剩下2个位置 $$ P_{10}^{10} = 3628800 $$ 
 *    对于支持1的组,
 *        当加入i个支持1的人时，每种情况重复 $$ C_{3+i}^i $$
 *    对于支持2的组
 *        当加入i个支持2的人时，每种情况重复 $$ C_{3+i}^i $$
 *        
 *
 *  G1: S1 S2 S3 | S4 S5 - 5! = C_5^3 * 3! * 2!  
 *      S1 S2 S4 | S3 S9
 *  
 *
 *
 * 
 */
void solution(int n, int k, int a, int x) {
    // n 个小组编号1～n, n*k 个位置编号1~n*k
    // 每组分为 m 和 k-m 两部分，对于 m 部，明确要求支持同 (1 或 2)，k-m 部自由分配
    int m = (k + 1) / 2; // 每组需要至少m个人支持同一款式才能获得多数
    
    // 计算恰好有x个组支持款式1的方案数
    long long ans = 0;
    
    // 使用组合数学和容斥原理求解
    // 首先，我们需要从n个组中选择x个组作为支持款式1的组
    // 然后，我们需要确保这x个组中的每个组都有至少m个支持款式1的学生
    // 同时，其余n-x个组中的每个组都有至多m-1个支持款式1的学生
    
    // 使用容斥原理计算满足条件的方案数
    for (int i = 0; i <= x; i++) {
        // 选择i个组不满足"至少m个人支持款式1"的条件
        for (int j = 0; j <= n - x; j++) {
            // 选择j个组不满足"至多m-1个人支持款式1"的条件
            
            // 计算在这种情况下的方案数
            long long sign = ((i + j) % 2 == 0) ? 1 : -1;
            
            // 计算组合数：从x个组中选择i个，从n-x个组中选择j个
            long long ways_to_select = C(x, i) * C(n - x, j) % MOD;
            
            // 计算在这种选择下，将a个支持款式1的学生分配到各组的方案数
            // 对于x-i个组，每组至少m个支持款式1的学生
            // 对于i个组，每组至多m-1个支持款式1的学生
            // 对于j个组，每组至少m个支持款式1的学生
            // 对于n-x-j个组，每组至多m-1个支持款式1的学生
            
            // 使用多项式系数计算方案数
            // 设置初始状态
            vector<long long> dp(a + 1, 0);
            dp[0] = 1;
            
            // 处理x-i个组（每组至少m个支持款式1的学生）
            for (int g = 0; g < x - i; g++) {
                vector<long long> ndp(a + 1, 0);
                for (int p = 0; p <= a; p++) {
                    for (int q = m; q <= k; q++) {
                        if (p + q <= a) {
                            ndp[p + q] = (ndp[p + q] + dp[p] * C(k, q) % MOD) % MOD;
                        }
                    }
                }
                dp = ndp;
            }
            
            // 处理i个组（每组至多m-1个支持款式1的学生）
            for (int g = 0; g < i; g++) {
                vector<long long> ndp(a + 1, 0);
                for (int p = 0; p <= a; p++) {
                    for (int q = 0; q < m; q++) {
                        if (p + q <= a) {
                            ndp[p + q] = (ndp[p + q] + dp[p] * C(k, q) % MOD) % MOD;
                        }
                    }
                }
                dp = ndp;
            }
            
            // 处理j个组（每组至少m个支持款式1的学生）
            for (int g = 0; g < j; g++) {
                vector<long long> ndp(a + 1, 0);
                for (int p = 0; p <= a; p++) {
                    for (int q = m; q <= k; q++) {
                        if (p + q <= a) {
                            ndp[p + q] = (ndp[p + q] + dp[p] * C(k, q) % MOD) % MOD;
                        }
                    }
                }
                dp = ndp;
            }
            
            // 处理n-x-j个组（每组至多m-1个支持款式1的学生）
            for (int g = 0; g < n - x - j; g++) {
                vector<long long> ndp(a + 1, 0);
                for (int p = 0; p <= a; p++) {
                    for (int q = 0; q < m; q++) {
                        if (p + q <= a) {
                            ndp[p + q] = (ndp[p + q] + dp[p] * C(k, q) % MOD) % MOD;
                        }
                    }
                }
                dp = ndp;
            }
            
            // 将方案数乘以选择组的方式，并根据容斥原理的符号加减
            ans = (ans + sign * ways_to_select % MOD * dp[a] % MOD + MOD) % MOD;
        }
    }
    
    // 考虑学生在各组内的排列方式
    // 对于每个组，学生的排列方式为k!
    // 总共有n个组，所以总的排列方式为(k!)^n
    long long total_arrangements = 1;
    for (int i = 0; i < n; i++) {
        total_arrangements = total_arrangements * fact[k] % MOD;
    }
    
    // 最终结果是方案数乘以排列方式
    ans = (ans * total_arrangements) % MOD;
    
    cout << ans << endl;
}

int main () {
    int n, k, a, x;
    cin >> n >> k >> a >> x;
    init();
    
    solution(n, k, a, x);

    return 0;
}
