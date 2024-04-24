#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

class DateTime {
private:
    int year, month, day, hours, minutes, seconds;

    bool isNumber(const string& str) const { //檢查字串是否為數字
        for (char const &c : str) {
            if (isdigit(c) == 0) return false;
        }
        return true;
    }

public:
    DateTime() : year(1900), month(1), day(1), hours(0), minutes(0), seconds(0) {}

    DateTime(const string& dateTimeStr) {
        stringstream dateStream, timeStream;
        string dateStr, timeStr;
        string::size_type spacePos = dateTimeStr.find(' ');
        if (spacePos != string::npos) {
            dateStr = dateTimeStr.substr(0, spacePos); // 讀取空格之前的日期
            timeStr = dateTimeStr.substr(spacePos + 1);// 讀取空格之後的時間
        }

        dateStream.str(dateStr);
        string part;
        vector<string> dateParts;
        while (getline(dateStream, part, '/')) {
            dateParts.push_back(part);//將分割後的字符串添加到 vector 中
        }
        if (dateParts.size() == 3 && isNumber(dateParts[0]) && isNumber(dateParts[1]) && isNumber(dateParts[2])) {
            year = stoi(dateParts[0]);
            month = stoi(dateParts[1]);
            day = stoi(dateParts[2]);
        }
      
        timeStream.str(timeStr);
        vector<string> timeParts;
        while (getline(timeStream, part, ':')) {
            timeParts.push_back(part);
        }
        if (timeParts.size() == 3 && isNumber(timeParts[0]) && isNumber(timeParts[1]) && isNumber(timeParts[2])) {
            hours = stoi(timeParts[0]);     
            minutes = stoi(timeParts[1]);
            seconds = stoi(timeParts[2]);
        }
    }

    string toString() const {
        stringstream ss;
        ss << setw(4) << setfill('0') << year << '/'
           << setw(2) << setfill('0') << month << '/'
           << setw(2) << setfill('0') << day << ' '
           << setw(2) << setfill('0') << hours << ':'
           << setw(2) << setfill('0') << minutes << ':'
           << setw(2) << setfill('0') << seconds;
        return ss.str();
    }
};
int main() {
    string dateTimeStr;
    while (getline(cin, dateTimeStr)) {
        if (dateTimeStr.empty()) break; 

        DateTime dateTime(dateTimeStr);
        cout << dateTime.toString() << endl;
    }
    return 0;
}