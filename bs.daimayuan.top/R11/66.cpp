#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353;

template<typename T> vector<T> euler_phi(T MAX) {
    // 初始化欧拉函数数组，大小为MAX+1
    vector<T> phi(MAX + 1);
    // 存储质数的容器
    vector<T> primes;
    // φ(1) = 1
    phi[1] = 1;
    
    // 线性筛法计算欧拉函数
    for (T i = 2; i <= MAX; i++) {
        // 如果phi[i]为0，说明i是质数
        if (phi[i] == 0) {
            // 质数的欧拉函数值为i-1
            phi[i] = i - 1;
            primes.push_back(i);
        }
        
        // 用已找到的质数筛i的倍数
        for (T p : primes) {
            // 超过最大值则停止
            if (i * p > MAX) break;
            
            // 分两种情况计算欧拉函数：
            if (i % p == 0) {
                // 情况1：p是i的质因数
                // φ(i*p) = φ(i) * p
                phi[i * p] = phi[i] * p;
                break;  // 保证每个数只被最小质因数筛一次
            } else {
                // 情况2：p不是i的质因数
                // φ(i*p) = φ(i) * (p-1)
                phi[i * p] = phi[i] * (p - 1);
            }
        }
    }
    return phi;
}

int main () {
    int n;
    cin  >> n;

    vector<int> phi = euler_phi(n);
    vector<long long> prefix_sum_phi(n + 1);
    for (int i = 1; i <= n; i++) {
        prefix_sum_phi[i] = (prefix_sum_phi[i - 1] + phi[i]) % MOD;
    }

    long long sum = 0;
    for (int d = 1; d <= n; d++) {
        // 计算公约数为d的数对数量
        // m = n / d 表示n 以内最多可取d的m倍
        // 使用m的 欧拉函数前缀和，即可算出数对的组数
        // 对于每组数对， 存在 i, j 对称的两对，但是 1, 1 这对自对称
        // 所以总对数为 2 * phi(m)前缀和 - 1
        int m = n / d;
        long long pair_count = (2 * prefix_sum_phi[m] - 1) % MOD;
        sum = (sum + d * pair_count ) % MOD;
    }
    
    cout << sum << endl;

    return 0;
}