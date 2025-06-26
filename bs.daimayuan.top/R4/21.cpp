#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e6 + 1;
vector<bool> is_prime(MAX, true);
map<int, int> prime_counts;

void sieve(int n) {
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= n; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= n; j += i) {
                is_prime[j] = false;
            }
        }
    }
}

void factorize(int x) {
    for (int i = 2; i * i <= x; i++) {
        if (is_prime[i]) {
            while (x % i == 0) {
                prime_counts[i]++;
                x /= i;
            }
        }
    }
    if (x > 1) {
        prime_counts[x]++;
    }
}

int main() {
    sieve(MAX - 1);
    
    int n;
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        factorize(x);
    }
    
    for (auto &p : prime_counts) {
        if (p.second > 0) {
            cout << p.first << " " << p.second << " ";
        }
    }
    cout << endl;
    return 0;
}