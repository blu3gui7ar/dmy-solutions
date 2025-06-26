#include <bits/stdc++.h>
using namespace std;
int main () {
    int l, r, k;
    cin >> l >> r >> k;

    int n = r / k  - l / k + (l % k == 0 ? 1 : 0);
    
    cout << n << endl;
    return 0;
}