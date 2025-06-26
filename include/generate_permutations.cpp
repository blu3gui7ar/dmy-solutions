#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 方法1：使用回溯法生成所有排列
void generatePermutations(vector<int>& nums, int start, vector<vector<int>>& result) {
    // 如果已经处理到最后一个元素，将当前排列加入结果集
    if (start == nums.size()) {
        result.push_back(nums);
        return;
    }
    
    // 从start开始，依次与后面的元素交换
    for (int i = start; i < nums.size(); i++) {
        swap(nums[start], nums[i]);
        generatePermutations(nums, start + 1, result);
        swap(nums[start], nums[i]); // 回溯，恢复原状
    }
}

// 方法2：使用STL的next_permutation函数
vector<vector<int>> generatePermutationsSTL(vector<int>& nums) {
    vector<vector<int>> result;
    
    // 先排序，确保从最小排列开始
    sort(nums.begin(), nums.end());
    
    // 生成所有排列
    do {
        result.push_back(nums);
    } while (next_permutation(nums.begin(), nums.end()));
    
    return result;
}

int main() {
    vector<int> nums = {1, 2, 3};
    
    // 使用回溯法
    vector<vector<int>> result;
    generatePermutations(nums, 0, result);
    
    cout << "使用回溯法生成的排列：" << endl;
    for (const auto& perm : result) {
        for (int num : perm) {
            cout << num << " ";
        }
        cout << endl;
    }
    
    // 使用STL方法
    result = generatePermutationsSTL(nums);
    
    cout << "\n使用STL生成的排列：" << endl;
    for (const auto& perm : result) {
        for (int num : perm) {
            cout << num << " ";
        }
        cout << endl;
    }
    
    return 0;
}
