#pragma once

#include <bits/stdc++.h>
using namespace std;

/**
 * @brief 计算两个数的最大公约数(GCD)
 * @tparam T 数值类型，要求支持模运算(%)
 * @param a 第一个数
 * @param b 第二个数
 * @return T 返回a和b的最大公约数
 * @note 使用欧几里得算法(辗转相除法)实现
 *       时间复杂度: O(log min(a,b))
 */
template<typename T> T gcd(T a, T b) {
    if (a < 0) a = -a;  // 处理负数
    if (b < 0) b = -b;  // 处理负数
    // 递归终止条件：当b为0时，a就是GCD
    // 否则继续计算gcd(b, a % b)
    return b == 0 ? a : gcd(b, a % b);
}

/**
 * @brief 获取一个数的所有因数
 * @tparam T 数值类型，要求支持除法运算(/)
 * @param n 要分解因数的数字
 * @return vector<T> 包含所有因数的vector，未排序
 * @note 时间复杂度: O(√n)
 *       算法原理: 
 *         1. 遍历1到√n的所有整数
 *         2. 当i是n的因数时，同时记录i和n/i
 *         3. 避免重复记录平方数的情况(i == n/i)
 */
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

/**
 * @brief 质因数分解，返回质因数及其幂次的映射
 * @tparam T 数值类型，要求支持除法运算(/)
 * @param n 要进行质因数分解的数字
 * @return map<T, T> 键为质因数，值为对应幂次
 * @note 时间复杂度: O(√n)
 *       算法原理:
 *         1. 从2开始遍历到√n
 *         2. 当i是n的因数时，记录i并将n中所有i的因子除尽
 *         3. 最后如果n>1，说明n本身是一个质数
 * @example 
 *     factorize(12) -> {{2:2}, {3:1}}
 *     factorize(17) -> {{17:1}}
 */
template<typename T> map<T, T> factorize(T n) {
    map<T, T> factors;
    if (n < 2) return factors;  // 小于2的数没有质因数
    
    for (T i = 2; i * i <= n; ++i) {
        if (n % i == 0) {       // 发现一个质因数
            factors[i] = 0;     // 初始化幂次为0
            while (n % i == 0) { // 计算该质因数的幂次
                n /= i;
                factors[i]++;   // 幂次加1
            }
        }
    }
    
    if (n > 1) factors[n] = 1; // 处理最后剩下的质数
    return factors;
}


/**
 * @brief 埃拉托斯特尼筛法，生成素数表
 * @tparam T 数值类型
 * @param n 筛选范围上限
 * @param is_prime 预分配好的vector，将被填充为素数标记表
 * @note 时间复杂度: O(n log log n)
 *       算法原理:
 *         1. 初始化所有数为素数
 *         2. 从2开始，将每个素数的倍数标记为非素数
 *         3. 优化：从i*i开始标记，因为更小的倍数已被更小的素数标记过
 * @pre is_prime应已预分配足够空间(is_prime.size() > n)
 * @post is_prime[i]为true表示i是素数
 */
template<typename T> void sieve(T n, vector<bool> &is_prime) {
    is_prime[0] = is_prime[1] = false;  // 0和1不是素数
    
    // 外层循环：遍历2到√n
    for (T i = 2; i * i <= n; i++) {
        if (is_prime[i]) {  // 如果i是素数
            // 内层循环：标记i的所有倍数为非素数
            // 从i*i开始，因为更小的倍数已被更小的素数标记过
            for (T j = i * i; j <= n; j += i) {
                is_prime[j] = false;
            }
        }
    }
}

/**
 * @brief 欧拉筛法/线性筛法，生成素数表
 * @tparam T 数值类型
 * @param n 筛选范围上限
 * @param is_prime 预分配好的vector，将被填充为素数标记表
 * @note 时间复杂度: O(n)
 *       算法原理:
 *         1. 初始化所有数为素数
 *         2. 从2开始，将每个素数的倍数标记为非素数
 *         3. 优化：每个数只被标记一次，且标记时使用最小质因数
 * @pre is_prime应已预分配足够空间(is_prime.size() > n)
 * @post is_prime[i]为true表示i是素数
 */
