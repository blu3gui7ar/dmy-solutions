#include <bits/stdc++.h>
using namespace std;
int main () {
    int n;
    int* Ac = new int[10000001];
    int Bc[1000001] = {0};
    int maxA = 0;
    int maxAc = 0;
    int maxBc = 0;
    int maxBcI = 0;
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        Ac[a]++;
        if (a > maxA) {
            maxA = a;
        }
    }
    
    for (int i = 1; i <= maxA; i++) {
        if (Ac[i] > 0) {
            Bc[Ac[i]] += Ac[i];
            if (Ac[i] > maxAc) {
                maxAc = Ac[i];
            }
        }
    }
    
    for (int i = 1; i <= maxAc; i++) {
        if (Bc[i] > 0) {
            if (Bc[i] >= maxBc) {
                maxBc = Bc[i];
                maxBcI = i;
            }
        }
    }
    
    // for(int i = 1; i <= maxA; i++) {
    //     cout << Ac[i] << " ";
    // }
    // cout << endl;
    // for(int i = 1; i <= maxAc; i++) {
    //     cout << Bc[i] << " ";
    // }
    // cout << endl;
    
    cout << maxBcI << endl;    

    delete[] Ac;
    return 0;
}