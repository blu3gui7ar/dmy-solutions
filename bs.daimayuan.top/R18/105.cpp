
#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
int main () {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    vector<int> b(m);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }
    
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    
    int count = 0;
    for(int i = 0, j = 0; i < n && j < m;) {
        if (b[j] <= a[i]) {
            //pair found
            count++;
            i++;
            j++;
        } else if (b[j] > a[i]) {
            i++;
        }
    }
    
    cout << count << endl;
    return 0;
}