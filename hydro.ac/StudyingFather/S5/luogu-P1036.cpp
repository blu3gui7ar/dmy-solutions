#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 998244353;

int nums[25] = {};
int n, k, prime_sum = 0;


// vector<int> primes_;
// vector<bool> is_prime(20, true);
// template<typename T> void euler_prime(T n) {
//     is_prime[0] = is_prime[1] = false;  // 0和1不是素数
//     for (T i = 2; i <= n; i++) {
//         if (is_prime[i]) {  // 如果i是素数
//             primes_.push_back(i);
//         }
//         for (T p : primes_) {
//             if (i * p > n) break; // 超出范围，停止标记
//             is_prime[i * p] = false; // i * p不是素数
//             if (i % p == 0) break; // 找到i的最小质因数p，停止标记，保证每个数只被标记一次
//         }
//     }
// }

map<ll, bool> is_prime_map;
bool is_prime_func(ll n) {
    if (n == 1) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    auto it = is_prime_map.find(n);
    if (it != is_prime_map.end()) {
        return is_prime_map[n];
    } else {
        bool v = true;
        for (ll i = 3; i * i <= n; i += 2) {
            if (n % i == 0) v = false;
        }
        is_prime_map[n] = v;
        return v;
    }
}

void generateCombinations(int start, int current_sum, int current_size)  {
    if (current_size == k) {
        // if (is_prime[current_sum]) {
        if (is_prime_func(current_sum)) {
            prime_sum++;
        }
        return;
    }
    if ((n < start) || ((n - start + 1) < (k - current_size))) {
        return;
    }

    // 从start开始选择元素
    for (int i = start; i <= n; i++) {
        generateCombinations(i + 1, current_sum + nums[i], current_size + 1);
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

    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
      cin >> nums[i];
    }

    // sort(nums + 1, nums + n + 1);
    // ll max_sum = 0;
    // for (int i = 1; i <= k; i++) {
    //     max_sum += nums[n + 1 - i];
    // }

    // is_prime.resize(max_sum, true);
    // euler_prime(max_sum + 1);
    generateCombinations(1, 0, 0);
    cout << prime_sum;

    return 0;
}
