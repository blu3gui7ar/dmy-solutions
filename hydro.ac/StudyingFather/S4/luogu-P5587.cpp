#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 998244353;
int main (int argc, char const *argv[]) {

    vector<string> origin;
    vector<string> input;
    int T;

    string s;
    while(getline(cin, s)) {
        if (s == "EOF") {
            break;
        }
        origin.push_back(s);
    }   

    while(getline(cin, s)) {
        if (s == "EOF") {
            break;
        }
        // cout << "input: " << s << endl;
        for (size_t pos = s.find_first_of("<"); pos != string::npos; pos = s.find_first_of("<", pos == 0 ? pos : pos - 1)) {
            s.replace(pos == 0 ? pos : pos - 1, pos == 0 ? 1 : 2, "");
            // cout << "fixed input: " << s << endl;
        }
        input.push_back(s);
    }   
    cin >> T;

    ll cnt = 0;
    for(size_t i = 0; i < origin.size(); i++) {
        if (i >= input.size()) {
            break;
        }
        for(size_t j = 0; j < origin[i].size(); j++) {
            if (j >= input[i].size()) {
                break;
            }
            if(origin[i][j] == input[i][j]) {
                cnt++;
            }
        }
    }
    
    cout << round(cnt * 60 / T) << endl;
    
    return 0;
}