template<typename T> void euler_prime(T n, vector<bool> &is_prime) {
    vector<T> primes;
    is_prime[0] = is_prime[1] = false;  // 0和1不是素数
    for (T i = 2; i <= n; i++) {
        if (is_prime[i]) {  // 如果i是素数
            primes.push_back(i);
        } 
        for (T p : primes) {
            if (i * p > n) break; // 超出范围，停止标记
            is_prime[i * p] = false; // i * p不是素数
            if (i % p == 0) break; // 找到i的最小质因数p，停止标记，保证每个数只被标记一次
        }
    }
}

/**
 * @brief 基于素数表的质因数分解（带缓存优化）
 * @tparam T 数值类型
 * @param x 要分解的数
 * @param is_prime 预先生成的素数表（通过sieve函数生成）
 * @param prime_counts 用于存储质因数及其幂次的映射（输出参数）
 * @note 时间复杂度: O(√x) 但实际更快，因为只检查已知素数
 *       算法特点:
 *         1. 利用预先生成的素数表加速分解过程
 *         2. 只检查素数表中的数是否为因数
 *         3. 结果存储在外部传入的map中，便于多次调用累积结果
 * @pre is_prime应已通过sieve函数正确初始化
 * @post prime_counts将包含x的所有质因数及其幂次
 */
template<typename T> void factorize_cached(T x, vector<bool> &is_prime, map<T, T> &prime_counts) {
    // 遍历2到√x的所有可能因数
    for (T i = 2; i * i <= x; i++) {
        if (is_prime[i]) {  // 只检查素数
            while (x % i == 0) {  // 处理每个素因数的所有幂次
                prime_counts[i]++;  // 增加该素因数的计数
                x /= i;             // 除去该素因数
            }
        }
    }
    // 处理最后剩下的质数（如果x>1）
    if (x > 1) {
        prime_counts[x]++;
    }
}

/**
 * @brief 使用线性筛法预处理欧拉函数φ(1)到φ(max_n)
 * @tparam T 数值类型
 * @param x 未使用的参数（可考虑移除）
 * @return vector<int> 包含1到max_n的欧拉函数值
 * @note 欧拉函数:
 *       对于正整数n，φ(n)表示： 1 ≤ k ≤ n 且 gcd(k, n) = 1 的整数k的个数
 *       关键性质:
 *       积性函数：如果m和n互质，则φ(mn) = φ(m)φ(n)
 *       质数幂次：对于质数p，φ(p^k) = p^k - p^(k-1)
 *       一般公式：若n的质因数分解为n = Πp_i^k_i，则： φ(n) = n × Π(1 - 1/p_i)
 * 
 *       算法时间复杂度: O(n log log n)
 *       算法原理:
 *         1. 初始化φ(i)=i
 *         2. 对每个质数p，更新其倍数的φ值:
 *            φ(i) = φ(i) * (1 - 1/p) = φ(i) - φ(i)/p
 * @pre 需要预先定义max_n常量作为计算范围
 * @post 返回的vector索引即为对应的n值，phi[n]即为φ(n)
 */
template<typename T> vector<int> euler_phi_slow(T MAX) {
    vector<T> phi(MAX + 1);  // 创建大小为max_n+1的vector
    iota(phi.begin(), phi.end(), (T)0);  // 初始化为φ(i)=i
    
    // 线性筛法处理
    for (T p = 2; p <= MAX; ++p) {
        if (phi[p] == p) {  // 当φ(p)=p时，p是质数
            // 更新p的所有倍数的欧拉函数值
            for (T i = p; i <= MAX; i += p) {
                phi[i] -= phi[i] / p;  // φ(i) -= φ(i)/p
            }
        }
    }
    return phi;
}


/**
 * @brief 使用线性筛法计算欧拉函数φ(1)到φ(MAX)
 * @tparam T 数值类型
 * @param MAX 计算范围上限
 * @return vector<T> 包含1到MAX的欧拉函数值
 * @note 欧拉函数φ(n)表示小于等于n的正整数中与n互质的数的个数
 *       关键性质:
 *       1. 对于质数p，φ(p) = p-1
 *       2. 若n = p^k，则φ(n) = p^k - p^(k-1)
 *       3. 若m和n互质，则φ(mn) = φ(m)φ(n)
 *       时间复杂度: O(n)
 *       算法原理:
 *         1. 利用线性筛法同时标记质数和计算欧拉函数
 *         2. 根据i和p的关系分两种情况处理：
 *            - i是p的倍数：φ(i*p) = φ(i)*p
 *            - i不是p的倍数：φ(i*p) = φ(i)*(p-1)
 */
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
