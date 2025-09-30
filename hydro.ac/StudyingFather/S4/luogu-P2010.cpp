#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 998244353;

int end_date_of(int year, int month) {
    if (month == 2) {
        return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0 ? 29 : 28;
    } else if (month == 4 || month == 6 || month == 9 || month == 11) {
        return 30;
    } else {
        return 31;
    }
}

bool is_mirror(int year, int month, int date) {
    string y = to_string(year);
    stringstream ss;
    ss << setw(2) << setfill('0') << month << setw(2) << setfill('0') << date ;
    return string(y.rbegin(), y.rend()) == ss.str();
}

bool is_valid(int year, int month, int date) {
    int last_date = 31;
    if (month == 2) {
        last_date = (year % 4 == 0 && year % 100 != 0) || year % 400 == 0 ? 29 : 28;
    } else if (month == 4 || month == 6 || month == 9 || month == 11) {
        last_date = 30;
    } else if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
        last_date = 31;
    } else {
        //invalid month
        return false;
    }
    //valid date
    return date >= 1 && date <= last_date;
}

int main (int argc, char const *argv[]) {
    string begin;
    string end;
    cin >> begin >> end;

    int s_year = stoi(begin.substr(0, 4));
    int s_month = stoi(begin.substr(4, 2));
    int s_date = stoi(begin.substr(6, 2));

    int e_year = stoi(end.substr(0, 4));
    int e_month = stoi(end.substr(4, 2));
    int e_date = stoi(end.substr(6, 2));
   
    // cout << s_year << " " << s_month << " " << s_date << endl;
    // cout << e_year << " " << e_month << " " << e_date << endl;
    
    int cnt = 0;
    for (int year = s_year; year <= e_year; year++) {
        string y = to_string(year);
        string md = string(y.rbegin(), y.rend());
        string m = md.substr(0, 2);
        int month = stoi(m);
        string d = md.substr(2, 2);
        int date = stoi(d);
        
        // cout << year << " " << month << " " << date << endl;
        if (year == s_year) {
            if (month < s_month) {
                continue;
            } else if (month == s_month) {
                if (date < s_date) {
                    continue;
                }
            }
        }
        if (year == e_year) {
            if (month > e_month) {
                continue;
            } else if (month == e_month) {
                if (date > e_date) {
                    continue;
                }
            }
        }   
        if (is_valid(year, month, date)) {
            cnt++;
        }
    }
    
    /* brute force

    for (int year = s_year; year <= e_year; year++) {
        int from_month = year == s_year ? s_month : 1;
        int to_month = year == e_year ? e_month : 12;
        for (int month = from_month; month <= to_month; month++) {
            int from_date = (year == s_year && month == s_month) ? s_date : 1;
            int to_date = (year == e_year && month == e_month) ? e_date : end_date_of(year, month);
            for (int date = from_date; date <= to_date; date++) {
                if (is_mirror(year, month, date)) {
                    cnt++;
                }
            }
        }
    }
    */
    
    cout << cnt << endl;
    
    return 0;
}