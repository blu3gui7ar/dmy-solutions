#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 998244353;

struct AccMove {
    int idx = 0;
    ll up = 0;
    ll down = 0;
    ll left = 0;
    ll right = 0;
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
    

    int n;
    cin >> n;
    vector<pair<char, int>> move(n+1);
    vector<AccMove> accMove;
    AccMove accm;
    accMove.push_back(accm);
    for (int i = 1; i <= n; i++) {
        cin >> move[i].first >> move[i].second;
        if (move[i].first == 'U') {
            accm.up += move[i].second;
        } else if (move[i].first == 'D') {
            accm.down += move[i].second;
        } else if (move[i].first == 'L') {
            accm.left += move[i].second;
        } else if (move[i].first == 'R') {
            accm.right += move[i].second;
        }
        accm.duration += move[i].second;
        accm.idx = i;
        accMove.push_back(accm);
    }
    int Q;
    cin >> Q;
    for (int i = 0; i < Q; i++) { 
        int l, r; 
        ll t;
        cin >> l >> r >> t;

        AccMove loopMove;
        loopMove.up = accMove[n].up - accMove[r].up + accMove[l-1].up;
        loopMove.down = accMove[n].down - accMove[r].down + accMove[l-1].down;
        loopMove.left = accMove[n].left - accMove[r].left + accMove[l-1].left;
        loopMove.right = accMove[n].right - accMove[r].right + accMove[l-1].right;
        loopMove.duration = accMove[n].duration - accMove[r].duration + accMove[l-1].duration;
        
        ll loops = t / loopMove.duration;
        ll rem = t % loopMove.duration;
        
        ll x = loops * (loopMove.right - loopMove.left);
        ll y = loops * (loopMove.up - loopMove.down);
        
        AccMove m;
        m.idx = -1;
        m.up = m.down = m.right = m.left = -1;
        m.duration = rem;
        auto it = upper_bound(accMove.begin(), accMove.end(), m, [accMove, l, r](const AccMove& a, const AccMove& b) {
            ll da = a.duration;
            if (a.idx >= l && a.idx <= r) {
                da = accMove[l - 1].duration;
            }
            ll db = b.duration;
            if (b.idx >= l && b.idx <= r) {
                db = accMove[l - 1].duration;
            }
            return da < db;
        });
        
        
        if (rem > 0) {
            ll dt = it->duration;
            ll dx = it->right - it->left;
            ll dy = it->up - it->down;
            if (it->idx > r) {
                dt = it->duration - accMove[r].duration + accMove[l - 1].duration;
                dx = it->right - it->left - (accMove[r].right - accMove[r].left) + (accMove[l-1].right - accMove[l-1].left);
                dy = it->up - it->down - (accMove[r].up - accMove[r].down) + (accMove[l-1].up - accMove[l-1].down);
            }
            
            x += dx;
            y += dy;
            
            auto mv = move[it->idx];
            ll diff = dt - rem;
            if (mv.first == 'R') {
                x -= diff;
            } else if (mv.first == 'L') {
                x += diff;
            } else if (mv.first == 'U') {
                y -= diff;
            } else {
                y += diff;
            }
        }
        
        cout << x << " " << y << endl;
    }
    

    return 0;
}