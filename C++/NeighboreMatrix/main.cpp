#include <iostream>
#include <fstream>
#include <list>

using namespace std;

void PrintList(list<int> list) {
    while (!list.empty()) {
        cout << list.back() << ' ';
        list.pop_back();
    }
}

int main() {
    int size;
    ifstream fin("C:\\Users\\Egor\\C++\\NeighboreMatrix\\Matrix.txt");
    fin >> size;
    int** Matrix = new int* [size];

    for (int i = 0; i < size; i++) {
        Matrix[i] = new int[size];
        for (int j = 0; j < size; j++) {
            fin >> Matrix[i][j];
            cout << Matrix[i][j];
            cout << ' ';
        }
        cout << endl;
    }
    fin.close();



    for (int i = 0; i < size; i++) {
        list<int> ClosestPick;
        for (int j = 0; j < size; j++) {
            if (Matrix[i][j] == 1) {
                ClosestPick.push_front(j+1);
            }
        }
        cout << i + 1 << ": ";
        PrintList(ClosestPick);
        cout << endl;

    }

    for(int i = 0;i < size; i++ ) delete[] Matrix[i];


    return 0;
}

