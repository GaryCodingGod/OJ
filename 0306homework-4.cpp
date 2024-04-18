#include <iostream>
using namespace std;

class Journey{
private:
    double distance, time;
public:
    Journey(double D, double T){
        distance = D;
        time = T;
    }

    double Velocity1(){
        return distance/time;//
    }
};

int main(){
    double distance, time, velocity;
    cin >> distance >> time;
    Journey journey(distance, time);
    velocity = journey.Velocity1();
    
    cout << velocity << endl;
    return 0;
}
