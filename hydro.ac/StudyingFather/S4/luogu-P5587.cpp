#include <bits/stdc++.h>
using namespace std;
int main() {

    vector<string> origin;
    vector<string> input;
    int T;

    string s;
    while(getline(cin, s)) {
        if (s == "EOF") {
            break;
        }
        string processed;
        for (char c : s) {
            if (c == '<') {
                if (!processed.empty()) {
                    processed.pop_back();
                }
            } else {
                processed.push_back(c);
            }
        }
        origin.push_back(processed);
    }

    while(getline(cin, s)) {
        if (s == "EOF") {
            break;
        }
        string processed;
        for (char c : s) {
            if (c == '<') {
                if (!processed.empty()) {
                    processed.pop_back();
                }
            } else {
                processed.push_back(c);
            }
        }
        input.push_back(processed);
    }
    cin >> T;

    long long cnt = 0;
    for(size_t i = 0; i < origin.size() && i < input.size(); i++) {
        for(size_t j = 0; j < origin[i].size() && j < input[i].size(); j++) {
            if(origin[i][j] == input[i][j]) {
                cnt++;
            }
        }
    }
    
    cout << round(cnt * 60.0 / T) << endl;
    
    return 0;
}