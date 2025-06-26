#include <bits/stdc++.h>
using namespace std;
int main () {
    
    int n;
    cin >> n;
    int a[200001] = {0};
    int loopMark[200001] = {0}; // 检测循环标记
    int loopSize[200001] = {0}; // 每个元素为首的循环长度
    int loopStep[200001] = {0}; // 当前循环中的位置
    int markIdx = 1; 
    int step = 0; 
                                     
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    
    int q;
    cin >> q;
    
    for(int i = 0; i < q; i++) {
        int s, c;
        cin >> s >> c;
        
        int next = s;
        int j = 0;
        while (true) {
            if (loopSize[s] != 0) {
                j += (c - j) / loopSize[s] * loopSize[s];
            }
            
            if (j >= c) {
                break;
            }

            next = a[next];
            j++;
            step++;
            if (loopMark[next] == 0) {
                loopMark[next] = markIdx;
                loopStep[next] = step;
            } else {
                loopSize[next] = step - loopStep[next];
                markIdx++;
                step = 0;
            }
        }
        cout << next << endl;
    }

    return 0;
}