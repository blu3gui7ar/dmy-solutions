#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
 
const int MAXN = 1e6 + 1;
int fact[MAXN], inv_fact[MAXN];

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

void init(int max) {
    fact[0] = 1;
    for (int i = 1; i < max; i++) {
        fact[i] = 1LL * fact[i-1] * i % MOD;
    }
    inv_fact[max-1] = qpow(fact[max-1], MOD-2);
    for (int i = max-2; i >= 0; i--) {
        inv_fact[i] = 1LL * inv_fact[i+1] * (i+1) % MOD;
    }
}

/**
 * 对于每个节点，其子树的拓扑排序数是其所有子节点子树拓扑排序数的乘积
 * 然后乘以这些子树之间排列组合的可能性（用组合数计算）
 * 
 * 对于某一节点, 构造该节点为根的拓扑排序子序列：
 * 1. 对该节点每棵子树，获得其拓扑排序序列
 * 2. 对于各子树的有效拓扑排序序列，在保持序列内节点不变的前提下，合并成一个序列。
 * 3. 当前节点 + 合并后序列 即为一个有效的拓扑排序序列
 * 
 * 这样，对于任意节点，有递推关系:
 *  有效拓扑排序序列的方案数 = 子树有效方案数的积 * 序列合并方案数
 *
 *  $$ F(n) = \prod_{i=1}^k F(i) * S! / \prod_{i=1}^k Si! $$
 *
 * 序列合并方案数:
 *   对于节点数分别为m,n的两棵子树，可形成长度为(m + n)的序列，其中子树节点顺序固定。
 *   可以先取(m+n)的全排列，然后先后除以m!和n!, 以获得两树在保持顺序前提下合并的方案数。
 *   那么对于k个子树，同理可得合并方案数为 $$ S! / (s1! * s2! * ... * sk!) $$ (其中S为所有子树节点数和)。
 */
pair<int, int> dfs(int node, vector<vector<int>>& children) {
    // res: 当前子树的有效排列数
    // size: 当前子树的总节点数(包括自己)
    int res = 1, size = 1;
    
    // 遍历所有子节点
    for (auto child : children[node]) {
        // 递归处理子节点
        auto [child_res, child_size] = dfs(child, children);
        
        // 合并排列数:
        // 1. 乘以子树的排列数
        // 2. 乘以子节点排列的逆元(相当于除以子节点排列的阶乘)
        
        res = 1LL * res * child_res % MOD; // $$ \prod_{i=1}^k F(i) $$
                                           
        res = 1LL * res * inv_fact[child_size] % MOD; // $$ \prod_{i=1}^k 1/Si! $$
        
        // 累加子树大小
        size += child_size;
    }
    
    // 乘以当前节点子树的排列组合数:
    // (size-1)! 表示所有子树的排列方式
    res = 1LL * res * fact[size-1] % MOD; // $$ S! $$
    
    return {res, size};
}

/**
 * 有向无环图（DAG）的拓扑排序方案数
 * 
 * 拓扑排序的方案数在 DAG 中是一个经典问题，
 * 但直接计算所有可能的方案数在节点数较大时（如 n=1e5 ）
 * 会面临指数级复杂度，无法直接求解。
 * 
 * 不过根据题目中 “每个节点的前置节点唯一” 的条件（pi表示唯一前驱），
 * 图的结构实际是一棵树（以0为根）。
 * 
 */
int main() {
    int n;
    cin >> n;
    init(n+1);
    vector<vector<int>> children(n+1, vector<int>());
    int pi = 0;
    for (int i = 1; i <= n; i++) {
        cin >> pi;
        children[pi].push_back(i);
    }
    
    auto [ans, _] = dfs(0, children);
    cout << ans << endl;

    return 0;
}