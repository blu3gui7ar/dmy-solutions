#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
int main () {
    int n, x;
    cin >> n >> x;
    int count = 0;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        
        if (a == x || b == x) {
            count++;
        }
    }
    cout << count << endl;
    return 0;
}