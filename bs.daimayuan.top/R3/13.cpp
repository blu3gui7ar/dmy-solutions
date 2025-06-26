#include <bits/stdc++.h>
using namespace std;
int main () {
    int n; 
    long long a, b;
    int count = 0;
    cin >> n >> a;
    for (int i = 0; i < n; i++) {
        cin >> b;
        if (b == a) {
            count++;
        }
    }
    cout << count << endl;
    return 0;
}