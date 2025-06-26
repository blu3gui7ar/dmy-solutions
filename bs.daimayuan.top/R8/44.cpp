#include <bits/stdc++.h>
using namespace std;

int main () {
    struct Student {
        int scores[11] = {0};
        int pass = 0;
        int total = 0;
        int no;
    };

    int n, m;
    cin >> n >> m;
    assert(n > 0 || n < 2001 || m > 0 || m < 11);
    Student students[2001];
    Student *refs[2001];
    for (int i = 0; i < n; i++) {
        Student &s = students[i];
        s.no = i;
        for (int j = 0; j < m; j++) {
            cin >> s.scores[j];
            s.pass += s.scores[j] >= 60;
            s.total += s.scores[j];
        }
        refs[i] = &s;
    }

    sort(refs, refs + n, [](Student *a, Student *b) {
        if (a->pass != b->pass) {
            return a->pass > b->pass;
        } else if (a->total != b->total) {
            return a->total > b->total;
        } else {
            return a->no < b->no;
        }
    });
    
    for (int i = 0; i < n; i++) {
        cout << (*(refs+i))->no + 1 << " ";
    }
    cout << endl;
    
    return 0;
}