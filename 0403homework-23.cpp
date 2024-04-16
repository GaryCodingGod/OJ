#include <iostream>
#include <string>
#include <ctime>
#include <sstream>
#include <iomanip>

using namespace std;

class Date {
private:
    int year, month, day;

public:
    // Default constructor sets date to 1900/01/01
    Date() : year(1900), month(1), day(1) {}

    // Constructor that takes a date string in "yyyy/mm/dd" format
    Date(const string& date) {
        sscanf(date.c_str(), "%d/%d/%d", &year, &month, &day);
    }

    // Function to return a string representation of the date in "yyyy/mm/dd" format
    string toString() const {
        ostringstream oss;
        oss << year << "/" << setfill('0') << setw(2) << month << "/" << setw(2) << day;
        return oss.str();
    }

    // Overloaded operator- to find the difference in days between two dates
    int operator-(const Date& other) const {
        // Convert both dates to tm struct
        struct tm a = {0, 0, 0, day, month - 1, year - 1900};
        struct tm b = {0, 0, 0, other.day, other.month - 1, other.year - 1900};
        
        // Convert tm structs to time_t
        time_t x = mktime(&a);
        time_t y = mktime(&b);
        
        // Calculate difference in seconds and then convert to days
        double difference = difftime(x, y);
        return static_cast<int>(difference / (60 * 60 * 24));
    }
};

int main() {
    string date1String, date2String;
    
    cin >> date1String;
    cin >> date2String;
    
    Date date1(date1String);
    Date date2(date2String);

    int difference = date2 - date1;
    
    cout << difference << endl;
    
    return 0;
}