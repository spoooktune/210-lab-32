#include <iostream>
#include <deque>
#include <random>
#include "Car.h"

using namespace std;
const int PAYS_TOLL = 55;

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
    int r = 0;
    while (!carQ.empty()){
        r = rand() % 100 + 1;
        if (r <= PAYS_TOLL){
            cout << "Car paid: ";
            carQ.front().print();
            carQ.pop_front();
        }
        else if (r > PAYS_TOLL){
            Car temp;
            cout << "Car joined lane: ";
            temp.print();
            carQ.push_back(temp);
        }
        cout << "Queue: " << endl;
        for (Car c : carQ){
            cout << "> ";
            c.print();
        }
    }
    return 0;
}