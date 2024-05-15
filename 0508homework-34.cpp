//Question: please design and implement a function that judge which class of object is it.
//Question: The object it passing must be Stack or PriorityQueue。return 1 is Stack, return 2 is PriorityQueue.
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

class PriorityQueue : public Container { //先刪除具有最高級的元素
private:
    vector<int> data;

public:
    void push(int value) override {
        data.push_back(value);
        push_heap(data.begin(), data.end()); //push_heap 函數將一個新元素添加到堆中並重新排列，保持(Stack)堆的性質
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

int main() {
    // 測試 Stack
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    cout << "Stack top: " << s.top() << endl; // 應該輸出 3
    s.pop();
    cout << "Stack top after pop: " << s.top() << endl; // 應該輸出 2

    // 測試 PriorityQueue
    PriorityQueue pq;
    pq.push(3);
    pq.push(1);
    pq.push(4);
    cout << "PriorityQueue top: " << pq.top() << endl; // 應該輸出 4
    pq.pop();
    cout << "PriorityQueue top after pop: " << pq.top() << endl; // 應該輸出 3

    return 0;
}
