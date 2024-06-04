//Question: In this problem, you have to decide whether a number N is Non-prime or Prime or Emirp. Assume that 1 < N < 1000000.
// ex: 17 is Emirp because 17 as well as 71 are Prime.
#include <iostream>
#include <algorithm>
using namespace std;

class checkPrime {
    private:
        string original, rev;

    public:
        checkPrime(string o, string r): original(o), rev(r) {}

        int check(string num) { //檢查是否為質數
            int count = 0;
            for (int i = 1; i * i <= stoi(num); i++) {
                if (stoi(num) % i == 0)
                    count++;
            }
            return count;
        }

        void print() { 
            int originalCount = check(original);
            int revCount = check(rev);

            if (originalCount > 1) {
                cout << original << " is not prime." << endl;
            }

            else {
                if (originalCount == 1 && revCount != 1)
                    cout << original << " is prime." << endl;
                else if(originalCount == 1 && revCount == 1 && original != rev)
                    cout << original << " is emirp." << endl;
                else
                    cout << original << " is prime." << endl;
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
        c.print();
    }
    

    return 0;
}