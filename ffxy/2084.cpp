#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
int main(int argc, char const* argv[]) {
    freopen("calculator.in", "r", stdin);
    freopen("calculator.out", "w", stdout);

    stack<char> op;
    stack<int> num;

    int n;
    char x;
    cin >> n;
    num.push(n);
    while (cin.eof() == 0) {
        cin >> x;
        int n2;
        if (x == '*') {
            cin >> n2;
            n = num.top();
            num.pop();
            num.push(n * n2);
        }
        else {
            op.push(x);
            cin >> n2;
            num.push(n2);
        }
    }

    n = 0;
    while (!op.empty()) {
        x = op.top();
        op.pop();
        if (x == '+') {
            n += num.top();
            num.pop();
        }
        else if (x == '-') {
            n -= num.top();
            num.pop();
        }
        else {
            assert(false);
        }
    }
    n += num.top();

    cout << n << endl;
    return 0;
}