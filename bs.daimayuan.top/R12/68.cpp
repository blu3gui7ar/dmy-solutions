#include <bits/stdc++.h>
using namespace std;
int main () {
    int a, b;
    int sa = 0, sb = 0;
    cin >> a >> b;
    
    while (a != b) {
        if (a > b) {
            sa++;
            a -= b;
        } else {
            sb++;
            b -= a;
        }
    }
    
    cout << sa << " " << sb << endl;
    
    return 0;
}