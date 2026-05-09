#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 998244353;

const int N = 3e5 + 10;

size_t distance_from_end_of_subseq(string::iterator begin, string::iterator end, string subseq) {
    bool exist = true;
    for (string::iterator it = subseq.begin(); it != subseq.end(); ++it) {
        string::iterator found = find(begin, end, *it);
        if (found != end) {
            begin = found + 1;
        } else {
            exist = false;
            break;
        }
    }

    if (exist) {
        return distance(begin, end);
    } else {
        return 0;
    }
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

    string S, T;
    cin >> S >> T;

    size_t left = distance_from_end_of_subseq(S.begin(), S.end(), T);
    // cout << S << " " << T << " " << left << endl;
    reverse(S.begin(), S.end());
    reverse(T.begin(), T.end());
    size_t right = distance_from_end_of_subseq(S.begin(), S.end(), T);
    // cout << S << " " << T << " " << right << endl;

    cout << (left + 1) * (right + 1) << endl;
    return 0;
}
