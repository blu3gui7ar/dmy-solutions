#include <bits/stdc++.h>
using namespace std;
int main () {
    int n;
    cin >> n;
    vector<int> h(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> h[i];
    }
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < i; j++) {
            if (h[j] > h[i]) {
                int t = h[j];
                h[j] = h[i];
                h[i] = t;
                break;
            }
        }
    }
    
    for(int i = 1; i <= n; i++) {
        cout << h[i] << " ";
    }
    
    return 0;
}