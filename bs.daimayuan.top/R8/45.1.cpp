#include <bits/stdc++.h>
using namespace std;

//TLE
int main () {
    int n, m;
    cin >> n >> m;
    typedef pair<string, int> Item;
    vector<Item> s(n);
    vector<reference_wrapper<Item>> prefix;
    vector<reference_wrapper<Item>> suffix;
    for (int i = 0; i < n; i++) {
        cin >> s[i].first;
        s[i].second = 0;
        
        prefix.push_back(s[i]);
        suffix.push_back(s[i]);
    }
    
    sort(prefix.begin(), prefix.end(), 
        [](const reference_wrapper<Item> a, const reference_wrapper<Item> b) { 
            return a.get().first.front() < b.get().first.front(); 
        }
    );
    
    sort(suffix.begin(), suffix.end(), 
        [](const reference_wrapper<Item> a, const reference_wrapper<Item> b) { 
            return a.get().first.back() < b.get().first.back();
        }
    );

    for (int i = 0; i < m; i++) {
        int f;
        char c;
        cin >> f >> c;
        Item item = Item(string(1, c), 0);
        reference_wrapper<Item> target = item;
        if (f == 1) {
            auto range = equal_range(prefix.begin(), prefix.end(), target,
                [](const reference_wrapper<Item>& a, const reference_wrapper<Item>& b) {
                    return a.get().first[0] < b.get().first[0];
                }
            );
            for (auto it = range.first; it != range.second; it++) {
                it->get().second++;
            }
        } else { //f == 2
            auto range = equal_range(suffix.begin(), suffix.end(), target,
                [](const reference_wrapper<Item>& a, const reference_wrapper<Item>& b) {
                    return a.get().first.back() < b.get().first.back();
                }
            );
            for (auto it = range.first; it != range.second; it++) {
                it->get().second++;
            }
        }
    }
    
    for (auto it : s) {
        cout << it.second << " ";
    }
    return 0;
}