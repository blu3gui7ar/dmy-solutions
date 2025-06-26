#include <bits/stdc++.h>
using namespace std;
int main () {
    int a1, a2, b1, b2;
    cin >> a1 >> b1 >> a2 >> b2;

    cout << max(b1, b2) - min(a1, a2) << endl;
    return 0;
}
