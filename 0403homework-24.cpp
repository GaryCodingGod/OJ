#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <iomanip>
#include <cctype>

using namespace std;

// 檢查字符串是否為純數字
bool isNumber(const string& str) {
    for (char const &c : str) {
        if (isdigit(c) == 0) return false;
    }
    return true;
}

class Time {
private:
    vector<int> partTimes; // 以整數存儲小時、分鐘、秒

public:
    Time() : partTimes{0, 0, 0} {}

    Time(const string& t) {
        stringstream ss(t);
        string part;
        vector<string> parts;
        while (getline(ss, part, ':')) {
            parts.push_back(part);
        }
        
        if (parts.size() == 3 && isNumber(parts[0]) && isNumber(parts[1]) && isNumber(parts[2])) {
            partTimes.push_back(stoi(parts[0]));
            partTimes.push_back(stoi(parts[1]));
            partTimes.push_back(stoi(parts[2]));
        } else {
            // 如果格式不正確，設置為0
            partTimes = {0, 0, 0};
        }
    }

    string toString() const {
        stringstream ss;
        ss << setw(2) << setfill('0') << partTimes[0] << ":"
           << setw(2) << setfill('0') << partTimes[1] << ":"
           << setw(2) << setfill('0') << partTimes[2];
        return ss.str();
    }
};

class Date {
private:
    int year, month, day;

public:
    Date() : year(1900), month(1), day(1) {}

    Date(const string& dateStr) {
        stringstream ss(dateStr);
        string part;
        vector<string> parts;
        while (getline(ss, part, '/')) {
            parts.push_back(part);
        }
        
        if (parts.size() == 3 && isNumber(parts[0]) && isNumber(parts[1]) && isNumber(parts[2])) {
            year = stoi(parts[0]);
            month = stoi(parts[1]);
            day = stoi(parts[2]);
        } else {
            // 如果格式不正確，設置為預設日期
            year = 1900;
            month = 1;
            day = 1;
        }
    }

    string toString() const {
        stringstream ss;
        ss << setw(4) << setfill('0') << year << '/'
           << setw(2) << setfill('0') << month << '/'
           << setw(2) << setfill('0') << day;
        return ss.str();
    }
};

class DateTime {
private:
    Date date;
    Time time;

public:
    DateTime() : date(), time() {}

    DateTime(const string& dateTimeStr) {
        stringstream ss(dateTimeStr);
        string dateStr, timeStr;
        getline(ss, dateStr, ' ');
        getline(ss, timeStr);
        date = Date(dateStr);
        time = Time(timeStr);
    }

    string toString() const {
        return date.toString() + " " + time.toString();
    }
};

int main() {
    string dateTimeStr;
    while (getline(cin, dateTimeStr)) {
        if (dateTimeStr.empty()) break; // 當輸入為空行時結束輸入

        DateTime dateTime(dateTimeStr);
        cout << dateTime.toString() << endl;
    }
    return 0;
}
