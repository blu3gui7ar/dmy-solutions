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
    // 每个组分为 m 和 k-m 两部分，对于 m 部，明确要求支持同种(1 或 2)，k-m 部自由分配
    int m  = (k + 1) / 2; // m - 1 = k - m = (k - 1) / 2
    // 0. 先选出x个小组，支持1
    long long r0 = C(n, x);
    cout << "r0: " << r0 << endl;

    // 1. 对于 x 组，每组至少有 m 人支持 1
    // 从 a 中取出 x * m 人分到 x 组, 组内顺序无关
    // $$ P_a^{x * m} / {(m!)}^x   $$
    long long r1 = P(a, x * m) * qpow(inv_fact[m], x) % MOD;
    cout << "r1: " << r1 << endl;
    
    // 2. 对于 n - x 组，每组至少有 m 人支持 2
    // $$ P_{n*k-a}^{(n-x)*m} / (m!)^{n-x} $$
    long long r2 = P(n*k-a, (n-x)*m) * qpow(inv_fact[m], n-x) % MOD;
    cout << "r2: " << r2 << endl;
    
    // 3. 余下 a-x*m 个支持1 和 (n*k-a)-(n-x)*m 个支持2 的人，
    //    分配到剩下的 n*(k-m) 个位置中去
    //    需排除重复情况 (同类支持者在 m部 和 k-m 部都可能出现)
    
    //    支持1的组还有 x*(k-m) 个位置，支持2的组还有(n-x)*(k-m)个位置
    //    在支持1的组里，max{0, a-x*k} <= 支持1的人数 <= min{x*(k-m), a-x*m}
    //    在支持2的组里，max{0, n-a-(n-x)*k} <= 支持2的人数 <= min{(n-x)*(k-m), (n*k-a)-(n-x)*m}
    for (int g = 1; g <= n; g++) {
        for (int i = 0; i < )
    }

}

int main () {
    int n, k, a, x;
    cin >> n >> k >> a >> x;
    init();
    
    solution(n, k, a, x);

    return 0;
}