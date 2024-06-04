#include <iostream>
#include <algorithm>
using namespace std;

class checkPrime {
    private:
        string ori, rev;

    public:
        checkPrime(string o, string r): ori(o), rev(r) {}

        int check(string num) {
            int count = 0;
            for (int i = 1; i * i <= stoi(num); i++) {
                if (stoi(num) % i == 0)
                    count++;
            }
            return count;
        }

        void print(int (checkPrime::*check)(string)) {
            int oriCount = checkPrime::check(ori);
            int revCount = checkPrime::check(rev);

            if (oriCount > 1) {
                cout << ori << " is not prime." << endl;
            }

            else {
                if (oriCount == 1 && revCount != 1)
                    cout << ori << " is prime." << endl;
                else if(oriCount == 1 && revCount == 1 && ori != rev)
                    cout << ori << " is emirp." << endl;
                else
                    cout << ori << " is prime." << endl;
            }
        }
};


int main() {
    
    string number, rev_number;
    int priCount = 0;

    while (cin >> number) {
        rev_number = number;
        reverse(rev_number.begin(), rev_number.end());
        checkPrime c(number, rev_number);
        c.print(&checkPrime::check);
    }
    

    return 0;
}