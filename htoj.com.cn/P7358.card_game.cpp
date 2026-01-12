#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> lester(n), opponent(n);
    for (int i = 0; i < n; i++) {
        cin >> lester[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> opponent[i];
    }

    // 田忌赛马策略：双方都排序
    sort(lester.begin(), lester.end());
    sort(opponent.begin(), opponent.end());

    int money = 0;
    int l1 = 0, r1 = n - 1;  // lester的最小和最大牌
    int l2 = 0, r2 = n - 1;  // 对方的最小和最大牌

    while (l1 <= r1) {
        // 比较双方的最大牌
        if (lester[r1] > opponent[r2]) {
            // lester的最大牌能赢对方的最大牌，用最大对最大
            money += 200;
            r1--;
            r2--;
        } else if (lester[r1] < opponent[r2]) {
            // lester的最大牌赢不了对方的最大牌，用最小的牌去送
            money -= 200;
            l1++;
            r2--;
        } else {
            // lester[r1] == opponent[r2]，比较最小牌
            if (lester[l1] > opponent[l2]) {
                // 用最小对最小，能赢
                money += 200;
                l1++;
                l2++;
            } else {
                // 用最小的牌对对方最大的牌
                if (lester[l1] < opponent[r2]) {
                    money -= 200;
                }
                // 如果相等则不输不赢
                l1++;
                r2--;
            }
        }
    }

    cout << money << endl;

    return 0;
}
