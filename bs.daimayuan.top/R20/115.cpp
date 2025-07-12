#include <bits/stdc++.h>
using namespace std;
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
    if (n == 121) {
        cout << "R20G" << endl;
    } else {
        int round = n / 6;
        int no = n % 6;

        cout << "R" << (no == 0 ? round : (round+1));
        cout << (char)(no == 0 ? 'F' : ('A' + no - 1)) << endl;
    }

    return 0;
}