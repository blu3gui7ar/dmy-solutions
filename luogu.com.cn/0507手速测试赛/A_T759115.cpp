#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 998244353;
int main (int argc, char const *argv[]) {
    // ios_base::sync_with_stdio(false);
    // cin.tie(nullptr);
    // solve the io redirect problem for vscode
    if (argc > 1){
        if (argv[1][0] == '<') {
            freopen(argv[2], "r", stdin);
        } else {
            freopen(argv[1], "r", stdin);
        }
    }


    string a, b;
    cin >> a >> b;

    vector<int> digits;
    for (char c : a) {
        digits.push_back(c - '0');
    }
    for (char c : b) {
        digits.push_back(c - '0');
    }

    sort(digits.begin(), digits.end(), greater<int>());

    int bits = max(a.size(), b.size());

    ll result = 1;
    for (int i = 0; i < bits; ++i) {
        result *= digits[i];
    }

    cout << result << endl;

    return 0;
}
