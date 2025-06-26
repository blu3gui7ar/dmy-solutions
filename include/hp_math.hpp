#include <bits/stdc++.h>
using namespace std;

// 高精度整数输入
vector<int> hp_input(istream in) {
    string s;
    in >> s;
    vector<int> num;
    for (int i = static_cast<int>(s.size()) - 1; i >= 0; --i) {
        num.push_back(s[i] - '0');
    }
    return num;
}

// 将高精度整数转换为字符串
string hp_tostr(const vector<int>& num) {
    string result;
    for (int i = static_cast<int>(num.size()) - 1; i >= 0; --i) {
        result += to_string(num[i]);
    }
    return result;
}

// 高精度整数比较
bool hp_less(const vector<int>& a, const vector<int>& b) {
    if (a.size() != b.size()) return a.size() < b.size();
    for (int i = static_cast<int>(a.size()) - 1; i >= 0; --i) {
        if (a[i] != b[i]) return a[i] < b[i];
    }
    return false;
}

// 高精度整数加法
vector<int> hp_add(const vector<int>& a, const vector<int>& b) {
    vector<int> result;
    int carry = 0;
    for (size_t i = 0; i < max(a.size(), b.size()) || carry; ++i) {
        int cur = carry;
        if (i < a.size()) cur += a[i];
        if (i < b.size()) cur += b[i];
        result.push_back(cur % 10);
        carry = cur / 10;
    }
    return result;
}

// 高精度整数减法, 确保 a >= b
vector<int> hp_minus(const vector<int>& a, const vector<int>& b) {
    vector<int> result;
    int borrow = 0;
    for (size_t i = 0; i < max(a.size(), b.size()); ++i) {
        int a_digit = i < a.size() ? a[i] : 0;
        int b_digit = i < b.size() ? b[i] : 0;
        int r_digit = a_digit - b_digit - borrow;
        if (r_digit < 0) {
            r_digit += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }
        result.push_back(r_digit);
    }
    assert(borrow == 0);
    // 去除前导零
    while (result.size() > 1 && result.back() == 0) result.pop_back();
    return result;
}

// 高精度整数减法, 输出符号和结果
pair<char, vector<int>> hp_minus_signed(const vector<int>& a, const vector<int>& b) {
    if (hp_less(a, b)) {
        return {'-', hp_minus(b, a)};
    } else {
        return {'+', hp_minus(a, b)};
    }
}

vector<int> hp_minus_abs(const vector<int>& a, const vector<int>& b) {
    if (hp_less(a, b)) {
        return hp_minus(b, a);
    } else {
        return hp_minus(a, b);
    }
}

// 高精度整数除法
vector<int> hhp_divide(const vector<int>& a, int b) {
    vector<int> result;
    int remainder = 0;
    for (int i = static_cast<int>(a.size()) - 1; i >= 0; --i) {
        remainder = remainder * 10 + a[i];
        result.push_back(remainder / b);
        remainder %= b;
    }
    reverse(result.begin(), result.end());
    // 去除前导零
    while (result.size() > 1 && result.back() == 0) result.pop_back();
    return result;
}

// 高精度大数除法（大数/大数）
vector<int> hp_divide(const vector<int>& a, const vector<int>& b) {
    // 特殊情况处理
    if (b.size() == 1 && b[0] == 0) {
        throw runtime_error("Division by zero");
    }
    if (hp_less(a, b)) {
        return vector<int>(1, 0); // 返回0
    }
    if (!hp_less(b, a) && !hp_less(a, b)) { // a == b
        return vector<int>(1, 1); // 返回1
    }

    vector<int> current;
    vector<int> result;
    vector<int> one(1, 1);

    // 从最高位开始处理
    for (int i = static_cast<int>(a.size()) - 1; i >= 0; --i) {
        current.insert(current.begin(), a[i]); // 将被除数的下一位加入current
        // 去除前导零
        while (current.size() > 1 && current.back() == 0) {
            current.pop_back();
        }
        
        // 估算商
        int quotient = 0;
        while (!hp_less(current, b)) {
            current = hp_minus(current, b);
            quotient++;
        }
        
        result.push_back(quotient);
    }
    
    reverse(result.begin(), result.end());

    // 去除前导零
    while (result.size() > 1 && result.back() == 0) result.pop_back();
    return result;
}

// 高精度整数乘法
vector<int> hp_multiply(const vector<int>& a, const vector<int>& b) {
    vector<int> result(a.size() + b.size());
    for (size_t i = 0; i < a.size(); ++i) {
        for (size_t j = 0; j < b.size(); ++j) {
            result[i + j] += a[i] * b[j];
            result[i + j + 1] += result[i + j] / 10;
            result[i + j] %= 10;
        }
    }
    // 去除前导零
    while (result.size() > 1 && result.back() == 0) result.pop_back();
    return result;
}


// 高精度平方根
vector<int> hp_sqrt(const vector<int>& n) {
    // 初始猜测值为n的一半
    vector<int> x = hhp_divide(n, 2);
    vector<int> prev_x;
    
    // 设置一个足够小的精度阈值
    vector<int> epsilon(1, 1);  // 0.1
    
    int i = 0;
    do {

        prev_x = x;
        // x = (x + n/x)/2
        vector<int> n_div_x = hp_divide(n, x);  // 简单除法，实际应实现高精度除法
        x = hhp_divide(hp_add(x, n_div_x), 2);
        
        // 去除前导零
        while (x.size() > 1 && x.back() == 0) x.pop_back();
    } while (i < 100 && hp_less(epsilon, hp_minus_abs(prev_x, x)));  // 当变化小于epsilon时停止
    
    return x;
}
