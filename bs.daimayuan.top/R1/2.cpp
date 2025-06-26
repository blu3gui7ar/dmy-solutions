#include <bits/stdc++.h>
using namespace std;
int main () {
    int k;
    cin >> k;
    for (size_t i = 0; i < k; i++) {
        int n, m;
        cin >> n >> m;
        
        if (m % 2 == 0 || n % 2 == 0) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
    return 0;
}