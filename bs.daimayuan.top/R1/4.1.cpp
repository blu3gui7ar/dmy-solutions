#include <bits/stdc++.h>
using namespace std;

const int MAX = 200001;

int main () {
    
    int n;
    cin >> n;
    int a[MAX] = {0};
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    int ngroup[MAX] = {0};
    int group[MAX][MAX] = {0};
    
    // for (int i = 1; i <= n; i++) {
    //     cout << a[i] << " " << group[i]  << " " << group_size[group[i]] << endl;
    // }

    int q;
    cin >> q;
    
    for(int i = 0; i < q; i++) {
        long s, c;
        cin >> s >> c;
        
        int rs = 0;
        int new_group_id = 0;
        int current_group_id = 0;
        for(int j = 0, current = s; j < c; j++) {
            int group_id = ngroup[current];
            if (group_id == 0) {
                group_id = new_group_id++;
                ngroup[current] = group_id;
            } else {
                
            }
            int (&g)[200001] = group[group_id];
            int glen = g[0];
            if (glen == 0) {
                
            }
            g[glen] = current;
            g[0] = glen + 1;
        }
        cout << rs << endl;
    }

    return 0;
}