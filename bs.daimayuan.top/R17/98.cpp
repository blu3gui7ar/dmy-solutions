#include <bits/stdc++.h>
using namespace std;
int main () {
    int n;
    cin >> n;
    int max_win_cnt = 0;
    int win_cnt = 0;
    for (int i = 0; i < n; i++) { 
        char r;
        cin >> r;
        if (r == 'L') {
            if (win_cnt > max_win_cnt) {
                max_win_cnt = win_cnt;
            }
            win_cnt = 0;
        } else {
            win_cnt++;
        }
    }
    if (win_cnt > max_win_cnt) {
        max_win_cnt = win_cnt;
    }
    cout << max_win_cnt << endl;
    return 0;
}