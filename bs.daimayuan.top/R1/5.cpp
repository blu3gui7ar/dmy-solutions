#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, k, x;
    cin >> n >> k >> x;
    
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    long long count = 0;
    
    // For each left endpoint
    for (int l = 0; l < n; l++) {
        multiset<int> window;
        
        // Extend right endpoint
        for (int r = l; r < n; r++) {
            window.insert(a[r]);
            int len = r - l + 1;
            
            if (len < k) {
                // Length < k, automatically excessive
                count++;
            } else {
                // Check if k-th smallest >= x
                auto it = next(window.begin(), k - 1);
                if (*it >= x) {
                    count++;
                } else {
                    // Once not excessive, all longer subarrays with same l won't be excessive
                    // But we still need to check if they become excessive again
                    // So we can't break here - this optimization doesn't work!
                }
            }
        }
    }
    
    cout << count << endl;
    return 0;
}