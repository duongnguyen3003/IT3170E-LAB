#include <bits/stdc++.h>
#define int long long
using namespace std;

const int SZ = 1e6 + 5;
struct call_log {
    string from_number;
    string to_number;
    string date;
    string start;
    string end;
};
call_log calls[SZ];
string s;
int total_calls = 0;

void Read() {
    while (1) {
        getline(cin, s);
        if (s[0] == '#') {
            break;
        }
        if (s.find("call") != string::npos) {
            total_calls++;
            stringstream ss(s);
            string tmp, fromnumber, tonumber, date, start, end;
            ss >> tmp >> fromnumber >> tonumber >> date >> start >> end;
            calls[total_calls].from_number = fromnumber;
            calls[total_calls].to_number = tonumber;
            calls[total_calls].date = date;
            calls[total_calls].start = start;
            calls[total_calls].end = end;           
        }
    }
}

int Check() {
    for (int i = 1; i <= total_calls; i++) {
        for (int j = 0; j < (int)calls[i].from_number.size(); j++) {
            if (!isdigit(calls[i].from_number[j])) {
                return 0;
            }
        }
        for (int j = 0; j < (int)calls[i].to_number.size(); j++) {
            if (!isdigit(calls[i].to_number[j])) {
                return 0;
            }
        }
    }
    return 1;
}

unordered_map<string, int> number_calls, time_calls;

void Prep() {
    for (int i = 1; i <= total_calls; i++) {
        number_calls[calls[i].from_number]++;
        
        string cur_start = calls[i].start;
        string cur_end = calls[i].end;
        int hour_start = (cur_start[0] - '0') * 10 + (cur_start[1] - '0');
        int hour_end = (cur_end[0] - '0') * 10 + (cur_end[1] - '0');
        int minute_start = (cur_start[3] - '0') * 10 + (cur_start[4] - '0');
        int minute_end = (cur_end[3] - '0') * 10 + (cur_end[4] - '0');
        int second_start = (cur_start[6] - '0') * 10 + (cur_start[7] - '0');
        int second_end = (cur_end[6] - '0') * 10 + (cur_end[7] - '0');
        int total_start = hour_start * 3600 + minute_start * 60 + second_start;
        int total_end = hour_end * 3600 + minute_end * 60 + second_end;

        time_calls[calls[i].from_number] += total_end - total_start;
    }
}

int check = Check();

void Solve() {
    while (1) {
        cin >> s;
        if (s[0] == '#') {
            break;
        }
        if (s == "?check_phone_number") {
            cout << check << "\n";
        } else if (s == "?number_total_calls") {
            cout << total_calls << "\n";
        } else if (s == "?number_calls_from") {
            string number;
            cin >> number;
            cout << number_calls[number] << "\n";
        } else if (s == "?count_time_calls_from") {
            string number;
            cin >> number;
            cout << time_calls[number] << "\n";
        } 
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    Read();
    Prep();
    Solve();
    return 0;
}
