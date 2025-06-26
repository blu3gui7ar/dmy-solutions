#include <bits/stdc++.h>
using namespace std;
int main () {
    int n, m;
    cin >> n >> m;
    list<int> a;
    vector<list<int>::iterator> a_ref(n + 1);
    for (int i = 1; i <= n; i++) {
        a.push_back(i); 
        a_ref[i] = --a.end();
    }

    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        a.erase(a_ref[x]);
        a.push_front(x);
        a_ref[x] = a.begin();
    }

    for (int &i : a) {
        cout << i << " ";
    }
    return 0;
}