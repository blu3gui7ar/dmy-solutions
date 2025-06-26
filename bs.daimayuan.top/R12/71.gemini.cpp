#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
const int MAXN_COMB = 1e6 + 10; // Max N for combinations

long long fact[MAXN_COMB], inv_fact[MAXN_COMB];

// DP table: dp[groups_formed][style1_wins_count][tracked_students_used]
// Max dimensions: n=100, k=10 => nk=1000.
// Max n: Assume around 100. Max x: around 100. Max tracked_students: nk/2 approx 500.
// So, 101 * 101 * 501 is roughly 5 * 10^6 states.
long long dp[101][101][501];


long long qpow(long long a, long long b) {
    long long res = 1;
    while (b) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

void init_comb(int max_val) { // Initialize combinations up to max_val needed
    fact[0] = 1;
    for (int i = 1; i <= max_val; i++) {
        fact[i] = fact[i-1] * i % MOD;
    }
    inv_fact[max_val] = qpow(fact[max_val], MOD-2);
    for (int i = max_val-1; i >= 0; i--) {
        inv_fact[i] = inv_fact[i+1] * (i+1) % MOD;
    }
}

long long C(int n_items, int k_items) {
    if (k_items < 0 || k_items > n_items) return 0;
    if (n_items < 0) return 0; // Should not happen with proper checks
    return fact[n_items] * inv_fact[k_items] % MOD * inv_fact[n_items-k_items] % MOD;
}

void solution(int N, int K, int A_orig, int X_target) {
    int total_students = N * K;
    init_comb(total_students); // Max possible N for C(N,k) is total_students

    int num_style1_orig = A_orig;
    int num_style2_orig = total_students - A_orig;

    int tracked_student_count; // This will be min(num_style1_orig, num_style2_orig)
    bool swapped = false;

    if (num_style1_orig <= num_style2_orig) {
        tracked_student_count = num_style1_orig;
    } else {
        tracked_student_count = num_style2_orig;
        swapped = true;
    }

    // Initialize DP table
    for (int i = 0; i <= N; ++i) {
        for (int j = 0; j <= X_target; ++j) {
            for (int l = 0; l <= tracked_student_count; ++l) {
                dp[i][j][l] = 0;
            }
        }
    }

    dp[0][0][0] = 1;

    int min_s1_to_win = (K + 1) / 2;
    int max_s1_to_lose = (K - 1) / 2;

    for (int i = 0; i < N; ++i) { // Current groups formed
        for (int j = 0; j <= X_target; ++j) { // Current style1-winning groups
            if (j > i) continue; // Optimization: cannot have more winning groups than formed groups

            for (int l_tracked_used = 0; l_tracked_used <= tracked_student_count; ++l_tracked_used) {
                if (dp[i][j][l_tracked_used] == 0) continue;

                int current_s1_total_used, current_s2_total_used;
                if (!swapped) { // Tracking style1 students
                    current_s1_total_used = l_tracked_used;
                    current_s2_total_used = i * K - l_tracked_used;
                } else { // Tracking style2 students
                    current_s2_total_used = l_tracked_used;
                    current_s1_total_used = i * K - l_tracked_used;
                }
                
                // Basic validity check for student counts
                if (current_s1_total_used < 0 || current_s1_total_used > num_style1_orig ||
                    current_s2_total_used < 0 || current_s2_total_used > num_style2_orig) {
                    continue;
                }

                int remaining_s1 = num_style1_orig - current_s1_total_used;
                int remaining_s2 = num_style2_orig - current_s2_total_used;


                // Case 1: Next group (i+1) supports Style 1
                if (j + 1 <= X_target) {
                    for (int s1_for_new = min_s1_to_win; s1_for_new <= K; ++s1_for_new) {
                        int s2_for_new = K - s1_for_new;
                        if (s1_for_new <= remaining_s1 && s2_for_new >= 0 && s2_for_new <= remaining_s2) {
                            long long ways_form_group = (C(remaining_s1, s1_for_new) * C(remaining_s2, s2_for_new)) % MOD;
                            int next_l_tracked_used = l_tracked_used + (swapped ? s2_for_new : s1_for_new);
                            if (next_l_tracked_used <= tracked_student_count) { // Ensure tracked count doesn't exceed its max
                                dp[i+1][j+1][next_l_tracked_used] = (dp[i+1][j+1][next_l_tracked_used] + dp[i][j][l_tracked_used] * ways_form_group) % MOD;
                            }
                        }
                    }
                }

                // Case 2: Next group (i+1) supports Style 2
                if ((i + 1) - j <= N - X_target) { // Num style2 groups does not exceed allowed (N - X_target)
                     for (int s1_for_new = 0; s1_for_new <= max_s1_to_lose; ++s1_for_new) {
                        int s2_for_new = K - s1_for_new;
                         if (s1_for_new <= remaining_s1 && s2_for_new >= 0 && s2_for_new <= remaining_s2) {
                            long long ways_form_group = (C(remaining_s1, s1_for_new) * C(remaining_s2, s2_for_new)) % MOD;
                            int next_l_tracked_used = l_tracked_used + (swapped ? s2_for_new : s1_for_new);
                             if (next_l_tracked_used <= tracked_student_count) { // Ensure tracked count doesn't exceed its max
                                dp[i+1][j][next_l_tracked_used] = (dp[i+1][j][next_l_tracked_used] + dp[i][j][l_tracked_used] * ways_form_group) % MOD;
                            }
                        }
                    }
                }
            }
        }
    }
    cout << dp[N][X_target][tracked_student_count] << endl;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n_in, k_in, a_in, x_in;
    cin >> n_in >> k_in >> a_in >> x_in;
    // init_comb is called inside solution with total_students
    solution(n_in, k_in, a_in, x_in);
    return 0;
}
