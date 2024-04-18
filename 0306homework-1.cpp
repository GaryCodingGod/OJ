#include <iostream>
using namespace std;

class Point{
    public:
    Point(){};
    float x,y;

    Point(float x1,float y1){//
        x = x1;
        y = y1;
    }

};

int main(){
    int N;
    cin >> N;
    Point points[N];
    for(int i = 0 ; i < N; i++){
        float x,y;
        cin >> x >> y;
        points[i] = Point(x,y);
    }
    for(int i = 0 ; i < N; i++){
        cout << "(" << points[i].x <<", "<< points[i].y << ")" << endl; 
    }
    return 0;
}