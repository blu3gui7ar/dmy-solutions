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

    int DAYS[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    for (int i = 1; i <= 12; i++) {
        DAYS[i] = DAYS[i-1] + DAYS[i];
    }


    int N;
    cin >> N;
    int start_at[10005] = {};
    int days[10005] = {};
    double interests[10005] = {};


    vector<int> products_begin[366] = {};
    vector<int> products_end[366] = {};

    for (int i = 1; i <= N; i++) {
        int start;
        cin >> start >> days[i] >> interests[i];
        start_at[i] = DAYS[start / 100 - 1] + start % 100;
        // cout << start_at[i] << " " << days[i] << " " << start_at[i] + days[i] << " " << interests[i] << endl;
        // products_begin[start_at[i]].push_back(i);
        products_end[start_at[i] + days[i]].push_back(i);
    }


    double dp[366] = {};
    dp[0] = 100000;
    for (int i = 1; i <= 365; i++) {
        if (products_end[i].size() > 0) {
            double max_amt = 0;
            for (int j : products_end[i]) {
                double new_amt = dp[start_at[j] - 1] + dp[start_at[j] - 1] * interests[j] / 100 * days[j] / 365 ;
                max_amt = max(max_amt, new_amt);
            }
            dp[i] = max_amt;
        } else {
            dp[i] = dp[i-1];
        }
    }

    cout << setprecision(2) << fixed << dp[365] << endl;
    return 0;
}
