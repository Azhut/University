#include <iostream>
using namespace std;

int main(){
    int Quantity, Ball,LastBall=0, idx=0;


    cin >> Quantity;
    int* arr = new int[Quantity+1] {0};


    for (int i = 0; i < Quantity; ++i) {
        cin >> Ball;
        if(LastBall>Ball) {
            if (arr[idx] == Ball) {
                idx--;
            } else {
                    cout << "Cheater";
                return 0;
            }

        }
        else {
            Ball--;
            while (LastBall < Ball) {
                arr[++idx] = ++LastBall;
            }
            LastBall++;

        }
    }
    cout << "Not a proof";
}