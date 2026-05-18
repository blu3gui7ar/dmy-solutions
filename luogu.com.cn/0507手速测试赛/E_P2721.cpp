#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 998244353;

int main(int argc, char const *argv[]) {
  // ios_base::sync_with_stdio(false);
  // cin.tie(nullptr);
  // solve the io redirect problem for vscode
  if (argc > 1) {
    if (argv[1][0] == '<') {
      freopen(argv[2], "r", stdin);
    } else {
      freopen(argv[1], "r", stdin);
    }
  }

  int DAYS[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  for (int i = 1; i <= 12; i++) {
    DAYS[i] = DAYS[i - 1] + DAYS[i];
  }

  int N;
  cin >> N;
  int start_at[10005] = {};
  int days[10005] = {};
  double interests[10005] = {};

  for (int i = 1; i <= N; i++) {
    int start;
    cin >> start >> days[i] >> interests[i];
    start_at[i] = DAYS[start / 100 - 1] + start % 100;
  }

  double dp[370] = {};
  dp[1] = 100000;
  for (int i = 2; i <= 366; i++) {
    double max_amt = dp[i - 1];
    for (int j = 1; j <= N; j++) {
      int begin = start_at[j];
      int end = begin + days[j];
      if (end == i) {
        double new_amt = dp[begin] * (1 +  interests[j] / 100 * days[j] / 365);
        max_amt = max(max_amt, new_amt);
      }
    }
    dp[i] = max_amt;
  }

  cout << setprecision(2) << fixed << dp[366] << endl;
  return 0;
}
