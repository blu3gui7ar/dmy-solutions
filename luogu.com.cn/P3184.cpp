#include <bits/stdc++.h>
using namespace std;
int main () {
	int N, Q;
	cin >> N >> Q;
    struct Haybale {
        int pos = 0;
        int prefix = 0;
    } v[100010];
	for (int i = 1; i <= N; i++) {
		cin >> v[i].pos;
	}
    sort(v + 1, v + N + 1, [](const Haybale &a, const Haybale &b) { return a.pos < b.pos; });
    v[1].prefix = 1;
    v[N + 1].pos = INT_MAX;
    for (int i = 1; i <= N + 1; i++) {
        v[i].prefix = v[i - 1].prefix + 1;
    }
    // for (int i = 1; i <= N; i++) {
    //     cout << v[i].pos << " " << v[i].prefix << endl;
    // }
    Haybale A, B;
    for (int i = 1; i <= Q; i++) {
        cin >> A.pos >> B.pos;
        Haybale *a_pos = lower_bound(v + 1, v + N + 1, A, [](const Haybale &x, const Haybale &y) { return x.pos < y.pos; });
        Haybale *b_pos = upper_bound(v + 1, v + N + 1, B, [](const Haybale &x, const Haybale &y) { return x.pos < y.pos; });
        // cout << A.pos << ":" << B.pos << " " << a_pos->pos << "-" << b_pos->pos << endl;
        cout << b_pos->prefix - a_pos->prefix << endl;
    }
	return 0;
}