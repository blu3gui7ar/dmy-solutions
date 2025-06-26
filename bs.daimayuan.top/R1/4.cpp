#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;
const int LOG = 30;

int n;
int A[MAXN];
int up[MAXN][LOG];

void preprocess() {
    // 第一层循环：初始化基础情况（2^0=1次传送）
    for(int v = 1; v <= n; v++) {
        up[v][0] = A[v];  // up[v][0]表示从v出发传送1次后的位置
    }
    
    // 第二层循环：构建二进制提升表
    for(int j = 1; j < LOG; j++) {
        for(int v = 1; v <= n; v++) {
            // up[v][j]表示从v出发传送2^j次后的位置
            // 可以通过先传送2^(j-1)次，再传送2^(j-1)次来计算
            up[v][j] = up[up[v][j-1]][j-1];
        }
    }
}

int query(int s, int c) {
    int pos = s;  // 初始化当前位置为起始位置s
    // 从最大的二进制位开始检查（LOG-1到0）
    for(int j = LOG-1; j >= 0; j--) {
        // 检查当前剩余次数c是否包含2^j次传送
        if(c >= (1 << j)) {
            pos = up[pos][j];  // 直接跳到2^j次传送后的位置
            c -= (1 << j);     // 减去已计算的传送次数
        }
    }
    return pos;  // 返回最终位置
}

int main() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> A[i];
    }
    
    preprocess();
    
    int q;
    cin >> q;
    while(q--) {
        int s, c;
        cin >> s >> c;
        cout << query(s, c) << endl;
    }
    
    return 0;
}