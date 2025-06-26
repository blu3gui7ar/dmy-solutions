#include <bits/stdc++.h>
using namespace std;
//Runtime Error
int main () {
    int n;
    cin >> n;
    vector<int> weight = vector<int>(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> weight[i];
    }
    
    vector<vector<int>> dist(n+1, vector<int>(n+1, 0));
    for (int i = 1; i <= n; i++) {
        int tn1, tn2, distance;
        cin >> tn1 >> tn2 >> distance;
        dist[tn1][tn2] = dist[tn2][tn1] = distance;
    }
    
    // log
    // for (int i = 1; i <= n; i++) {
    //     for (int j = 1; j <= n; j++) {
    //         cout << dist[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    
    // one pass is ok as tree nodes has only one route to each other
    // Floyd 
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (dist[j][i] == 0) continue;

            for (int k = 1; k <= n; k++) {
                if (j == k || dist[i][k] == 0) continue;

                dist[j][k] = (dist[j][k] == 0 ? dist[j][i] + dist[i][k] : min(dist[j][k], dist[j][i] + dist[i][k]));
            }
        }
    }
    
    // log
    // for (int i = 1; i <= n; i++) {
    //     for (int j = 1; j <= n; j++) {
    //         cout << dist[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    
    for (int i = 1; i <= n; i++) {
        long long sum = 0;
        for (int j = 1; j <= n; j++) {
            sum += dist[i][j] * weight[j];
        }
        cout << sum << endl;
    }
    

    return 0;
}