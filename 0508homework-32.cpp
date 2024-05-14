//Question: Using class Set contain integer elements
//Question: Implementing a default constructor and a copy constructor
//Question: Two member functions for adding elements.
#include <iostream>
using namespace std;
template<class T>
class Set {
    private:
       T element[100];
       int count;
    public:
        Set(): count(0) {
            for(int i = 0;i < 100;i++)
                element[i] = 0;
        }
        // 拷貝構造函數
        Set(const Set<T> &s) {
            count = s.count;
            for(int i = 0;i < count;i++)
                this->element[i] = s.element[i];
        }
       void display() {
            if (count >= 100)
                cout << "0";
            for (int i = 0; i < count; i++) {
                cout << element[i] << " ";            
            }
        }
        int add(const T &x) { // 添加一個元素到Set中
            if (count >= 100 || contains(x))  
                return 0;
            this->element[count] = x;
            count++;
            return 1;
        }

        int add(const Set<T> &s) {  // 將另一個Set中的所有元素添加到當前Set中
            int initialCount = count;
            for(int i = 0; i < s.count; i++)
                add(s.element[i]);
            return count - initialCount;
        }

        // 檢查是否已經包含相同元素
        bool contains(const T &x) const {
            for (int i = 0; i < count; i++) {
                if (element[i] == x)
                    return true;
            }
            return false;
        }
};