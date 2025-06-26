#include <iostream>
using namespace std;

// 计算排列数A(n,k)
int permutation(int n, int k) {
    if (k > n) return 0;
    
    int result = 1;
    for (int i = 0; i < k; i++) {
        result *= (n - i);
    }
    
    return result;
}

int main() {
    int n = 5, k = 3;
    cout << "A(" << n << "," << k << ") = " << permutation(n, k) << endl;
    return 0;
}
