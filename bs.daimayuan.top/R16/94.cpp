#include <bits/stdc++.h>
using namespace std;


/**
 * $$ x - a_i + min(x - a_i, b_i) >= a_{i+1} $$
 * 
 *  当 $$ min(x - a_i, b_i) = x - a_i => x <= a_i + b_i $$
 *
 *  $$ x - a_i + x - a_i >= a_{i+1} $$
 *  $$ x >=  a_i + a_{i+1} / 2 $$
 * 
 *  当 $$ min(x - a_i, b_i) = b_i => x >= a_i + b_i $$
 *  $$ x - a_i + b_i >= a_{i+1} $$
 *  $$ x >= a_i + a_{i+1} - b_i $$
 */
long back_step(long a0, long b0, long a1) {
    if (2 * b0 > a1) {
        return a0 + a1 / 2 + (a1 % 2); 
    } else {
        return a0 + a1 - b0;
    }
}

int main () {
    int T;
    cin >> T;

    for(int i = 0; i < T; i++) {
        int n;
        cin >> n;
        vector<long> a(n);
        vector<long> b(n);
        for (int j = 0; j < n; j++) {
            cin >> a[j];
        }
        for (int j = 0; j < n; j++) {
            cin >> b[j];
        }
        

        long x = a[n - 1];
        // cout << x << ' ';
        for (int j = n - 2; j >= 0; j--) {
            x = back_step(a[j], b[j], x);
            // cout << x << ' ';
        }
        // cout << endl;

        cout << x << endl;
    }
    return 0;
}