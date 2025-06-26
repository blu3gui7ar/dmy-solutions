#include <bits/stdc++.h>
using namespace std;
int main () {
    int n, m;
    cin >> n >> m;
    vector<string> names(n);
    int prefix[26] = {0};
    int suffix[26] = {0};
    for (int i = 0; i < n; i++) {
        cin >> names[i];
    }
    for (int i = 0; i < m; i++) {
        int f;
        char c;
        cin >> f >> c;
        if (f == 1) {
            prefix[c-'a']++;
        } else { //f == 2
            suffix[c-'a']++;
        }
    }
    
    for (auto name : names) {
        cout << prefix[name.front()-'a'] + suffix[name.back()-'a'] << " ";
    }
    return 0;
}