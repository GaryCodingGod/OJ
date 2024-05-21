//Question: According to 36, implement the following functions:
//1. A class Set that inherits from the class LinkedList.
//2.operator== : Determine if two sets are equal.
//3.operator> : return true if A set is a proper superset of B set. Otherwise, return false. For example, {4, 5} > {4}
//4.operator< : return true if A set is a proper subset of B set. Otherwise, return false. For example, {4} < {4, 5}
//5.operator>= : return true if A set is a superset of B set. Otherwise, return false. For example, {4, 5} >= {4, 5}, {4, 5} >= {4}
//6.operator<= : return true if A set is a subset of B set. Otherwise, return false. For example, {4} <= {4, 5}, {4, 5} <= {4, 5}
#include <iostream>

using namespace std;

template<class T>
class LinkedList {
public:
    class Node {
    public:
        T data; // 節點的數據
        Node* next;
        Node() : next(nullptr), data(T()) {}
        Node(T d) : next(nullptr), data(d) {}
        Node(Node* n, T d) : next(n), data(d) {}
    };

    LinkedList() {
        head = new Node();
    }
    ~LinkedList() {
        Node* p = head;
        while (p != nullptr) {
            Node* q = p;
            p = p->next;
            delete q;
        }
    }
    bool addFromHead(T d) {
        Node* p = new Node(head->next, d);
        head->next = p;
        return true;
    }
    bool addFromTail(T d) {
        Node* p = head;
        while (p->next != nullptr) {
            p = p->next;
        }
        Node* q = new Node(d);
        p->next = q;
        return true;
    }
    bool removeFromHead() {
        if (head->next == nullptr) {
            return false;
        }
        Node* p = head->next;
        head->next = p->next;
        delete p;
        return true;
    }
    bool removeFromTail() {
        if (head->next == nullptr) {
            return false;
        }
        Node* p = head;
        while (p->next->next != nullptr) {
            p = p->next;
        }
        Node* q = p->next;
        p->next = nullptr;
        delete q;
        return true;
    }
    friend ostream& operator<<(ostream& os, const LinkedList<T>* l) {
        Node* p = l->head->next;
        os << "{";
        while (p != nullptr) {
            os << p->data;
            if (p->next != nullptr) {
                os << ", ";
            }
            p = p->next;
        }
        os << "}" << endl;
        return os;
    }
    size_t getSize() const {
        size_t size = 0;
        Node* p = head->next;
        while (p != nullptr) {
            size++;
            p = p->next;
        }
        return size;
    }
    int searchData(T d) {
        Node* p = head->next;
        int nodepos = 0;
        while (p != nullptr) {
            if (p->data == d) {
                return nodepos;
            }
            nodepos++;
            p = p->next;
        }
        return -1;
    }
    T operator[](int i) {
        Node* p = head->next;
        int nodepos = 0;
        while (p != nullptr) {
            if (nodepos == i) {
                return p->data;
            }
            nodepos++;
            p = p->next;
        }
        return T();
    }

protected:
    Node* head;
};

template<class T>
class Set : private LinkedList<T> {
public:
    Set() : LinkedList<T>() {}
    ~Set() {}

    bool addElement(T d) {
        if (this->searchData(d) != -1) {
            return false;
        }
        return this->addFromTail(d);
    }

    friend ostream& operator<<(ostream& o, Set<T>* s) {
        o << "{";
        typename LinkedList<T>::Node* current = s->head->next;
        while (current != nullptr) {
            o << current->data;
            if (current->next != nullptr) {
                o << ", ";
            }
            current = current->next;
        }
        o << "}\n";
        return o;
    }

    Set<T>* operator+(Set<T>* s) {
        Set<T>* Uset = new Set<T>();
        typename LinkedList<T>::Node* current = this->head->next;
        while (current != nullptr) {
            Uset->addElement(current->data);
            current = current->next;
        }
        current = s->head->next;
        while (current != nullptr) {
            Uset->addElement(current->data);
            current = current->next;
        }
        return Uset;
    }

    Set<T>* operator-(Set<T>* s) {
        Set<T>* diffSet = new Set<T>();
        typename LinkedList<T>::Node* current = this->head->next;
        while (current != nullptr) {
            if (s->searchData(current->data) == -1) {
                diffSet->addElement(current->data);
            }
            current = current->next;
        }
        return diffSet;
    }

    Set<T>* operator*(Set<T>* s) {
        Set<T>* InterSectSet = new Set<T>();
        typename LinkedList<T>::Node* current = this->head->next;
        while (current != nullptr) {
            if (s->searchData(current->data) != -1) {
                InterSectSet->addElement(current->data);
            }
            current = current->next;
        }
        return InterSectSet;
    }

    bool operator==(Set<T>* s) { //判斷兩個集合是否相等
        if (this->getSize() != s->getSize()) {
            return false;
        }
        typename LinkedList<T>::Node* current = this->head->next;
        while (current != nullptr) {
            if (s->searchData(current->data) == -1) {
                return false;
            }
            current = current->next;
        }
        return true;
    }

    bool operator>(Set<T>* s) { //目前集合中所有元素須包含另一個集合的所有元素，然後目前集合的大小必須大於另一個集合
        if (this->getSize() <= s->getSize()) {
            return false;
        }
        typename LinkedList<T>::Node* current = s->head->next;
        while (current != nullptr) {
            if (this->searchData(current->data) == -1) {
                return false;
            }
            current = current->next;
        }
        return true;
    }

    bool operator<(Set<T>* s) { //目前集合的大小必須小於另一個集合
        if (this->getSize() >= s->getSize()) {
            return false;
        }
        typename LinkedList<T>::Node* current = this->head->next;
        while (current != nullptr) {
            if (s->searchData(current->data) == -1) {
                return false;
            }
            current = current->next;
        }
        return true;
    }

    bool operator>=(Set<T>* s) {
        return (*this > s) || (*this == s);
    }

    bool operator<=(Set<T>* s) {
        return (*this < s) || (*this == s);
    }
};

int main() {
    Set<int> s1;
    Set<int> s2;

    s1.addElement(1);
    s1.addElement(2);
    s1.addElement(3);

    s2.addElement(3);
    s2.addElement(4);
    s2.addElement(5);

    Set<int>* s3 = s1 + &s2;
    Set<int>* s4 = s1 - &s2;
    Set<int>* s5 = s1 * &s2;

    cout << "Set 1: " << &s1;
    cout << "Set 2: " << &s2;
    cout << "Union: " << s3;
    cout << "Difference: " << s4;
    cout << "Intersection: " << s5;

    cout << "s1 == s2: " << (s1 == &s2) << endl;
    cout << "s1 > s2: " << (s1 > &s2) << endl;
    cout << "s1 < s2: " << (s1 < &s2) << endl;
    cout << "s1 >= s2: " << (s1 >= &s2) << endl;
    cout << "s1 <= s2: " << (s1 <= &s2) << endl;

    delete s3;
    delete s4;
    delete s5;

    return 0;
}
