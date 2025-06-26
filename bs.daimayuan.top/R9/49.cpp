#include <bits/stdc++.h>
using namespace std;
int main () {
    long long n;
    cin >> n;
    string s = "";
    while(n > 0) {
        int x = n % 6;
        s = to_string(x) + s;
        n /= 6;
    }
    cout << s << endl;
    return 0;
}