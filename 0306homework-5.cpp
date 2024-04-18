#include <iostream>
using namespace std;

class Overlay{
    public:
    int x1,x2,y1,y2;
    void SetValue(int a , int b, int c, int d){
        x1 = a;
        y1 = b;
        x2 = c;
        y2 = d;
    }
    void judge(){
        if(x2 <= y1 || y2 <= x1)
        cout << "no overlay" << endl;
        else
        cout << "overlay" << endl;//
    }
};
int main(){
    Overlay overlay;
    int X1,X2,Y1,Y2;
    cin >> X1 >> Y1;
    cin >> X2 >> Y2;

    if(X1 > Y1){
        int temp =X1;
            X1 = Y1;
            Y1 = temp;
    }
    if(X2 > Y2){
        int temp = X2;
            X2 = Y2;
            Y2 = temp;
    }
    overlay.SetValue(X1,X2,Y1,Y2);
    overlay.judge();

    return 0;
}