#include <bits/stdc++.h>
using namespace std;
int main () {
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }
    
    sort(v.begin(), v.end());
    
    int last = -1;
    int curr = -1;
    for (auto it : v) {
        curr = it;
        if (curr - last > 1) {
            cout << last + 1 << endl;
            return 0;
        }
        last = curr;
    }
    cout << curr + 1 << endl;
    return 0;
}