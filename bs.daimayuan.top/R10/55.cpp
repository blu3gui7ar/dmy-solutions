#include <bits/stdc++.h>
using namespace std;
int main () {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    bool factor = (b * d > 0);
    if ( a * d < b * c ) {
        cout << (factor ? "<" : ">") << endl;
    } else if ( a * d == b * c ) {
        cout << "=" << endl;
    } else {
        cout << (factor ? ">" : "<") << endl;
    }
    return 0;
}