#include <bits/stdc++.h>
using namespace std;
int main () {
    int n;
    cin >> n;
    int max = -1;
    int x;
    for (size_t i = 1; i <= n; i++) {
        cin >> x;
        if (x % 2 == 1) {
            if (x > max) {
                max = x;
            }
        }
    }
    
    cout << max << endl;
    return 0;
}