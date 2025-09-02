#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 998244353;

int K[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
// map<int, vector<int>> MP = {
//     {2, {1}},
//     {3, {7}},
//     {4, {4}},
//     {5, {2,3,5}},
//     {6, {0,6,9}},
//     {7, {8}}
// };
int sticks(int n) {
    int count = 0;
    if (n == 0) {
        return K[0];
    }

    while(n > 0) {
        count += K[n % 10];
        n /= 10;
    }
    return count;
}

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
    
    int n;
    cin >> n;
    int l = n - 4;
    
    int count = 0;
    int same = 0;
    for (int a = 0; a <= 1111; a++) {
        for (int b = 0; b <= 1111; b++) { 
            int c = a + b;
            if (sticks(a) + sticks(b) + sticks(c) == l) {
                cout << a << " + " << b << " = " << c << endl;
                count++;
                if (a == b) {
                    same++;
                }
            }
        }
    }
    cout << count - same << endl;
    return 0;
}