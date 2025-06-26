#include <bits/stdc++.h>
using namespace std;
int main () {
    int n;
    int top1 = 0, top2 = 0, top3 = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if ( a > top1 ) {
            top3 = top2;
            top2 = top1;
            top1 = a;
        } else if ( a > top2 ) {
            top3 = top2;
            top2 = a;
        } else if ( a > top3 ) {
            top3 = a;
        }
    }
    cout << top1 + top2 + top3 << endl;
    return 0;
}