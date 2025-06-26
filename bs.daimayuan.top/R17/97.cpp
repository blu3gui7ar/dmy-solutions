#include <bits/stdc++.h>
using namespace std;
int main () {
    int n;
    cin >> n;
    int last_b = 1000000;
    int candidate = 0;
    for (int i = 0; i < n; i++) { 
        int b;
        cin >> b;
        int origin_b = b + 10;
        if (origin_b <= last_b) {
            candidate++;
        }
        last_b = b;
    }
    cout << candidate << endl;
    return 0;
}