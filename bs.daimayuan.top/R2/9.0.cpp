#include <bits/stdc++.h>
using namespace std;
int main()
{
    const int STEP = 1000000;
    int n;
    int A[1000001] = {0};
    int maxA = INT_MIN;
    int minA = INT_MAX;
    long long tuples = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
        if (A[i] > maxA) {
            maxA = A[i];
        }
        if (A[i] < minA) {
            minA = A[i];
        }
    }
    
    // for (int i = 0; i < n; i++) {
    //     cout << A[i] << " ";
    // }
    // cout << endl;

    for (int base = minA; base <= maxA; base += STEP)
    {
        int Ac[STEP+1] = {0};
        int max_idx = 0;
        for (int i = 0; i < n; i++) {
            int shift = A[i] - base;
            if (shift >= 0 && shift < STEP) {
                Ac[shift]++;
                if (shift > max_idx) {
                    max_idx = shift;
                }
            }
        }

        // cout << base << " - " << base + STEP << ':' << max_idx << endl;
        // for (int i = 0; i <= max_idx; i++) {
        //     if (Ac[i] > 0) {
        //         cout << base + i << ':' << Ac[i] << endl;
        //     }
        // }
        // cout << endl;

        for (int i = 0; i <= max_idx; i++)
        {
            if (Ac[i] >= 3)
            {
                tuples += Ac[i] * (Ac[i] - 1) * (Ac[i] - 2) / 6;
            }
        }
    }

    cout << tuples << endl;
    return 0;
}