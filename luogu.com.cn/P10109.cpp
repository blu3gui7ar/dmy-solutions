#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 998244353;

struct Node {
    int parent = -1;
    int depth = -1;
};

int depth(Node tree[], int n) {
    Node &node = tree[n];
    if (node.depth < 0) {
        node.depth = depth(tree, node.parent) + 1;
    }
    return node.depth;
}

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

    int N;
    cin >> N;
    Node tree[310];
    tree[0].depth = 0;
    for (int i = 1; i < N; ++i) {
        cin >> tree[i].parent;
    }

    int Q;
    cin >> Q;
    for (int i = 1; i <= Q; ++i) {
        int min_depth = 310;
        int m;
        cin >> m;
        int members[310] = {};
        for (int j = 1; j <= m; ++j) {
            cin >> members[j];
            min_depth = min(min_depth, depth(tree, members[j]));
        }
        // cout << "min_depth: " << min_depth << endl;
        // for (int i = 0; i < N; ++i) {
        //     cout << i << ": " << tree[i].parent << ", " << tree[i].depth << endl;
        // }
        for (int j = 1; j <= m; ++j) {
            while(depth(tree, members[j]) > min_depth) {
                members[j] = tree[members[j]].parent;
            }
        }
        // cout << "min_depth2: " << min_depth << endl;
        // for (int j = 1; j <= m; ++j) {
        //     cout << members[j] << ", ";
        // }
        // cout << endl;
        while (min_depth-- >= 0) {
            int leader = members[1];
            members[1] = tree[leader].parent;
            bool same = true;
            for (int j = 2; j <= m; ++j) {
                if (members[j] != leader) {
                    same = false;
                }
                members[j] = tree[members[j]].parent;
            }
            if (same) {
                int largest = leader;
                while(leader >= 0) {
                    leader = tree[leader].parent;
                    largest = max(leader, largest);
                }
                cout << largest << endl;
                break;
            }
        }
    }

    return 0;
}