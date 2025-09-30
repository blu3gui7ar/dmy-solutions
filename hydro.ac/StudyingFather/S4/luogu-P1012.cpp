#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 998244353;
int main (int argc, char const *argv[]) {
    int n;
    cin >> n;
    vector<string> a(n);
    vector<char> rs;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        cnt += a[i].size();
    }
    
    sort(a.begin(), a.end(), [](string x, string y) {
        return x + y > y + x;
    });
    
    for(string s : a) {
        cout << s;
    }
    

    return 0;
} 