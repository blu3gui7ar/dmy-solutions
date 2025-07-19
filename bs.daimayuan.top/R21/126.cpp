#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 998244353;

struct AccMove {
    int idx = 0;
    ll x = 0;
    ll y = 0;
    ll duration = 0;
};

int main (int argc, char const *argv[]) {
    // ios_base::sync_with_stdio(false);
    // cin.tie(nullptr);
    // solve the io redirect problem for vscode
    if (argc > 1){
        if (argv[1][0] == '<') {
            freopen(argv[2], "r", stdin);
        } else {
            freopen(argv[1], "r", stdin);
        }
    }
    

    ll n;
    cin >> n;
    vector<pair<char, ll>> move(n+1);
    vector<AccMove> accMove;
    AccMove accm;
    accMove.push_back(accm);
    for (int i = 1; i <= n; i++) {
        cin >> move[i].first >> move[i].second;
        if (move[i].first == 'U') {
            accm.y += move[i].second;
        } else if (move[i].first == 'D') {
            accm.y -= move[i].second;
        } else if (move[i].first == 'L') {
            accm.x -= move[i].second;
        } else if (move[i].first == 'R') {
            accm.x += move[i].second;
        }
        accm.duration += move[i].second;
        accm.idx = i;
        accMove.push_back(accm);
    }
    int Q;
    cin >> Q;
    for (int i = 0; i < Q; i++) { 
        ll l, r; 
        ll t;
        cin >> l >> r >> t;
        assert(l >= 1);

        AccMove loopMove;
        loopMove.x = accMove[n].x - accMove[r].x + accMove[l-1].x;
        loopMove.y = accMove[n].y - accMove[r].y + accMove[l-1].y;
        loopMove.duration = accMove[n].duration - accMove[r].duration + accMove[l-1].duration;
        
        ll loops = t / loopMove.duration;
        ll rem = t % loopMove.duration;
        
        ll x = loops * loopMove.x;
        ll y = loops * loopMove.y;
        
        if (rem > 0) {
            ll left = 1LL;
            ll right = n + 1;
            ll rs = n + 1;
            while (left < right) {
                ll mid = (left + right) / 2;
                ll duration;
                if (mid < l) {
                    duration = accMove[mid].duration;
                }
                else if (mid >= l && mid <= r) {
                    duration = accMove[l-1].duration;
                }
                else if (mid > r) {
                    duration = accMove[mid].duration - accMove[r].duration + accMove[l - 1].duration;
                }

                if (duration < rem) {
                    left = mid + 1;
                    if (left >= l && left <= r) {
                        left = r + 1;
                    }
                }
                else if (duration >= rem) {
                    rs = mid;
                    right = mid;
                    if (right >= l && right <= r) {
                        right = l;
                    }
                }
            }

            AccMove found = accMove[rs];

            ll dt = found.duration;
            ll dx = found.x;
            ll dy = found.y;
            if (found.idx > r) {
                dt = found.duration - accMove[r].duration + accMove[l - 1].duration;
                dx = found.x - accMove[r].x + accMove[l - 1].x;
                dy = found.y - accMove[r].y + accMove[l - 1].y;
            }

            x += dx;
            y += dy;

            auto mv = move[found.idx];
            ll diff = dt - rem;
            if (mv.first == 'R') {
                x -= diff;
            }
            else if (mv.first == 'L') {
                x += diff;
            }
            else if (mv.first == 'U') {
                y -= diff;
            }
            else {
                y += diff;
            }
        }
        
        cout << x << " " << y << endl;
    }
    

    return 0;
}