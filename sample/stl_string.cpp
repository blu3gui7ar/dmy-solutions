#include <string>
#include <iostream>
using namespace std;

int main() {
    
    string s1 = "abc";
    string s2 = "def";

    string s3 = s1 + s2;
    cout << "s3 = s1 + s2: " << s3 << ' ' << s1 << ' ' << s2 << endl;

    string s4 = operator+(s1, s2);
    s1.operator+=(s2);
    s1 += s2;
    
    
    cout << "s1 == s2: " << (s1 == s2) << endl;
    cout << "\"abc\" == s1: " << ("abc" == s1) << endl;
    
    swap(s1, s2);
    cout << "swap(s1,s2): " << s1 << ' ' << s2 << endl;
    s1.swap(s2);
    cout << "s1.swap(s2): " << s1 << ' ' << s2 << endl;


    erase(s1, 'b');
    cout << "erase(s1, 'b'): " << s1 << endl;
    erase_if(s2, [](char c){ return c == 'e'; });
    cout << "erase_if(s2, xxx): " << s2 << endl;

    s1.erase();
    cout << "s1.erase(): " << s1 << endl;

    s2.erase(s2.begin() + 1);
    cout << "s2.erase(s2.begin() + 1): " << s2 << endl;

    s1 = "abc";
    s2 = "def";
    s1.erase(s1.begin(), s1.end() - 1);
    cout << "s1.erase(s1.begin(), s1.end() - 1): " << s1 << endl;
    

    operator>>(cin, s2);
    cout << s2 << endl;
    cin >> s1;
    cout << s1 << endl;
   
    getline(cin, s3);
    cout << s3 << endl;
    
    int a = stoi("123");
    long b = stol("135");
    long long c = stoll("1231421321");
    int h = stoi("123ABC", nullptr, 16);
    cout << a << ", " <<  b << ", " << c << ", hex: " << h << ", " <<
        // stoi("asdfa1231321") << ", " << 
        stoi("    1231321") << ", " << 
        stoi("1231zcxvzxc") <<endl;
    
    float f = stof("123.321");
    double d = stod("123.456");
    long double ld = stold("123.456890");
    
    cout << f << ", " << d << ", " << ld << endl;
    
    unsigned long ul = stoul("1234");
    unsigned long long ull = stoull("123213098194713");
    
    cout << ul << ", " << ull << endl;

    cout << to_string(f) << endl;
    
    for(/* string::iterator  */ auto it = s4.begin(); it != s4.end(); it++) {
        cout << *it;
    }
    cout << endl;

    for(string::reverse_iterator it = s4.rbegin(); it != s4.rend(); it++) {
        cout << *it;
    }
    cout << endl;
    
    
    cout << "s4.size(): " << s4.size() << ", " << size(s4) << endl;
    cout << "s4.ssize(): " << ssize(s4) << endl;
    long i = ssize(s4);
    for (--i; i != -1; --i)
        std::cout << s4[i] << (i ? ' ' : '\n');
    
    cout << "empty: " << s4.empty() << endl;
    s4.clear();
    cout << "empty: " << s4.empty() << endl;
    
    
    return 0;
}