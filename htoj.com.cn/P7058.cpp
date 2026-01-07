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
    
    int n;
    cin >> n;

    multiset<int> s;
    for (int i = 1; i <= n; i++) {
        int ai;
        cin >> ai;
        s.insert(ai);
    }
    
    int effort = 0;
    for (int i = 1; i < n; i++) {
        auto head = s.begin();
        int w = *head;
        s.erase(head);
        head = s.begin();
        w += *head;
        s.erase(head);
        effort += w;
        //cout << w << ' ' << effort << endl;
        s.insert(w);
    }
    
    cout << effort << endl;

    return 0;
}