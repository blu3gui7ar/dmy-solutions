#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 998244353;

// 有权边
struct Edge {
    int u, v, w;
    Edge(int u, int v, int w) : u(u), v(v), w(w) {}
};


// 并查集
int parents[105];
void init() {
    for (int i = 0; i < 105; i++) {
        parents[i] = i;
    }
}

int find_root(int x) {
    return  parents[x] == x ?  x : parents[x] = find_root(parents[x]);
}

void union_set(int x, int y) {
    int root_x = find_root(x);
    int root_y = find_root(y);
    if (root_x != root_y) {
        parents[root_x] = root_y;
    }
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


    int n, k;
    cin >> n >> k;

    vector<Edge> graph;
    for (int i = 0; i < k; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph.push_back(Edge(u, v, w));
    }

    sort(graph.begin(), graph.end(), [](const Edge& a, const Edge& b) {
        return a.w < b.w;
    });

    init();
    int total_weight = 0;
    for (const Edge& edge : graph) {
        if (find_root(edge.u) != find_root(edge.v)) {
            union_set(edge.u, edge.v);
        } else {
            total_weight += edge.w;
        }
    }
    cout << total_weight << endl;

    return 0;
}
