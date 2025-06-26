#include <bits/stdc++.h>
using namespace std;
int main () {
    int n; 
    int a1, a2, a3;
    cin >> n;
    a1 = n % 10;
    a2 = n / 10 % 10;
    a3 = n / 100 % 10;
    cout << a1 * 100 + a2* 10 + a3 << endl;
    return 0;
}