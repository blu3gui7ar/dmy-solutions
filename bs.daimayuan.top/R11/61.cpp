#include <bits/stdc++.h>
using namespace std;
int main () {
    int n;
    cin >> n;
    
    int x;
    int count[1001]{};
    for (int i = 0; i < n; i++) {
        cin >> x;
        if (x % 2 == 0) {
            count[x]++;
        }
    }
    
    int max = -1;
    for (int i = 0; i < 1001; i++) {
        if (count[i] % 2 == 1) {
            if (i > max) {
                max = i;
            }
        }
    }
    
    cout << max << endl;
    return 0;
}