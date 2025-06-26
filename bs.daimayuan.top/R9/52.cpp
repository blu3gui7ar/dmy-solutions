#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
const int MAXN = 5005;

long long fact[MAXN], inv_fact[MAXN];
/*
在模运算中，模逆元和除法的关系非常关键。让我用中文解释清楚：

模运算中的除法问题
在普通算术中，a/b = a × (1/b)。但在模运算中，我们不能直接做除法，因为分数在模运算中没有定义。

模逆元的定义
数 b 在模 MOD 下的逆元是一个整数 x，满足：
b × x ≡ 1 (mod MOD)
这个 x 就记作 $$ b^{-1} $$ 或 inv(b)，称为 b 的模逆元。

除法与逆元的关系
在模 MOD 下：
a / b (mod MOD) 
= (a / b (mod MOD)) * 1
= (a / b (mod MOD)) * (b * inv(b) (mod MOD))
= (a / b) * (b * inv(b)) (mod MOD)
= a * inv(b) (mod MOD)

既:
a / b ≡ a × inv(b) (mod MOD)
也就是说，模运算中的"除法"实际上是通过乘以逆元来实现的。

费马小定理的应用
当 p 是质数时（如题目中的 998244353）, 有：
$$ b^{p-1} \equiv 1 (mod\ p) $$
$$ b^{p-2} \equiv b^{p-1} / b \equiv 1 * b^{-1} (mod\ p) \equiv b^{-1} (mod\ p) $$
所以，当 p 是质数时，b 的逆元就是 b^(p-2)。
这就是为什么代码中用快速幂 qpow(b, MOD-2) 来计算逆元。

实际例子
比如计算 6/2 mod 5：

先求 2 的逆元：2^(5-2)=8 ≡ 3 (mod 5)
所以 6/2 ≡ 6×3 ≡ 18 ≡ 3 (mod 5)
*/
// 快速幂计算逆元
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
    
    // 阶乘模逆元计算: 预处理逆阶乘
    // $$ x_n * n! \equiv 1 (mod\ p) $$
    // step1: 初始值
    // $$ x_n = (n!)^{p-2} $$
    inv_fact[MAXN-1] = qpow(fact[MAXN-1], MOD-2);
    // step2: 递推
    // $$ x_{n} * n * (n - 1)! * x_{n-1} \equiv x_{n-1} (mod\ p) $$
    // 由于 $$ x_{n-1} * (n-1)! \equiv 1 (mod\ p) $$
    // $$ x_{n} * n \equiv x_{n-1} (mod\ p) $$
    for (int i = MAXN-2; i >= 0; i--) {
        inv_fact[i] = inv_fact[i+1] * (i+1) % MOD;
    }
}

long long C(int n, int i) {
    if (i < 0 || i > n) return 0;
    return fact[n] * inv_fact[i] % MOD * inv_fact[n-i] % MOD;
}

int main () {
    init(); // 添加这行初始化
    int a,b,c,n,m;
    cin >> a >> b >> c >> n >> m;
    
    // step1: 从b出选出 Cb 人 0 <= Cb <= min(b, n+m) , 有 $$ C_b^{Cb} $$ 种方案
    // step2: 把选出的人分配给小N(Nb)和小M(Cb - Nb), 有 $$ C_{Cb}^{Nb} $$ 种方案
    // step3: 从a中选出 Na = n - Nb, 有 $$ C_a^{n - Nb} $$ 种方案
    // step4: 从c中选出 Nc = m - Mb = m - (Cb - Nb), 有 $$ C_c^{m - (Cb - Nb)} $$ 种方案
    //
    // 总体计算式为: $$ \sum_{i=0}^{min(b, n+m)} \sum_{j=max(0, n-b)}^{min(n,i)} C_b^i * C_i^{j} * C_a^{n - j} * C_c^{m - i + j} $$
    //

    long long sum = 0;
    int s1_limit = min(b, n+m);
    // cout << "s1_limit: " << s1_limit << endl;
    for (int i = 0; i <= s1_limit; i++) {
        long long c_b_i = C(b, i); 
        int s2_limit = min(n,i);
        // cout << "s2_limit: " << s2_limit << endl;
        for (int j = 0; j <= s2_limit; j++) {
            long long c_i_j = C(i, j);
            long long c_a_n_j = C(a, n - j);
            long long c_c_m_i_j = C(c, m - i + j);
            long long step_sum = c_b_i * c_i_j % MOD * c_a_n_j % MOD * c_c_m_i_j % MOD;
            // cout << "Cb:" << i << ", Nb:" << j << ", Na:" << n-j << ", Mb:" << i - j << ", Mc:" << m - (i - j) << endl;
            // cout << c_b_i << " * " << c_i_j << " * " << c_a_n_j << " * " << c_c_m_i_j << " = " <<  step_sum << endl;
            sum = (sum + step_sum) % MOD;
        }
    }
    cout << sum << endl;
    return 0;
}