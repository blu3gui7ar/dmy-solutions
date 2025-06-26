#include <bits/stdc++.h>
using namespace std;
int main () {
    long long n;
    cin >> n;
    
    long long mod_sum = 0;
    
    // 5 / 5 = 1 => 5 / (1 + 1) = 2 => (l, r] = (2, 5] => mod_sum += (5 % 3 + 5 % 5) * (5 - 2) / 2
    for (long long r = n, l; r >= 2; ) {
        int x = n / r;
        l = n / (x + 1);
        mod_sum += (n % (l + 1) + n % r) * (r - l) / 2;
        r = l;
    }
    
    cout << mod_sum << endl;
    return 0;
}