#include <iostream>
#include <cmath>
using namespace std;

class Segment {
    public:
        double a,b,c,d;
        void SetValue(double x1,double y1, double x2, double y2){
            a = x1;
            b = y1;
            c = x2;
            d = y2;
        }
        void distance(){
           double disval=sqrt( pow((a - c), 2) + pow((b - d),2));
            cout << disval << endl;
        }
};
int main() {//
    int n;
    cin >> n;
    double x1,x2,y1,y2;
    Segment Seg;
    for(int i = 0; i < n; i++){
        cin >> x1 >> y1 >> x2 >> y2;
        Seg.SetValue(x1,y1,x2,y2);
        Seg.distance();
    }
  return 0;
}
