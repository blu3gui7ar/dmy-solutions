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

void solution1(int n, int k, int a, int x) {
    int m  = (k + 1) / 2; // m - 1 = (k - 1) / 2
    // 1. 对于 x 组，每组至少有 m 人支持 1
    // 从 a 中取出 x * m 人分到 x 组, 组内顺序无关
    // $$ P_a^{x * m} / {(m!)}^x   $$
    long long r1 = P(a, x * m) * qpow(inv_fact[m], x) % MOD;
    
    cout << "r1: " << r1 << endl;

    // 2. 剩下的a-x*m个支持1的人 加上支持2的人补足到 n * (k -m)人， 分配到所有n个组中，每组最多k-m人
    // 每组取（k - m)个位置，形成n * (k-m)个位置，
    // 剩下a - x * m 人支持1的人 和 n * k - a 个支持2的人中取出 n * (k - m) - (a - x * m) 人
    // 分配到这 n * (k - m) 个位置中, 组内顺序无关
    // $$  C_{n * k - a}^{n * (k - m) - (a - x * m)} * P_{n * (k - m)}^{n * (k - m)} / ((k -m)!)^n $$
    long long r2 = C(n * k -a , n * (k - m) - (a - x * m)) * fact[n * (k - m)] * qpow(inv_fact[k - m], n) % MOD;

    cout << "r2: " << r2 << endl;
    // 3. 对于 n - x组支持2的，每组还剩下 m 个位置， 由余下的人分配，组内位置无关
    // 确认: 余下的人数为 n * k - a - (n * (k - m) - (a - x * m)) = nk - a - nk + nm +a - xm = (n - x) * m
    // $$ P_{(n - x) * m}^{(n - x) * m} / {(m!)}^{n - x}   $$
    long long r3 = fact[(n - x) * m] * qpow(inv_fact[m], n - x) % MOD;
    cout << "r3: " << r3 << endl;
    
    cout << r1 * r2 % MOD * r3 % MOD << endl;
}

void solution2(int n, int k, int a, int x) {
    int m = (k + 1) / 2;
    
    // 1. 分配x组支持1的
    long long r1 = P(a, x * m) * qpow(inv_fact[m], x) % MOD;
    
    // 2. 分配剩余支持1的同学到所有组
    long long r2 = P(n * (k - m), a - x * m) * qpow(inv_fact[k - m], n) % MOD;
    
    // 3. 分配支持2的同学到n-x组
    long long r3 = P(n * k - a, (n - x) * m) * qpow(inv_fact[m], n - x) % MOD;
    
    // 4. 剩余支持2的同学自由分配
    long long remaining_2 = (n * k - a) - (n - x) * m;
    long long r4 = P(n * (k - m), remaining_2) * qpow(inv_fact[k - m], n) % MOD;
    
    cout << r1 * r2 % MOD * r3 % MOD * r4 % MOD << endl;
}

int main () {
    int n, k, a, x;
    cin >> n >> k >> a >> x;
    init();
    
    solution1(n, k, a, x);

    return 0;
}