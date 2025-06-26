#include <bits/stdc++.h>
using namespace std;

struct Order
{
    int id;
    int time;
    int duration;
};

int main () {
    int n;
    cin >> n;
    vector<Order> orders(n);
    for(int i = 1; i <= n; i++) {
        int t,d;
        cin >> t >> d;
        orders.push_back({i,t,d});
    }
    
    sort(orders.begin(), orders.end(), [](Order a, Order b) {
        return a.time < b.time;
    });
    
    int time = 0;
    vector<int> fail_orders;
    for (Order order: orders) {
        if (order.time < time ) {
            fail_orders.push_back(order.id);
        } else {
            time = order.time + order.duration;
        }
    }
    if (fail_orders.empty()) {
        cout << "Perfect";
    } else {
        sort(fail_orders.begin(), fail_orders.end());
        for (int order: fail_orders) {
            cout << order << " ";
        }
    }
    cout << endl;
    return 0;
}