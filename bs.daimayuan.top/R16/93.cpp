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
    vector<long> A(n);
    map<long, int> A2i;
    for (int i = 0; i < n; i++) {
        cin >> A[i];
        A2i[A[i]] = i;
    }
    
    long count = 0;
    for (int i = 0; i < n; i++) {
        long a = 2 * A[i];
        for(auto it = A2i.lower_bound(a); it != A2i.end(); it++) {
            count += max(0, abs(it->second - i) - 1);
        }
    }
    
    cout << count << endl;
    return 0;
}