#include <iostream>
#include <cmath>
using namespace std;

class Point {
public:
    double x, y;
    Point(double _x, double _y);
    
    double getX() { return x; }
    double getY() { return y; }
};

class Segment {//
public:
    Point p1, p2;
    Segment(Point _p1, Point _p2);
    
    Point getEnd(int n) {
        if(n == 1) return p1;
        else return p2;
    }
    
    double length() {
        return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
    }
};

class Path {
private:
    Segment* segments;
    int segmentCount;
    
public:
    Path(Segment sgmnts[], int count) {
        if(isValidPath()) {
            cout << calculateLength() << endl;
        } else {
            cout << "-1" << endl;
        }
    };
    
    ~Path() {
        // If using dynamic allocation, we would delete segments here
    }
    
    double calculateLength() {
        double totalLength = 0.0;
        for(int i = 0; i < segmentCount; ++i) {
            totalLength += segments[i].length();
        }
        return totalLength;
    }

    bool isValidPath() {
        for(int i = 0; i < segmentCount - 1; ++i) {
            if(!(segments[i].getEnd(2).getX() == segments[i + 1].getEnd(1).getX() && 
                 segments[i].getEnd(2).getY() == segments[i + 1].getEnd(1).getY())) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    // Create some points
    Point p1(0, 0), p2(1, 1), p3(2, 2), p4(3, 3);
    // Create segments from those points
    Segment s1(p1, p2), s2(p2, p3), s3(p3, p4);
    // Create an array of segments
    Segment segments[] = {s1, s2, s3};
    // Create the path
    Path path(segments, 3); // Pass the array and the count of segments
    return 0;
}
