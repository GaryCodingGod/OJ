#include <iostream>


using namespace std;

//
class Point{  
  public:
   Point(float xVal, float yVal){

    x = xVal;
    y = yVal;

   }

    float getX(){
        return x;
    }

    float getY(){
        return y;
    }


    float x,y;
};




int main() {
    int N;
    cin >> N;
    float x, y;
    for (int i = 0; i < N; i++) {
        cin >> x >> y;
        Point p(x, y);
        cout << "(" << p.getX() << ", " << p.getY() << ")" << endl;
    }

    return 0;
}

