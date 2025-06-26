#include <bits/stdc++.h>
using namespace std;
int main () {
    int n, m;
    cin >> n >> m;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    sort(a.begin(), a.end());
    
    long long weight = __LONG_LONG_MAX__;
    for (int i = 0; i < m; i++) {
        long long w = a[n - m * 2 + i] * a[n - i - 1];
        if (w < weight) {
            weight = w;
        }
    } 
    cout << weight << endl;
    return 0;
}