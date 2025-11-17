#include <iostream>
#include <deque>
#include <random>
#include <array>
#include "Car.h"

using namespace std;
const int PAYS_TOLL = 55;

int main(){
    srand(time(0));
    // array of deques
    array<deque<Car>, 4> carPlaza;
    
    cout << "Initial Queue: " << endl;
    for (int x = 0; x < 4; x++){
        deque<Car> carQ = carPlaza[x];
        cout << "> Lane " << x + 1 << endl;
        for (int i = 0; i < 2; i++){
            Car temp;
            carQ.push_back(temp);
            cout << "   ";
            temp.print();
        }
    }
    cout << endl;
    /*
    int r = 0;
    int numPeriods = 0;
    while (!carQ.empty()){
        numPeriods++;
        cout << "Period " << numPeriods << endl;
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
        if (carQ.empty()){
            cout << "> Queue is empty" << endl;
        }
        else{
            for (Car c : carQ){
                cout << "> ";
                c.print();
            }
        }
        cout << endl;
    }*/
    return 0;
}