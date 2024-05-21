//Question: Given multiple test cases, each test case contains a sequence of car weights.
//Question: The test cases contain an integer 0 <= n <= 2000, n is an non-negative integer.
//Question: For each test case, find the longest possible train that can be formed, where the weights of the cars within the train must be in decreasing order
#include <iostream>
#include <vector>

using namespace std;

#define MAX(x, y) ((x) >= (y) ? (x) : (y))

// 用二元搜尋法，返回插入位置
int binarySearch(const vector<int>& num, int target) {
    int left = 0, right = num.size();
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (num[mid] < target) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    return left;
}

class Train {
public:
    Train(const vector<int>& cars) : cars(cars) {}

    int getMaxLength() {
        int n = cars.size();
        if (n == 0) return 0;

        vector<int> headCheck, tailCheck;
        int maxLength = 0;

        for (int i = n - 1; i >= 0; --i) {
            int len1, len2;

            int pos = binarySearch(tailCheck, cars[i]);
            if (pos == tailCheck.size()) {
                tailCheck.push_back(cars[i]);
                len2 = tailCheck.size();
            } else {
                tailCheck[pos] = cars[i];
                len2 = pos + 1;
            }

            pos = binarySearch(headCheck, -cars[i]);
            if (pos == headCheck.size()) {
                headCheck.push_back(-cars[i]);
                len1 = headCheck.size();
            } else {
                headCheck[pos] = -cars[i];
                len1 = pos + 1;
            }

            maxLength = MAX(maxLength, len1 + len2 - 1);
        }

        return maxLength;
    }

private:
    const vector<int>& cars;  
};

int main() {
    int T;
    cin >> T;  

    while (T--) {
        int n;
        cin >> n;  
        vector<int> cars(n);
        for (int i = 0; i < n; ++i) {
            cin >> cars[i];  
        }

        Train train(cars);
        cout << train.getMaxLength() << endl;  
    }

    return 0;  
}
