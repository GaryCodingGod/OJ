//Question: Implement a class Set that inherits from LinkedList.(HW27) The Set class should have
//1. A method addElement that adds an element to the set. The element should be unique.
//2. A method operator+ that returns the union of two sets.
//3. A method operator- that returns the difference of two sets.
//4. A method operator* that returns the intersection of two sets.
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
        Node(Node* n) : next(n), data(T()) {}
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
        int nodepos = 0;//紀錄當前節點的位置
        while (p != nullptr) {
            if (p->data == d) {
                return nodepos;
            }
            nodepos++;
            p = p->next;
        }
        return -1;
    }
    T operator[](int i) { //根據節點位置訪問鏈結串列的元素  
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

    bool addElement(T d) { //添加元素確保元素唯一 
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

    Set<T>* operator+(Set<T>* s) { //聯集
        Set<T>* Uset = new Set<T>();
        typename LinkedList<T>::Node* current = this->head->next; //::要告訴編譯器Node是LinkedList的類別
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

    Set<T>* operator-(Set<T>* s) { //差集
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

    Set<T>* operator*(Set<T>* s) { //交集
        Set<T>* InterSectset = new Set<T>();
        typename LinkedList<T>::Node* current = this->head->next;
        while (current != nullptr) {
            if (s->searchData(current->data) != -1) {
                InterSectset->addElement(current->data);
            }
            current = current->next;
        }
        return InterSectset;
    }
};

    int main() {
        Set<int>* s1 = new Set<int>();
        s1->addElement(1);
        s1->addElement(2);
        s1->addElement(3);
        s1->addElement(4);
        s1->addElement(5);
        cout << s1;
        Set<int>* s2 = new Set<int>();
        s2->addElement(3);
        s2->addElement(4);
        s2->addElement(5);
        s2->addElement(6);
        s2->addElement(7);
        cout << s2;
        Set<int>* s3 = *s1 + s2;
        cout << s3;
        Set<int>* s4 = *s1 - s2;
        cout << s4;
        Set<int>* s5 = *s1 * s2;
        cout << s5;
        return 0;
    }