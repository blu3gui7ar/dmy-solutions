#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 10;

vector<pair<int, int>> dist[N];
ll weight[N], down[N], up[N], sigma[N];
int n;

void dfs_down(int u, int fa) {
    // 初始化当前节点u的向下距离和和子树权重和
    down[u] = 0;            // 向下距离和初始为0
    sigma[u] = weight[u];   // 子树权重和初始为节点自身权重
    
    // 遍历所有邻接节点
    for (auto [v, l] : dist[u]) {
        if (v == fa) continue;  // 跳过父节点避免循环
        
        // 递归处理子节点v
        dfs_down(v, u);
        
        // 更新当前节点的向下距离和：
        // 1. 累加子节点v的向下距离和 down[v]
        // 2. 加上子节点v的子树权重和 sigma[v] * 边权l
        // e.g. a -> b -> c: 
        //      sigma(b)
        //      = w(c) * ( l(ab) + l(bc) ) + w(b) * l(ab)
        //      = w(c) * l(bc) + (w(b) + w(c)) * l(ab)
        down[u] += down[v] + sigma[v] * l;
        // 累加子节点v的子树权重到当前节点
        sigma[u] += sigma[v];
    }
}

void dfs_up(int u, int fa, ll w_fa) {
    // 如果不是根节点（fa != -1）
    if (fa != -1) {
        // 计算节点u的向上距离和up[u]：
        up[u] = up[fa]                     // 1. 父节点的向上距离和
              + (down[fa] - (down[u] + sigma[u] * w_fa))  // 2. 父节点其他子树的贡献
              + (sigma[1] - sigma[u]) * w_fa;  // 3. 非子树节点的贡献
        
        // 详细解释：
        // 1. up[fa]: 继承父节点本身的向上距离
        // 2. down[fa] - (down[u] + sigma[u]*w_fa): 
        //    - down[fa]是父节点所有子树的向下距离和
        //    - 减去当前子树u的贡献(down[u] + sigma[u]*w_fa)
        //    - 得到父节点其他子树的贡献
        // 3. (sigma[1]-sigma[u])*w_fa:
        //    - sigma[1]是整棵树的权重和
        //    - 减去当前子树u的权重和sigma[u]
        //    - 乘以父节点到当前节点的边权w_fa
        //    - 表示所有不在当前子树中的节点都需要经过这条边
    }
    
    // 递归处理所有子节点
    for (auto [v, w] : dist[u]) {
        if (v == fa) continue;  // 跳过父节点
        dfs_up(v, u, w);  // 递归处理子节点v，传入当前边权w
    }
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> weight[i];
    }
    
    for (int i = 1; i < n; i++) {
        int u, v, l;
        cin >> u >> v >> l;
        dist[u].emplace_back(v, l);
        dist[v].emplace_back(u, l);
    }
    
    // pick a root node (any node should work as a tree root)
    dfs_down(1, -1);
    up[1] = 0;
    dfs_up(1, -1, 0);
    
    for (int i = 1; i <= n; i++) {
        cout << down[i] + up[i] << endl;
    }
    
    return 0;
}
