#include <bits/stdc++.h>
using namespace std;
int main () {
    int n;
    bool find = false;
    cin >> n;
    char c[1000001]= {0};
    int idx = 0;
    for (int i = 0; i < n; i++) {
        char a;
        cin >> a;
        if (a == 'D' || a == 'M' || a == 'Y') {
            find = true;
            c[idx++] = a;
        }
    }
    if (!find) {
        cout << -1 << endl;
    } else {
        cout << c << endl;
    }
    return 0;
}