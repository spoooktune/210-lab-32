#include <iostream>
#include <deque>
#include <random>
#include "Car.h"

using namespace std;

int main(){
    deque<Car> carQ;
    cout << "Initial Queue: " << endl;
    for (int i = 0; i < 2; i++){
        Car temp;
        carQ.push_back(temp);
        cout << "> ";
        temp.print();
    }
    cout << endl;
    return 0;
}