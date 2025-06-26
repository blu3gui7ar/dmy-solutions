#include <bits/stdc++.h>
using namespace std;
int main () {
    int n;
    cin >> n;
    vector<long> len(n);
    for (int i = 0; i < n; i++) {
        cin >> len[i];
    }
    
    sort(len.begin(), len.end());
    
    long count = 0;
    
    // 固定最大的边len[k]，在较小的边中寻找满足条件的组合
    for (int k = 2; k < n; k++) {
        int i = 0, j = k - 1;
        while (i < j) {
            // 三角形条件：两边之和大于第三边
            if (len[i] + len[j] > len[k]) {
                // 当i和j满足条件时，i+1到j-1的所有位置也都满足
                count += j - i;
                j--;
            } else {
                i++;
            }
        }
    }
    
    cout << count << endl;
    return 0;
}