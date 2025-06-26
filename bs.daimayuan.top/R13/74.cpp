#include <bits/stdc++.h>
using namespace std;
int main () {
    int n, m;
    cin >> n >> m;
    
    for (int i = 0; i < n; i++) {
        if (m > 9) {
            cout << 9;
            m -= 9;
        } else{
            cout << m;
            m = 0;
        }
    }
    return 0;
}