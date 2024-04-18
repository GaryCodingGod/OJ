#include <iostream>
#include <string>
using namespace std;

class License {
public:
    bool containsFour(int number) {
        string numberStr = to_string(number);
        for (char c : numberStr) {
            if (c == '4') {
                return true;
            }
        }
        return false;
    }
};

int main() {
    License checker;
    int Number;

    cin >> Number;

    bool hasFour = checker.containsFour(Number);

    if(hasFour) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}
