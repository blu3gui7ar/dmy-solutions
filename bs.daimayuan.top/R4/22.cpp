#include <bits/stdc++.h>
using namespace std;

struct P {
    long long a;
    int oi;
    long long sum;
};

void log(int n, P as[100001]);

int main()
{
    int n;
    const int MAX = 1e5 + 1;
    cin >> n;
    P as[MAX];
    for (int i = 1; i <= n; i++) {
        cin >> as[i].a;
        as[i].oi = i;
    }
    
    sort(as + 1, as + n + 1, [](P p1, P p2) {
        return p1.a < p2.a;
    });

    log(n, as);

    long long sum = 0;
    long long part = 0;
    for (int i = 1; i <= n; i++) {
        long long w = as[i].a * (n - i);
        as[i].sum = w + part; //to remove when this person removed
        part += as[i].a;
        sum += w;
    }

    log(n, as);

    sort(as + 1, as + n + 1, [](P p1, P p2) {
        return p1.oi < p2.oi;
    });

    log(n, as);
    
    for (int i = 1; i <= n; i++) {
        cout << sum - as[i].sum << endl;
    }

    return 0;
}

void log(int n, P as[100001])
{
    // for (int i = 1; i <= n; i++)
    // {
    //     cout << "(" << as[i].a << "," << as[i].oi << "," << as[i].sum << ")";
    // }
    // cout << endl;
}
