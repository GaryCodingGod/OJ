//Question : Please design a class LinkedList to represent a linked list.
//Question : includes the definition of nodes and basic operations such as adding and removing nodes
#include <iostream>
using namespace std;

class LinkedList {
    public:
        class Node {
            public:
                int data; //節點的數據
                Node *next;
                Node(): next(nullptr), data(0) {}
                Node(int d): next(nullptr), data(d) {}
                Node(Node *n): next(n), data(0) {}
                Node(Node *n, int d): next(n), data(d) {}
        };
        LinkedList() {
            head = new Node();
        }
        ~LinkedList() {
            Node *p = head;
            while (p != nullptr) {
                Node *q = p;
                p = p->next;
                delete q;
            }
        }
        bool addFromHead(int d) {
            Node *p = new Node(head->next, d);
            head->next = p;
            return true;
        }
        bool addFromTail(int d) {
            Node *p = head;
            while (p->next != nullptr) {
                p = p->next;
            }
            Node *q = new Node(d);
            p->next = q;
            return true;
        }
        bool removeFromHead() {
            if (head->next == nullptr) {
                return false;
            }
            Node *p = head->next;
            head->next = p->next;
            delete p;
            return true;
        }
        bool removeFromTail() {
            if (head->next == nullptr) {
                return false;
            }
            Node *p = head;
            while (p->next->next != nullptr) {
                p = p->next;
            }
            Node *q = p->next;
            p->next = nullptr;
            delete q;
            return true;
        }
        friend ostream &operator<<(ostream &os, const LinkedList *l) {
            Node *p = l->head->next;
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
            Node *p = head->next;
            while (p != nullptr) {
                size++;
                p = p->next;
            }
            return size;
        }
    protected:
        Node *head;
};