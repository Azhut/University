#include <iostream>
#include <cmath>;
using namespace std;

struct Point{
    double x;
    double y;
};

struct Square{
        bool empty;
        Point coordinate[4];
};


void FillSq(Square A){//это не работает, почему-то ошибка получается при передачи квадрата в функцию

    Point const hd1 = {(A.coordinate[0].x-A.coordinate[2].x) * 0.5,(A.coordinate[0].y-A.coordinate[2].y) * 0.5};
    Point const hd2{ -hd1.y, hd1.x };
    A.coordinate[1]={A.coordinate[2].x + hd1.x + hd2.x,A.coordinate[2].y+ hd1.x + hd2.y};;
    A.coordinate[3]={ A.coordinate[2].x + hd1.x - hd2.x,A.coordinate[2].y + hd1.y - hd2.y};

};

int main() {
    int n;
    cin >> n;
    Square* square= new Square[n];
    for(int i=0; i<n; i++){
        cin >> square[i].coordinate[0].x >> square[i].coordinate[0].y;
        cin >> square[i].coordinate[2].x >> square[i].coordinate[2].y;
    }

    for (int i = 0; i < n; ++i) {
        Point const hd1 = {(square[i].coordinate[0].x-square[i].coordinate[2].x) * 0.5,(square[i].coordinate[0].y-square[i].coordinate[2].y) * 0.5};
        Point const hd2{ -hd1.y, hd1.x };
        square[i].coordinate[1]={square[i].coordinate[2].x + hd1.x + hd2.x,square[i].coordinate[2].y+ hd1.x + hd2.y};;
        square[i].coordinate[3]={ square[i].coordinate[2].x + hd1.x - hd2.x,square[i].coordinate[2].y + hd1.y - hd2.y};
    }



    for(int i=0; i<n; i++){
        cout <<"The "<< i+1 <<' '<< "square coordinate:"<<endl;
        for(int j=0; j<4; j++) {
            cout << j+1 <<" point:" << "(" << square[i].coordinate[j].x << "," << square[i].coordinate[j].y << ")" << endl;
        }
        cout << endl;
    }
    return 0;
}
