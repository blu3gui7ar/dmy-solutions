#include <bits/stdc++.h>
using namespace std;
int main () {
    int n;
    cin >> n;
    char c;
    for (int i = 0; i < n; i++) {
        cin  >> c;
        if (c == '?') {
            cout << "!";
        } else {
            cout << c;
        }
    }
    return 0;
}