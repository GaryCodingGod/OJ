#include <iostream>

using namespace std;

class Gate {
public:
    Gate* input[2] = {nullptr, nullptr};
    virtual bool output() = 0; //因為Gate是屬於抽象的，具體實現由子類別完成
    void setValue(Gate* gate, int pin);//pin是引腳，類似接受器的概念
    void setValue(bool val, int pin);
};

class TRUE : public Gate {
public:
    virtual bool output() { return true; }
    void setValue(Gate*, int) {}
    void setValue(bool, int) {}
};

class FALSE : public Gate {
public:
    virtual bool output() { return false; }
    void setValue(Gate*, int) {}
    void setValue(bool, int) {}
};

TRUE t; //因為true false都是屬於無參建構函數 所可以以直接提供一個默認的無參建構函數
FALSE f;

void Gate::setValue(bool val, int pin) {
    if (val) {
        input[pin] = static_cast<Gate*>(&t); //現在True繼承的是Gate所以我要將子類指標轉換為父類指標
    } else {                                 // 將 TRUE* 類型的指標轉換為 Gate* 類型的指標，因為 input[pin] 需要的是一個 Gate* 類型的指標。
        input[pin] = static_cast<Gate*>(&f);
    }
}

void Gate::setValue(Gate* gate, int pin) {
    input[pin] = gate;
}

class NOT : public Gate { //NOt輸入1就會輸出0，所以只會有一個pin引腳(接收器)
public:
    virtual bool output() {
        bool inputValue = input[0]->output();
        bool result = !inputValue;
        return result;
    }
};


class NAND : public Gate { //Nand=And+Not先做And運算再取反
public:
    virtual bool output() {
        bool input1 = input[0]->output();
        bool input2 = input[1]->output();
        
        bool andResult = input1 && input2;
        bool result = !andResult; 
        
        return result;
    }
};

class NOR : public Gate { //Nor=Or+Not先做or運算再取反
public:
    virtual bool output() {
        bool input1 = input[0]->output();
        bool input2 = input[1]->output();
    
        bool orResult = input1 || input2;
        bool result = !orResult;
        return result;
    }
};


class AND : public Gate { //And=Nand+Not
private:
    NAND nandGate;
    NOT notGate;
public:
    virtual bool output() {
        nandGate.setValue(input[0], 0);
        nandGate.setValue(input[1], 1);
        notGate.setValue(&nandGate, 0);
        return notGate.output();
    }
};

class OR : public Gate {
private:
    NOR norGate;
    NOT notGate;
public:
    virtual bool output() {
        norGate.setValue(input[0], 0);
        norGate.setValue(input[1], 1);
        notGate.setValue(&norGate, 0);// 設置 NOT 閘的輸入為 NOR 閘的輸出
        return notGate.output();
    }
};

class XOR : public Gate {
private:
    AND and1, and2;
    OR orGate;
    NOT not1, not2;
public:
    virtual bool output() {
        not1.setValue(input[0], 0);
        not2.setValue(input[1], 0);
        
        and1.setValue(input[0], 0);
        and1.setValue(&not2, 1);
        
        and2.setValue(&not1, 0);
        and2.setValue(input[1], 1);
        
        orGate.setValue(&and1, 0);
        orGate.setValue(&and2, 1);
        
        return orGate.output();
    }
};