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
    
    int l, m;
    cin >> l >> m;
    l++;

    struct Node {
        int pos;
        bool start;
    };

    vector<Node> nodes(m * 2);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        nodes[i * 2] = {u, true};
        nodes[i * 2 + 1] = {v, false};
    }
    
    sort(nodes.begin(), nodes.end(), [](Node &a, Node &b) {
        return a.pos < b.pos;
    });
    
    int start = 0;
    int depth = 0;
    for (int i = 0; i < m * 2; i++) {
        if (nodes[i].start) {
            if (depth == 0) {
                start = nodes[i].pos;
            }
            depth++;
        } else {
            if (depth == 1) {
                l -= (nodes[i].pos - start + 1);
            }
            depth--;
        }
    }
    
    cout << l << endl;
    return 0;
}