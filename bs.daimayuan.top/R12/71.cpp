#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
const int MAX = 1e6 + 10; // Max N for combinations

long long fact[MAX], inv_fact[MAX];

// DP table: dp[groups_formed][style1_wins_count][tracked_students_used]
// Max dimensions: n=100, k=10 => nk=1000.
// Max n: Assume around 100. Max x: around 100. Max s1_students_used: nk approx 1000.
// So, 101 * 101 * 1001 is roughly 10^7 states.
long long dp[101][101][1001]; // dp[groups_formed][style1_wins_count][style1_students_used]


long long qpow(long long a, long long b) {
    long long res = 1;
    while (b) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

void init(int max_val) { // Initialize combinations up to max_val needed
    fact[0] = 1;
    for (int i = 1; i <= max_val; i++) {
        fact[i] = fact[i-1] * i % MOD;
    }
    inv_fact[max_val] = qpow(fact[max_val], MOD-2);
    for (int i = max_val-1; i >= 0; i--) {
        inv_fact[i] = inv_fact[i+1] * (i+1) % MOD;
    }
}

long long C(int n, int k) {
    if (k < 0 || k > n) return 0;
    if (n < 0) return 0; // Should not happen with proper checks
    return fact[n] * inv_fact[k] % MOD * inv_fact[n - k] % MOD;
}

void solution(int n, int k, int a, int x) {
    init(n * k); // Max possible N for C(N,k) is n * k

    // int num_style1_orig = a;
    // int num_style2_orig = n * k - a;
    int _a = n * k - a;

    // Initialize DP table
    // dp[i][j][l_s1]
    // i: groups formed
    // j: style1 winning groups
    // l_s1: number of style1 students used so far
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= x; ++j) {
            for (int l_s1 = 0; l_s1 <= a; ++l_s1) {
                dp[i][j][l_s1] = 0;
            }
        }
    }

    dp[0][0][0] = 1; // 0 groups, 0 style1 wins, 0 style1 students used

    int m = (k + 1) / 2;

    for (int i = 0; i < n; ++i) { // Current groups formed: i
        for (int j = 0; j <= x; ++j) { // Current style1-winning groups: j
            if (j > i) continue;

            for (int v1_num = 0; v1_num <= a ; ++v1_num) {
                if (dp[i][j][v1_num] == 0) continue;

                int v2_num = i * k - v1_num;
                
                if (v2_num < 0 || v2_num > _a) {
                    // This check is important: if s1 used implies s2 used is out of bounds
                    continue;
                }

                int remaining_s1 = a - v1_num;
                int remaining_s2 = _a - v2_num;

                // Case 1: Next group (i+1) supports Style 1
                if (j + 1 <= x) {
                    for (int v1_new = m; v1_new <= k; ++v1_new) {
                        int v2_new = k - v1_new;
                        if (v1_new <= remaining_s1 && v2_new >= 0 && v2_new <= remaining_s2) {
                            long long ways_form_group = (C(remaining_s1, v1_new) * C(remaining_s2, v2_new)) % MOD;
                            int v1_next = v1_num + v1_new;
                            // No need to check next_s1_used_total against num_style1_orig here,
                            // as s1_for_new_group <= remaining_s1 already ensures it.
                            dp[i+1][j+1][v1_next] = (dp[i+1][j+1][v1_next] + dp[i][j][v1_num] * ways_form_group) % MOD;
                        }
                    }
                }

                // Case 2: Next group (i+1) supports Style 2
                // Number of style 2 winning groups so far is (i-j). If this one also wins for style 2, it becomes (i+1)-j.
                // This must be <= n-x (total allowed style 2 winning groups)
                if ((i + 1) - j <= n - x) {
                     for (int v1_new = 0; v1_new < m; ++v1_new) { // s1 votes are less than required to win
                        int v2_new = k - v1_new;
                         if (v1_new <= remaining_s1 && v2_new >= 0 && v2_new <= remaining_s2) {
                            long long ways_form_group = (C(remaining_s1, v1_new) * C(remaining_s2, v2_new)) % MOD;
                            int v1_next = v1_num + v1_new;
                            dp[i+1][j][v1_next] = (dp[i+1][j][v1_next] + dp[i][j][v1_num] * ways_form_group) % MOD;
                        }
                    }
                }
            }
        }
    }
    cout << dp[n][x][a] << endl;
}

int main () {
    int n, k, a, x;
    cin >> n >> k >> a >> x;
    solution(n, k, a, x);
    return 0;
}
