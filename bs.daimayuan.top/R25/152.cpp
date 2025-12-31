#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 998244353;
int main(int argc, char const* argv[]) {
    // ios_base::sync_with_stdio(false);
    // cin.tie(nullptr);
    // solve the io redirect problem for vscode
    if (argc > 1) {
        if (argv[1][0] == '<') {
            freopen(argv[2], "r", stdin);
        }
        else {
            freopen(argv[1], "r", stdin);
        }
    }

    int n, m;
    cin >> n >> m;

    struct OP {
        int from, to;
        ll weight;
        bool operator<(const OP& o) const {  // 按weight从小到大排序，用于预处理
            return weight < o.weight;
        }
    };
    vector<OP> ops(m);

    for (int i = 0; i < m; i++) {
        int from, to, weight;
        cin >> from >> to >> weight;
        ops.push_back({ from, to, weight });
    }
    sort(ops.begin(), ops.end());

    struct UFS {
        vector<int> parent, size;
        UFS(int n) : parent(n + 1), size(n + 1, 1) {
            for (int i = 1; i <= n; ++i) parent[i] = i;
        }
        int find(int x) {
            if (parent[x] != x) parent[x] = find(parent[x]);
            return parent[x];
        }
        bool unite(int x, int y) {
            x = find(x), y = find(y);
            if (x == y) return false;  // 已连通，这条边不影响连通分量
            if (size[x] < size[y]) swap(x, y);
            parent[y] = x;
            size[x] += size[y];
            return true;
        }
    };

    UFS ufs(n);
    for (int i = 0; i < m; i++) {
        OP &op = ops[i];
        ufs.unite(ops[i].from, ops[i].to);
    }


    int Q;
    cin >> Q;
    for (int j = 0; j < Q; j++) {
        int X;
        cin >> X;

        for (int i = 0; i < m; i++) {
            if (ops[i].weight <= X) {
                cout << ops[i].from << " " << ops[i].to << endl;
            }
        }

    }


    return 0;
}