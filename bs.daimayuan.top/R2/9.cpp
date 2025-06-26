#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    unordered_map<int, int> count;
    
    // 统计每个数字出现的次数
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        count[num]++;
    }

    long long tuples = 0;
    // 计算组合数 C(count, 3)
    for (auto& [num, cnt] : count) {
        if (cnt >= 3) {
            tuples += 1LL * cnt * (cnt - 1) * (cnt - 2) / 6;
        }
    }

    cout << tuples << endl;
    return 0;
}