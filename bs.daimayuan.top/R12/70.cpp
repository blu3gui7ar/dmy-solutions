#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;

template<typename T> vector<T> get_factors(T n) {
    vector<T> factors;
    // 只需遍历到√n即可
    for (T i = 1; i * i <= n; ++i) {
        if (n % i == 0) {  // 如果i是n的因数
            factors.push_back(i);  // 记录i
            if (i != n / i) {  // 避免平方数重复记录
                factors.push_back(n / i);  // 记录对应的另一个因数
            }
        }
    }
    return factors;
}

template<typename T> vector<int> euler_phi(T x) {
    vector<T> phi(x + 1);  // 创建大小为max_n+1的vector
    iota(phi.begin(), phi.end(), (T)0);  // 初始化为φ(i)=i
    
    // 线性筛法处理
    for (T p = 2; p <= x; ++p) {
        if (phi[p] == p) {  // 当φ(p)=p时，p是质数
            // 更新p的所有倍数的欧拉函数值
            for (T i = p; i <= x; i += p) {
                phi[i] -= phi[i] / p;  // φ(i) -= φ(i)/p
            }
        }
    }
    return phi;
}

/**
 * @notes:
 * gcd(i, N) 为N的约数
 * gcd(gcd(i,N),gcd(j,N)) 为N的两个约数的最大公约数
 * 
 * 设 di = gcd(i, N), 则 count(i) = φ(N / di)
 * 原题可转化为：
 * ∑ gcd(di, dj) * count(i) * count(j)
 * = ∑ gcd(di, dj) * φ(N / di) * φ(N / dj) 
 */
int main () {
    int n;
    cin >> n;

    vector<int> phi = euler_phi(n);
    vector<int> factors = get_factors(n);
    
    long long rs = 0;
    for (int f1: factors) {
        for (int f2: factors) {
            int gcdf = gcd(f1, f2);
            rs = (rs + 1LL * gcdf % MOD * phi[n / f1] % MOD * phi[n / f2] % MOD) % MOD;
        }
    }
    cout << rs << endl;
    return 0;
}