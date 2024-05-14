//Question: Reference 34 to implement a function that judges which class of object it is.
#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>

using namespace std;

class Container {
public:
    virtual void push(int) = 0;//插入元素
    virtual void pop() = 0; // 刪除頂部元素
    virtual int top() const = 0; // 獲取頂部元素
    virtual bool empty() const = 0;
    virtual ~Container() {}
};

class Stack : public Container { //實現先進後出
private:
    vector<int> data;

public:
    void push(int value) override {
        data.push_back(value);
    }

    void pop() override {
        if (empty()) {
            throw out_of_range("Stack is empty");
        }
        data.pop_back();
    }

    int top() const override {
        if (empty()) {
            throw out_of_range("Stack is empty");
        }
        return data.back();
    }

    bool empty() const override {
        return data.empty();
    }
};

class PriorityQueue : public Container { 
private:
    vector<int> data;

public:
    void push(int value) override {
        data.push_back(value);
        push_heap(data.begin(), data.end()); 
    }

    void pop() override {
        if (empty()) {
            throw out_of_range("PriorityQueue is empty");
        }
        pop_heap(data.begin(), data.end());
        data.pop_back();
    }

    int top() const override {
        if (empty()) {
            throw out_of_range("PriorityQueue is empty");
        }
        return data.front();
    }

    bool empty() const override {
        return data.empty();
    }
};
    int judge(Container *c) {
        if (dynamic_cast<Stack*>(c) != nullptr) { //dynamic_cast運算符用於將父類指針轉換為子類指針
            return 1;                             //轉換失敗返回nullptr
        }
        else if (dynamic_cast<PriorityQueue*>(c) != nullptr) {
            return 2;
        }
     return 0;
}

int main() {
    // 測試 Stack
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    cout << "Stack top: " << s.top() << endl; 
    s.pop();
    cout << "Stack top after pop: " << s.top() << endl; 

    // 測試 PriorityQueue
    PriorityQueue pq;
    pq.push(3);
    pq.push(1);
    pq.push(4);
    cout << "PriorityQueue top: " << pq.top() << endl; 
    pq.pop();
    cout << "PriorityQueue top after pop: " << pq.top() << endl; 

    return 0;
}
