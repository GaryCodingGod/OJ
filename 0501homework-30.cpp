//Question : Please referenc equestion 29 to create a class Rectangle
#include <iostream>
#include <cmath>
using namespace std;

class Point {
    private:
        float x, y;
    public:
        Point(): x(0), y(0) {}
        Point(float a_x, float a_y): x(a_x), y(a_y) {}

        void printPoint() {
            cout << "(" << x << ", " << y << ")";
        }

        float getX() {
            return x;
        }

        float getY() {
            return y;
        }

        void setX(float a_x) {
                x = a_x;
        }

        void setY(float a_y) {
                y = a_y;
        }

        float getDistance(Point p) {
            float dx = x - p.x;
            float dy = y - p.y;
            return sqrt(dx * dx + dy * dy);
        }
};

class Segment {
    public:
        Point p1, p2;
    public:
        Segment(): p1(0, 0), p2(0, 0) {}
        Segment(Point a_p1, Point a_p2) : p1(a_p1), p2(a_p2) {}

        float getLength() {
            return p1.getDistance(p2);
        }
};

class Shape {
    private:
        Segment seg[10];
        int edgeCount;

    public:
        Shape(): edgeCount(0) {}
        virtual float getArea() = 0;
        Shape(Segment *s, int n) {
            for (int i = 0; i < n - 1; i++) {
                if (s[i].p2.getX() != s[i + 1].p1.getX() && s[i].p2.getY() != s[i + 1].p1.getY()) {
                    throw invalid_argument("Segments cannot form a closed path.");
                }
            }
            if (n < 3 || s[0].p1.getX() != s[n - 1].p2.getX() || s[0].p1.getY() != s[n - 1].p2.getY()) {
                throw invalid_argument("A shape must have at least 3 edges.");
            }
            for (int i = 0; i < n; i++) {
                seg[i] = s[i];
            }
            edgeCount = n;
        }
        float getPerimeter() {
            float perimeter = 0;
            for (int i = 0; i < edgeCount; i++) {
                perimeter += seg[i].getLength();
            }
            return perimeter;
        }
        
        Segment& getSeg(int n) {
            return seg[n];
        }    
};
class Rectangle: public Shape {
    public:
        Rectangle(Segment *s): Shape(s, 4) {}
        float getArea() {
            return getSeg(0).getLength() * getSeg(1).getLength();
        }
};