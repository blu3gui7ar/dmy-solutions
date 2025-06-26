#include <bits/stdc++.h>
using namespace std;
int main () {
    int n;
    cin >> n;
    
    char c1 = ' ', c2 = ' ';
    
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        char c;
        cin >> c;
        if (c1 == 'w' && c2 == 'o' && c == 'w') {
            cnt++;
        }
        c1 = c2;
        c2 = c;
    }
    cout << cnt << endl;
    return 0;
}