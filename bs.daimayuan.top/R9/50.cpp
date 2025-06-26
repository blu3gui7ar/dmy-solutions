#include <bits/stdc++.h>
using namespace std;
int main () {
    int n;
    cin >> n;
    int min_odd = INT_MAX, max_odd = INT_MIN, min_even = INT_MAX, max_even = INT_MIN;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        if (x % 2 == 0) {
            if (x < min_even) {
                min_even = x;
            }
            if (x > max_even) {
                max_even = x;
            }
        } else {
            if (x < min_odd) {
                min_odd = x;
            }   
            if (x > max_odd) {
                max_odd = x;
            }
        }
    }
    if (min_odd == INT_MAX || max_even == INT_MIN || min_even == INT_MAX || max_odd == INT_MIN) {
        cout << -1 << endl;
    } else {
        int d1 = abs(min_odd - max_even);
        int d2 = abs(min_even - max_odd);
        cout << max(d1, d2) << endl;
    }
    return 0;
}