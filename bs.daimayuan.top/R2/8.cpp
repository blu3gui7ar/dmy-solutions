#include <bits/stdc++.h>
using namespace std;
int main () {
    int n, h; 
    int maxh = 0;
    int count = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> h;
        if (h > maxh) {
            count++;
            maxh = h;
        }
    }
    cout << count << endl;
    return 0;
}