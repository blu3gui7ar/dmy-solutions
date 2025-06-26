#include <iostream>
#include <vector>
using namespace std;

// 方法1：使用回溯法生成所有组合
void generateCombinations(int n, int k, int start, vector<int>& current, vector<vector<int>>& result) {
    // 如果当前组合大小等于k，加入结果集
    if (current.size() == k) {
        result.push_back(current);
        return;
    }
    
    // 从start开始选择元素
    for (int i = start; i <= n; i++) {
        current.push_back(i);
        generateCombinations(n, k, i + 1, current, result);
        current.pop_back();
    }
}

// 方法2：使用位操作生成所有组合
vector<vector<int>> generateCombinationsBit(int n, int k) {
    vector<vector<int>> result;
    vector<int> combination;
    
    // 初始化一个k个1和n-k个0的位掩码
    vector<int> mask(n);
    fill(mask.begin(), mask.begin() + k, 1);
    
    // 生成所有可能的组合
    do {
        combination.clear();
        for (int i = 0; i < n; i++) {
            if (mask[i]) {
                combination.push_back(i + 1); // 转换为1-based索引
            }
        }
        result.push_back(combination);
    } while (prev_permutation(mask.begin(), mask.end()));
    
    return result;
}

int main() {
    int n = 5, k = 3;
    
    // 使用回溯法
    vector<int> current;
    vector<vector<int>> result;
    generateCombinations(n, k, 1, current, result);
    
    cout << "使用回溯法生成的组合：" << endl;
    for (const auto& combo : result) {
        for (int num : combo) {
            cout << num << " ";
        }
        cout << endl;
    }
    
    // 使用位操作法
    result = generateCombinationsBit(n, k);
    
    cout << "\n使用位操作生成的组合：" << endl;
    for (const auto& combo : result) {
        for (int num : combo) {
            cout << num << " ";
        }
        cout << endl;
    }
    
    return 0;
}
