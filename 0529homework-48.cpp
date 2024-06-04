#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class CountLength {
    private:
        long count;
        long num;
    public:
        CountLength(long n): num(n), count(1) {}

        long countMaxLength() {

            while (num != 1) {
                count++;
                if (num % 2 == 1)
                    num = (3 * num) + 1;
                else
                    num /= 2;
            }
            return count;
        }

        
};

int main() {
    long head, tail;
    long tempHead, tempTail;

    while (cin >> head >> tail) {
        tempHead = head;
        tempTail = tail;
        if (head > tail)
            swap(tempHead, tempTail);

        vector<long> record(tempTail - tempHead + 1);
        for (int i = tempHead, j = 0; i <= tempTail; i++, j++) {
            CountLength cl(i);
            record[j] = cl.countMaxLength();
        }
        cout << head << " " << tail << " " << *max_element(record.begin(), record.end()) << endl;
    }

    return 0;
}