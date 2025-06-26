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

/**
 * 快速幂算法 (模运算版本)
 * 计算 a^b % MOD 的值
 * 
 * @param a 底数
 * @param b 指数
 * @return 计算结果 a^b % MOD
 */
long long qpow(long long a, long long b) {
    long long res = 1;  // 初始化结果为1
    
    // 使用二进制分解法计算幂
    while (b) {
        // 如果当前二进制位为1，将a乘入结果
        if (b & 1) res = res * a % MOD;
        
        // 将a平方，准备处理下一位
        a = a * a % MOD;
        
        // 右移一位，处理下一个二进制位
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
