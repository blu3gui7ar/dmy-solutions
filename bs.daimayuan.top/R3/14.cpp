#include <bits/stdc++.h>
using namespace std;
int main () {
    int c = 998244353;
    int n, k, a;
    long long ma = 0;
    cin >> n >> k;
    
    for (int i = 0; i < n; i++) {
        cin >> a;
        // cout << a << ": ";
        long long m = 1;
        for (int j = 0; j < k; j++) {
            m = m * a % c;
            // cout << m << ",";
        }
        // cout << endl;
        ma = (ma + m) % c;
    }
    
    cout << ma % c << endl;
    return 0;
}