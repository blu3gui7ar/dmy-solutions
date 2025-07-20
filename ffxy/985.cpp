#include <bits/stdc++.h>
using namespace std;
int main () {
	string s;
	getline(cin, s);
	
    string a, b;
    getline(cin, a);
    getline(cin, b);
    
    if (a.empty()) {  // 处理空字符串情况
        cout << s;
        return 0;
    }

	size_t x = 0;
	while (x < s.size()) {
		//1. find substring
		x = s.find(a, x);
		//2. not found, end
		if (x == s.npos) {
			cout << s;
			return 0;
		}
		//3. found, check word separator(' ' of begin/end of string)
		//4.1 word confirmed, break;
		//4.2 not a word, find from the end of substring
		if ((x == 0 || s[x - 1] == ' ') &&
			(x + a.size() >= s.size() 
				|| s[x + a.size()] == ' ')) {
			break;
		} else {
			x += a.size();
		}
	}
    // cout << s.substr(0, x) << b << s.substr(x + a.size());
	for (size_t i = 0; i < s.size(); i++) {
		if (i == x) {
			cout << b;
			i += a.size();
		}
		if (i < s.size()) {
			cout << s[i];
		}
	}
	return 0;
}