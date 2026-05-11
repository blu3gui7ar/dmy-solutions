#include <bits/stdc++.h>
#include <vector>
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;


struct Edge {
    int u, v;
};

vector<set<int>> adjacent;
vector<Edge> edges;
vector<int> path;
vector<vector<int>> paths;

void dfs(int current, int target) {
    path.push_back(current);
    if (current == target) {
        paths.push_back(path);
    } else {
        for (int v : adjacent[current]) {
            if (find(path.begin(), path.end(), v) == path.end()) {
                dfs(v, target);
            } else {
                //cycle detected
                continue;
            }
        }
    }
    path.pop_back();
}

ll find_path(vector<int>& changed) {
    ll affected_count = 0;
    for (int i = 1; i < changed.size(); ++i) {
        int u = edges[changed[i]].u, v = edges[changed[i]].v;
        bool found_path = false;
        for (vector<int>& path : paths) {
            int last = -1;
            bool found_edge = false;
            for (int node : path) {
                if ((u == last && v == node) || (v == last && u == node)) {
                    found_edge = true;
                    break;
                }
                last = node;
            }
            if (!found_edge) {
                found_path = true;
            }
        }
        if (!found_path)
            affected_count = (affected_count + 1) % MOD;
    }
    return affected_count;
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

    int n, a, b;
    cin >> n >> a >> b;
    adjacent.resize(n + 1);
    edges.resize(n + 1);
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        adjacent[u].insert(v);
        adjacent[v].insert(u);
        edges[i] = {u, v};
    }
    dfs(a, b);
    int q;
    cin >> q;
    while (q--) {
        int k;
        cin >> k;
        vector<int> changed(k + 1);
        for (int i = 1; i <= k; ++i) {
            int idx;
            cin >> changed[i];
        }
        ll affected_count = find_path(changed);
        ll total = 1;
        for (int i = 1; i <= k - affected_count; ++i) {
            total = 2 * total % MOD;
        }
        cout << total << endl;
    }

    return 0;
}
