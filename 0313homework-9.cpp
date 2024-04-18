#include <iostream>
#include <cmath>
using namespace std;

class Toll{
    float a,d;

    public:

    Toll(float distance){
        d = distance;

        if(d > 200){
       a = (d-200)*1.2*0.75+200*1.2;
    }else{
        a = d*1.2;
    }
    cout << round(a) << endl;
    }
};

int main(){
    float d , a;    
    cin >> d ;
    Toll Tolls(d);
    return 0;
}

//另解
/*#include <iostream>
#include <cmath>x
  using namespace std;

  class toll{
    int d;
    float calculate(int d){
        if (d <= 200)
            return d*1.2;
        else
            return 200*1.2 +(d-200)* 0.9;
    }
    public:
        toll(int a){
            d = a;
            cout << round(calculate(d)) << endl;
        }
  };
  int main(){
    int a;
    cin >> a;
    toll Toll(a);
    return 0 ;
  }*/