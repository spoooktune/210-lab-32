#include <iostream>
#include <deque>
#include <random>
#include <array>
#include "Car.h"

using namespace std;
const int PAYS_TOLL = 46, JOIN_Q = 39 + PAYS_TOLL;

int main(){
    srand(time(0));
    // array of deques
    array<deque<Car>, 4> carPlaza;
    
    cout << "Initial Queue: " << endl;
    for (int x = 0; x < 4; x++){
        deque<Car> * carQ = &carPlaza[x];
        cout << "> Lane " << x + 1 << endl;
        for (int i = 0; i < 2; i++){
            Car temp;
            carQ->push_back(temp);
            cout << "   ";
            temp.print();
        }
    }
    cout << endl;
    int r = 0;
    for (int i = 0; i < 20; i++){
        cout << "Period " << i + 1 << endl;
        for (int x = 0; x < 4; x++){
            cout << "> Lane " << x + 1 << endl;
            deque<Car> * carQ = &carPlaza[x];
            r = rand() % 100 + 1;
            if (r <= PAYS_TOLL && !carQ->empty()){
                cout << "   Car paid: ";
                carQ->front().print();
                carQ->pop_front();
            }
            else if (r > PAYS_TOLL && r <= JOIN_Q){
                Car temp;
                cout << "   Car joined lane: ";
                carQ->push_back(temp);
                carQ->back().print();
            }
            else if (r > JOIN_Q && !carQ->empty()){
                int laneC = rand() % 3;
                // if laneC is same as current lane
                while (laneC == x){
                    // get another num for laneC until diff from x
                    laneC = rand() % 3;
                }
                Car temp = carQ->back();
                carPlaza[laneC].push_back(temp);
                carQ->pop_back();
                cout << "   Car moved to Lane " << laneC + 1 << ": ";
                temp.print();
            }
        }
        cout << endl;
        
        cout << "Queue: " << endl;
        for (int x = 0; x < 4; x++){
            deque<Car> carQ = carPlaza[x];
            cout << "> Lane " << x + 1 << endl;
            if (carQ.empty()){
                cout << "   Lane is empty" << endl;
            }
            else{
                for (Car c : carQ){
                    cout << "   ";
                    c.print();
                }
            }
        }
        cout << endl;
    }
    //*/
    return 0;
}