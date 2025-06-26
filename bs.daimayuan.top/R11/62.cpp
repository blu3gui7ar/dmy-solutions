#include <bits/stdc++.h>
using namespace std;
int main () {
    int n;
    int a = INT_MAX, b = INT_MAX, c = INT_MAX, x;
    int ia = 0, ib = 0, ic = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        
        if (a > x) {
            c = b;
            ic = ib;
            b = a;
            ib = ia;
            a = x;
            ia = i;
        } else if (b > x) {
            c = b;
            ic = ib;
            b = x;
            ib = i;
        } else if (c > x) {
            c = x;
            ic = i;
        }
        
    }
    
    for (int i = 0; i < n; i++) {
        if (i == ia) 
            cout << a << " ";
        if (i == ib) 
            cout << b << " ";
        if (i == ic) 
            cout << c << " ";
    }
    
    return 0;
}