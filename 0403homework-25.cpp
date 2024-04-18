#include <iostream>
#include <vector>
using namespace std;

class GridCity {
private:
    vector<int> streets;
    vector<int> avenues;

    // 使用插入排序算法對數字向量進行排序
    void sortVector(vector<int> &v) {
        for (size_t i = 1; i < v.size(); i++) {
            int key = v[i];
            int j = i - 1;

            while (j >= 0 && v[j] > key) {
                v[j + 1] = v[j];
                j--;
            }
            v[j + 1] = key;
        }
    }

public:
    void addFriendLocation(int street, int avenue) {
        streets.push_back(street);
        avenues.push_back(avenue);
    }

    // 計算會面點的函數，不再返回 pair，而是通過引用返回街道和大道的中位數
    void findMeetingPoint(int &medianStreet, int &medianAvenue) {
        sortVector(streets);
        sortVector(avenues);
        // 選擇中間的第一個元素作為中位數
    medianStreet = streets[(streets.size() - 1) / 2];
    medianAvenue = avenues[(avenues.size() - 1) / 2];
    }
};

int main() {
    int T, S, A, F, street, avenue;
    cin >> T; 
    while (T--) {
        cin >> S >> A >> F; 
        GridCity city; 
        for (int i = 0; i < F; i++) {
            cin >> street >> avenue; 
            city.addFriendLocation(street, avenue); 
        }
        
        int medianStreet, medianAvenue;
        city.findMeetingPoint(medianStreet, medianAvenue); // 計算會面點
        cout << "(Street: " << medianStreet << ", Avenue: " << medianAvenue << ")" << endl;
    }
    return 0;
}
