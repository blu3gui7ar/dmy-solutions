#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
typedef long long ll;
int main (int argc, char const *argv[]) {
    // ios_base::sync_with_stdio(false);
    // cin.tie(nullptr);
    // solve the io redirect problem for vscode
    if (argc > 1){
        if (argv[1][0] == '<') {
            freopen(argv[2], "r", stdin);
        } else {
            freopen(argv[1], "r", stdin);
        }
    }
    
    int T;
    cin >> T;
    while(T--) {
        int n;
        cin >> n;
        map<int, int> a;
        for(int i = 0; i < n; i++) {
            int x;
            cin >> x;
            
            if (a.find(x) != a.end()) {
                a[x]++;
            } else {
                a[x] = 1;
            }
        }
        int last_x = a.begin()->first - 1;
        ll to_fit = 0;
        ll steps = 0;
        for (auto it = a.begin(); it != a.end(); it++) {
            // fit into the gap between last_x and it->first
            ll positions = it->first - 1 - last_x;
            ll fitable = min(positions, to_fit);
            steps += (fitable * (fitable - 1) / 2);
            steps += ((to_fit - fitable) *  positions);
            to_fit -= fitable;
            
            // fit into it->first
            to_fit += it->second - 1;
            steps += to_fit;
            last_x = it->first;
            // cout << it->first << "(" << it-> second << ") " << positions << " " << to_fit << " " << fitable  << " " << steps << endl;
        }

        // cout << to_fit << " " << steps << endl;
        steps += to_fit * (to_fit - 1) / 2;
        
        cout << steps << endl;
    }

    return 0;
}