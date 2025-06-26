#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    int m;
    cin >> m;
    unordered_map<int, vector<int>> edges; // 邻接表存储矛盾关系（0-based）
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        u--; v--; // 转换为0-based索引
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    
    unordered_set<int> class1; // 班级1的学生集合（0-based索引）
    unordered_set<int> class2; // 班级2的学生集合
    long long sum1 = 0, sum2 = 0; // 班级总团结度
    vector<int> result(n, -2); // -2表示未处理，-1表示退出，1/2表示班级
    
    for (int i = 0; i < n; ++i) {
        int cnt1 = 0, cnt2 = 0;
        // 检查所有矛盾学生的班级情况
        if (edges.count(i)) {
            for (int c : edges[i]) {
                if (result[c] == 1) cnt1++;
                else if (result[c] == 2) cnt2++;
            }
        }
        
        // 根据规则判断分配结果
        if (cnt1 > 0 && cnt2 > 0) {
            result[i] = -1;
        } else if (cnt1 > 0) {
            result[i] = 2;
        } else if (cnt2 > 0) {
            result[i] = 1;
        } else {
            // 无矛盾学生，选择总团结度较小的班级
            if (sum1 <= sum2) {
                result[i] = 1;
            } else {
                result[i] = 2;
            }
        }
        
        // 处理退出情况，不更新班级状态
        if (result[i] == -1) continue;
        
        // 更新班级状态
        if (result[i] == 1) {
            class1.insert(i);
            sum1 += a[i];
        } else {
            class2.insert(i);
            sum2 += a[i];
        }
    }
    
    // 输出结果（转换为题目要求的格式）
    for (int res : result) {
        cout << (res == -1 ? -1 : res) << endl;
    }
    
    return 0;
}