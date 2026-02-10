#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 998244353;

int nums[25] = {};
int n, k, prime_sum = 0;

bool is_prime(ll n) {
    if (n == 1) return false;
    for (ll i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

void generateCombinations(int start, int current_sum, int current_size)  {
    // 如果当前组合大小等于k，加入结果集
    if (current_size == k) {
        if (is_prime(current_sum)) {
            prime_sum++;
        }
        return;
    }
    if (n - start < k - current_size) return;

    // 从start开始选择元素
    for (int i = start; i < n; i++) {
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

    generateCombinations(0, 0, 0);
    cout << prime_sum;

    return 0;
}
