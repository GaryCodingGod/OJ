#include <iostream>
#include <cstdlib>

using namespace std;

class Fraction {
private:
    int numerator;
    int denominator;

    // 最大公因數
    static int gcd(int a, int b) {
        while (b != 0) {
            int t = b;
            b = a % b;
            a = t;
        }
        return a;
    }

    // 最小公倍數
    static int lcm(int a, int b) {
        return a / gcd(a, b) * b; // 防止溢出
    }

public:
    Fraction() : numerator(0), denominator(1) {}

    Fraction(int n, int d) : numerator(n), denominator(d) {
        if (d == 0) {
            exit(1); // 分母若為0就退出程式
        }
    }

    int getNumerator() const {
        return numerator;
    }

    int getDenominator() const {
        return denominator;
    }

    void setNumerator(int n) {
        numerator = n;
    }

    void setDenominator(int d) {
        if (d == 0) {
      
            exit(1);
        }
        denominator = d;
    }

    void display() const {
        if (denominator == 1) {
            cout << numerator;
        } else {
            cout << numerator << '/' << denominator;
        }
    }

    // 加法運算符重載
    Fraction operator+(const Fraction& other) const {
        int lcmDenominator = lcm(denominator, other.denominator);
        int newNumerator = numerator * (lcmDenominator / denominator) +
                           other.numerator * (lcmDenominator / other.denominator);
        int commonDivisor = gcd(newNumerator, lcmDenominator);
        return Fraction(newNumerator / commonDivisor, lcmDenominator / commonDivisor);
    }

    // 減法運算符重載
    Fraction operator-(const Fraction& other) const {
        int lcmDenominator = lcm(denominator, other.denominator);
        int newNumerator = numerator * (lcmDenominator / denominator) -
                           other.numerator * (lcmDenominator / other.denominator);
        int commonDivisor = gcd(newNumerator, lcmDenominator);
        return Fraction(newNumerator / commonDivisor, lcmDenominator / commonDivisor);
    }

    // 乘法運算符重載
    Fraction operator*(const Fraction& other) const {
        int newNumerator = numerator * other.numerator;
        int newDenominator = denominator * other.denominator;
        int commonDivisor = gcd(newNumerator, newDenominator);
        return Fraction(newNumerator / commonDivisor, newDenominator / commonDivisor);
    }

    // 除法運算符重載
    Fraction operator/(const Fraction& other) const {
        int newNumerator = numerator * other.denominator;
        int newDenominator = denominator * other.numerator;
        int commonDivisor = gcd(newNumerator, newDenominator);
        return Fraction(newNumerator / commonDivisor, newDenominator / commonDivisor);
    }

    // 賦值運算符重載
    Fraction& operator=(const Fraction& other) {
        if (this != &other) { // 防止自我賦值
            numerator = other.numerator;
            denominator = other.denominator;
        }
        return *this;
    }

    // 邏輯非運算符重載 (取倒數)
    Fraction operator!() const {
        return Fraction(denominator, numerator);
    }

    // 插入運算符重載 (用於輸出)
    friend ostream& operator<<(ostream& out, const Fraction& f) {
        if (f.denominator == 1) {
            out << f.numerator;
        } else {
            out << f.numerator << '/' << f.denominator;
        }
        return out;
    }
};

int main() {
    Fraction f1(1, 2), f2(1, 3), f3;
    f3 = f1 + f2;
    cout << "f1 + f2 = " << f3 << endl;
    f3 = f1 - f2;
    cout << "f1 - f2 = " << f3 << endl;

    
    return 0; 
}