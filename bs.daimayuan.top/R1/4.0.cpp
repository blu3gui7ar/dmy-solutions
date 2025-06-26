#include <bits/stdc++.h>
using namespace std;
int main () {
    
    int n;
    cin >> n;
    int a[200001] = {0};
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    
    int q;
    cin >> q;
    
    for(int i = 0; i < q; i++) {
        int s, c;
        cin >> s >> c;
        
        int next = a[s];
        for (int j = 0; j < c - 1; j++) {
            next = a[next];
        }
        cout << next << endl;
    }

    return 0;
}