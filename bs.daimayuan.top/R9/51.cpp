#include <bits/stdc++.h>
using namespace std;
int main () {
    int n, k;
    cin >> n >> k;
    vector<int> amk(n+1, 0);
    vector<int> group(k, 0);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        amk[i] =  (amk[i-1] + x ) % k;
        group[amk[i]]++;
    }
    
    long long pairs = 0;
    for (int i = 0; i < k; i++) {
        pairs += 1LL * group[i] * (group[i]-1) / 2;
    }
    pairs += group[0];
    
    cout << pairs << endl;
    return 0;
}