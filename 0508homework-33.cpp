//Question: Referencing question 32
//Question: Override + to operate union
//Question: Override - to operate intersect
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
        int add(const T &x) {
            if (count >= 100 || contains(x))  
                return 0;
            this->element[count] = x;
            count++;
            return 1;
        }

        int add(const Set<T> &s) {
            int initialCount = count;
            for(int i = 0; i < s.count; i++)
                add(s.element[i]);
            return count - initialCount;
        }

        bool contains(const T &x) const {
            for (int i = 0; i < count; i++) {
                if (this->element[i] == x)
                    return true;
            }
            return false;
        }

        Set<T> operator+(const Set<T> &s) { //實現兩個Set的聯集
            Set<T> result = *this;
            result.add(s);
            return result;
        }
        Set<T> operator-(const Set<T> &s) { //實現兩個Set的交集
            Set<T> result;
            for (int i = 0; i < s.count; i++) {
                if (contains(s.element[i]))
                    result.add(s.element[i]);//如果當前Set包含該元素，則添加到結果Set中
            }
            return result;
        }
};