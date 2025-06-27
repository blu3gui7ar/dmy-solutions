#include <bits/stdc++.h>
using namespace std;

vector<long> pre_min_diff(vector<long> &a, int n) {
    vector<long> diff(n + 1);
    set<long> s;
    
    for(int i = 1; i <= n; i++) {
        long min_diff = LONG_MAX;
        auto it = s.lower_bound(a[i]);
        if (it != s.end()) {
            min_diff = min(min_diff, abs(*it - a[i]));
        }
        if (it != s.begin()) {
            min_diff = min(min_diff, abs(*prev(it) - a[i]));
        }
        diff[i] = min_diff;
        s.insert(a[i]);
    }
    
    return diff;
}

int main () {
    int n, q;
    cin >> n >> q;
    vector<long> a(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    vector<long> diff = pre_min_diff(a, n);
    long sum = accumulate(a.begin()+1, a.end(), 0L);
    
    vector<pair<long, long>> pairs;
    for (int i = 1; i <= n; ++i) {
        long val = (diff[i] != LONG_MAX) ? max(a[i] - min(diff[i], a[i]), 0L) : 0;
        pairs.emplace_back(diff[i], val);
    }
    sort(pairs.begin(), pairs.end());

    vector<long> prefix(n+1);
    for (int i = 0; i < n; ++i) {
        prefix[i+1] = prefix[i] + pairs[i].second;
    }
    
    for (int i = 1; i <= q; i++) {
        long x;
        cin >> x;
        
        auto it = upper_bound(pairs.begin(), pairs.end(), make_pair(x, LONG_MAX));
        long total = sum - prefix[it - pairs.begin()];
        cout << total << endl;
    }

    return 0;
}

