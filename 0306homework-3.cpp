#include <iostream>
#include <cmath>
using namespace std;

class Triangle{
    public:
        double x1,y1,x2,y2,x3,y3;
        void Setvalue(double i, double j, double k, double l, double m, double n){
            x1 = i;
            y1 = j;
            x2 = k;
            y2 = l;
            x3 = m;
            y3 = n;
        }
        void perimeter(){
            double disa = sqrt(pow((x1-x2),2)+pow((y1-y2),2));
            double disb = sqrt(pow((x1-x3),2)+pow((y1-y3),2));
            double disc = sqrt(pow((x2-x3),2)+pow((y2-y3),2));
            double perimeter = disa + disb + disc;
            cout << perimeter << endl;
        }
};
int main(){
    Triangle triangle;
    double x1,y1,x2,y2,x3,y3;
    int a;
    cin >> a;
    for(int i = 0 ; i < a ; i++){
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
        triangle.Setvalue(x1,y1,x2,y2,x3,y3);
        triangle.perimeter();
    }
    return 0;
}//