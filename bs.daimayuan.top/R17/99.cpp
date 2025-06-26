#include <bits/stdc++.h>
using namespace std;

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

int main () {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    vector<int> factors = get_factors(n);
    sort(factors.begin(), factors.end());
    for (int factor: factors) {
        int support1 = 0;
        int support2 = 0;
        int groups = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] == 1) {
                support1++;
            } else {
                support2++;
            }
            
            if (i % factor == factor - 1) {
                if (support1 > support2) {
                    groups++;
                }
                support1 = 0;
                support2 = 0;
            }
        }
        cout << groups << endl;
    }
    
    return 0;
}