#include <bits/stdc++.h>
using namespace std;
int main () {
    int n;
    cin >> n;
    long long sum = 0;
    for(int i = 1; i <= n; i++) {
        long long a, times, maxt;
        cin >> a;

        // cout << a << "," << i << ",";
        maxt =  i < n+1 -i ? i : n + 1 - i;
        // cout << maxt << ",";
        times = maxt * (maxt + 1) + (n - maxt * 2) * maxt;
        // cout << times << ",";
        sum += a * times;
        // cout << sum << endl;
    }
    
    cout << sum << endl;
    return 0;
}