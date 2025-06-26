#include <bits/stdc++.h>
using namespace std;


// 使用牛顿迭代法计算整数平方根
long long sqrt_newton(long long x) {
    if (x <= 1) return x;  // 处理0和1的特殊情况
    
    // 初始猜测值，选择x/2作为起点
    long long guess = x / 2;
    // 牛顿迭代：guess = (guess + x/guess)/2
    while (guess > x / guess) {  // 当guess² > x时继续迭代
        guess = (guess + x / guess) / 2;
    }
    return guess;
}

// 使用牛顿迭代法解方程 x² + x - c = 0
long long solve_equation(long long c) {
    if (c == 0) return 0;  // 处理c=0的特殊情况
    
    // 初始猜测值，选择sqrt(c)作为起点
    long long x = sqrt_newton(c);
    // 牛顿迭代公式：x = x - (x² + x - c)/(2x + 1)
    while (true) {
        long long fx = x * x + x - c;
        if (fx == 0) break;  // 找到精确解
        
        long long derivative = 2 * x + 1;
        long long next_x = x - fx / derivative;
        
        // 当迭代不再变化时停止
        if (next_x == x) break;
        x = next_x;
    }
    return x;
}


/**
 *  第x级需要经验 k * x^2, 题数为k * x
 *  
 *  k * x * (x + 1) / 2 = n
 *  x * (x + 1) = 2n / k
 *  x^2 + x - 2n / k = 0
 *  
 *  用牛顿迭代法解方程, 获得x, 再调整
 *  
 */
int main () {
    long long n, k;
    cin >> n >> k;
    
    long long c = 2 * n / k;
    long long x = solve_equation(c);
    long long count = k * x * (x + 1) / 2;
    
    // 调整x, 使count <= n
    while (count > n) {
        x = x - 1;
        count = k * x * (x + 1) / 2;
    }
    
    if (count == n) {
        cout << x  << " " << 0 << endl;
    } else {
        long long score = (n - count) * (x + 1);
        cout << x + 1 << " " << score << endl;
    }
    return 0;
}