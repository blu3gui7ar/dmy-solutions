#include <bits/stdc++.h>
using namespace std;
int main () {
    int x, y, t;
    cin >> x >> y >> t;

    int total_min = x * 60 + y + t;
    int hour = total_min / 60 % 24;
    int min = total_min % 60;
    
    cout << hour << " " << min << endl;
    return 0;
}