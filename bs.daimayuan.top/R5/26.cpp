#include <bits/stdc++.h>
using namespace std;

vector<int> getPrimeFactors(int n) {
    vector<int> factors;
    if (n < 2) return factors;
    
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            factors.push_back(i);
            while (n % i == 0) {
                n /= i;
            }
        }
    }
    if (n > 1) factors.push_back(n);
    return factors;
}

int main() {
    int N;
    cin >> N;
    
    vector<int> primeFactors = getPrimeFactors(N);
    
    if (primeFactors.size() < 2) {
        cout << -1 << endl;
    } else {
        sort(primeFactors.begin(), primeFactors.end());
        cout << primeFactors[primeFactors.size() - 2] << endl;
    }
    
    return 0;
}