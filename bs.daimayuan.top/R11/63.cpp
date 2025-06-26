#include <bits/stdc++.h>
using namespace std;
int main () {
    long long v0, a, v1, t;
    cin >> v0 >> a >> v1 >> t;
    
    v0 = v0 * 10000;
    v1 = v1 * 10000;
    t = t * 10000;
    
    long long tt = (v1 - v0) / a;
    
    long long s = 0;
    if (t <= tt) {
        s = v0 * t + 0.5 * a * t * t ;
    } else {
        s = v0 * tt + 0.5 * a * tt * tt;
        s += v1 * (t - tt);
    }
    
    cout << fixed << setprecision(3) << (double)s / 100000000 << endl;
    return 0;
}