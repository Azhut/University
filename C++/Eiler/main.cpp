#include <iostream>
using namespace std;

int phi (int n) {
    int result = n;
    for (int i=2; i*i<=n; ++i) {
        if (n % i == 0) {
            while (n % i == 0) n /= i;
            result -= result / i;
        }
    }
    if (n > 1)
        result -= result / n;
    return result;
}

int main() {
    int SIZE;
    cin >> SIZE;

    int CurNum;
    int LastNum;
    int input;

    int ChainStart=0;
    int MaxLen=0;
    int MaxPos=0;

    for (int i = 0; i < SIZE; ++i) {
        LastNum=CurNum;
        cin >> input;
        CurNum= phi(input);
        if(CurNum>LastNum)continue;
        if(MaxLen < i-ChainStart) {MaxLen = i - ChainStart; MaxPos = ChainStart;}
        ChainStart=i;
        //if(SIZE-i==1)MaxLen = SIZE - ChainStart;
    }
    if(ChainStart!=SIZE-1)        if(MaxLen < SIZE - ChainStart) {MaxLen = SIZE- ChainStart; MaxPos = ChainStart;}
    cout << "The start of the chain: "<< MaxPos << endl
         << "The length of the chain: "<< MaxLen << endl;
}

