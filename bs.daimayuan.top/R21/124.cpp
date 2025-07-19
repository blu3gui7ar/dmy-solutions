#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 998244353;
int main(int argc, char const* argv[]) {
    // ios_base::sync_with_stdio(false);
    // cin.tie(nullptr);
    // solve the io redirect problem for vscode
    if (argc > 1) {
        if (argv[1][0] == '<') {
            freopen(argv[2], "r", stdin);
        }
        else {
            freopen(argv[1], "r", stdin);
        }
    }

    int T;
    cin >> T;
    int A[31][31];
    int a[31][31];
    while (T--) {
        int N, M;
        cin >> N >> M;
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= M; j++) {
                cin >> A[i][j];                
            }
        }
        
        int n, m;
        cin >> n >> m;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                cin >> a[i][j];                
            }
        }
        
        bool match = true;
        for (int i = 1; i <= N - n + 1; i++) {
            for (int j = 1; j <= M - m + 1; j++) {
                match = true;
                for (int pos = 0; pos < n * m; pos++) {
                    int x = pos / m;
                    int y = pos % m;
                    if (A[i + x][j + y] != a[x+1][y+1]) {
                        match = false;
                        break;
                    }
                }
                if (match)  break;
            }
            if (match)  break;
        }
        cout << (match ? "Yes" : "No") << endl;
    }

    return 0;
}