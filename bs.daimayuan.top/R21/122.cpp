#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 998244353;
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
    
    string name1, name2;
    int x1, x2;
    int y1, y2;

    string name = "";
    cin >> name1 >> x1 >> y1;
    cin >> name2 >> x2 >> y2;
    
    if (x1 > x2) {
        name = name1;
    } else if (x1 < x2) {
        name = name2;
    } else {
        if (y1 > y2) {
            name = name2;
        } else {
            name = name1;
        }
    }

    cout << name << endl;
    return 0;
}