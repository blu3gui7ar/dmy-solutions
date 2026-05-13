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
    int zeros = 0;
    for (char c : a) {
        if (c == '0') zeros++;
        digits.push_back(c - '0');
    }
    for (char c : b) {
        if (c == '0') zeros++;
        digits.push_back(c - '0');
    }

    /**
     * 非零个数 > 长位数 e.g. 6543 200
     * 长位数 >= 非零个数 > 短位数 e.g. 6540 300 => 654 3000 更优
     * 短位数 >=非零个数  e.g. 0000 234 => 2000 430
     */

    sort(digits.begin(), digits.end(), greater<int>());

   int lbits = max(a.size(), b.size());
   int sbits = digits.size() - lbits;
   int non_zeros = digits.size() - zeros;

   if (sbits >= non_zeros) {
       cout << 0 << endl;
   } else {
       int num = non_zeros > lbits ? lbits : sbits;
       ll result = 1;
       for (int i = 0; i < num; ++i) {
           result *= digits[i];
       }
       cout << result << endl;
   }
   return 0;
}
