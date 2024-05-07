//Question: Please design a class Point represent a point on plane coordinates.
//Question: Please design a class Segment represent a line segment on plane coordinates.
//Question: Cacluate the distance between two points.
#include <iostream>
#include <cmath> 
using namespace std;

// 定義一個 Point 類來表示二維空間中的點
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

        // 計算當前點到另一點 p 的距離
        float getDistance(Point p) {
            float dx = x - p.x;
            float dy = y - p.y;
            return sqrt(dx * dx + dy * dy); 
        }
};


class Segment { // 定義一個 Segment 類來表示線段
    private:
        Point p1, p2;  

    public:
        Segment(): p1(0, 0), p2(0, 0) {}
        Segment(Point a_p1, Point a_p2) : p1(a_p1), p2(a_p2) {}

        float getLength() {
            return p1.getDistance(p2);  // 計算端點 p1 與 p2 之間的距離
        }
};
