#include <iostream>
#include <vector>
using namespace std;

// 方法1：使用递归计算组合数
int combinationRecursive(int n, int k) {
    if (k == 0 || k == n)
        return 1;
    return combinationRecursive(n-1, k-1) + combinationRecursive(n-1, k);
}

// 方法2：使用动态规划计算组合数
int combinationDP(int n, int k) {
    vector<vector<int>> dp(n+1, vector<int>(k+1, 0));
    
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= min(i, k); j++) {
            if (j == 0 || j == i)
                dp[i][j] = 1;
            else
                dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
        }
    }
    
    return dp[n][k];
}

// 方法3：使用公式直接计算组合数
int combinationFormula(int n, int k) {
    if (k > n - k)
        k = n - k;
    
    long long result = 1;
    for (int i = 0; i < k; i++) {
        result *= (n - i);
        result /= (i + 1);
    }
    
    return result;
}

int main() {
    int n = 5, k = 2;
    
    cout << "C(" << n << "," << k << ") = " << combinationRecursive(n, k) << endl;
    cout << "C(" << n << "," << k << ") = " << combinationDP(n, k) << endl;
    cout << "C(" << n << "," << k << ") = " << combinationFormula(n, k) << endl;
    
    return 0;
}
