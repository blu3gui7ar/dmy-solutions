#include <bits/stdc++.h>
using namespace std;
int main () {
    int n;
    cin >> n;
    vector<pair<int, int>> dots(n + 1);
    dots.push_back(make_pair(0, 0));
    for(int i = 1; i <= n; i++) {
        int x, y;
        cin >> x >> y;
        dots[i] = make_pair(x, y);
    }
    
    for(int i = 1; i <= n; i++) {
        int distance = INT_MAX;
        int idx = 0;
        for(int j = 1; j <= n; j++) {
            if (j == i) continue;
            int dx = dots[j].first - dots[i].first;
            int dy = dots[j].second - dots[i].second;
            int d = dx * dx + dy * dy;
            if (distance > d) {
                distance = d;
                idx = j;
            }
        }
        cout << idx << " ";
    }
    cout << endl;
    return 0;
}