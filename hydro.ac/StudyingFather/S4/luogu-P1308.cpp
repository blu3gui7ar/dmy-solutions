#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 998244353;

int main (int argc, char const *argv[]) {
    string target;
    string sentence;
    getline(cin, target);
    transform(target.begin(), target.end(), target.begin(), [](char c) { return tolower(c); });
    getline(cin, sentence);
    transform(sentence.begin(), sentence.end(), sentence.begin(), [](char c) { return tolower(c); });
    
    vector<string> words;
    vector<int> pos;
    vector<char> word;
    for (size_t i = 0; i < sentence.size(); i++) {
        if (isalpha(sentence[i])) {
            word.push_back(sentence[i]);
        } else {
            if (word.size() > 0) {
                words.push_back(string(word.begin(), word.end()));
                pos.push_back(i - word.size());
                word.clear();
            }
        }
    }
    
    
    int count = 0;
    int start = -1;
    for (size_t i = 0; i < words.size(); i++) {
        if (words[i] == target) {
            if (start == -1) {
                start = pos[i];
            }
            count++;
        }
    }
        
    if (count == 0) {
        cout << -1 << endl;
    } else {
        cout << count << " " << start << endl;
    }
    
    return 0;
} 