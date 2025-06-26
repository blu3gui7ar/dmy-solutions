
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

/**
 * 计算long long类型数值的整数平方根（向下取整）
 * 使用二分查找法实现，避免浮点数精度问题
 * @param x 需要计算平方根的非负整数
 * @return 返回x的整数平方根（即最大的整数n满足n² ≤ x）
 */
long long sqrt_qs(long long x) {
    // 处理边界情况：0和1的平方根就是它们自己
    if (x <= 1) return x;
    
    // 初始化二分查找范围：1到x
    long long l = 1, r = x, ans = 0;
    
    // 二分查找主循环
    while (l <= r) {
        // 计算中间值，使用防溢出的写法
        long long mid = l + (r - l) / 2;
        
        // 检查mid是否可能是平方根
        if (mid <= x / mid) {  // 等价于 mid² ≤ x，但避免溢出
            // 如果mid² ≤ x，记录当前mid并向右搜索更大的可能值
            l = mid + 1;
            ans = mid;  // 更新当前最佳答案
        } else {
            // 如果mid² > x，向左搜索更小的值
            r = mid - 1;
        }
    }
    // 返回找到的最大整数n满足n² ≤ x
    return ans;
}