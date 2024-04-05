////конспект лекции Вахрушева, среда 14.12.22
#include <iostream>
#define  ll long long

using namespace std;
struct Point{
    ll x;
    ll y;
    ll z;
    Point(ll a,ll b,ll c) {
        x = a;
        y = b;
        z = c;
    }
    Point operator-(const Point& B){
        return Point(x-B.x, y - B.y, z - B.z);
    }

    ll ScalarProduct(const Point &B){
        return (x * B.x, y * B.y, z * B.z);
    };

    Point operator*(const Point& second){
        return Point(y * second.z - z * second.y, -z * second.y - x * second.z, x * second.y - y * second.x);
    }
};

struct Plane{
    ll A, B, C, D;
    Plane(const Point& n, const Point& o){
        A = n.x, B = n.y; C= n.z;
        D = -A * o.x - B * o.y - C * o.z;
    }
    Plane(Point& a,Point& b,Point& c){

        Point ba = b-a;
        Point n = ba * (c - a);
        this->A = n.x;
        this->B = n.y;
        this->C = n.z;
        this-> D = -n.x * c.x - n.y * c.y - n.z * c.z;
        /////Дед написал this, потому что у него не А большое в ll, поэтому него не работало просто а;
        ////У него а малое
    }
};


int main() {
    Vector A ;
    Vector B ;
    Vector C ;
    Vector D ;

    Vector AB = B - A;
    Vector CD = D - C;
    Vector N = AB^CD;// перпендикуляр к прямым

    if(N.isZero()){//проверка на параллельность
        cout << "Invalid" << endl;
        return 0;
    }

    Vector BC = C - B;
    if((N * BC) || (AB * CD)){//проверка на не пересечение или не перпендикулярность
        cout << "Invalid" << endl;
        return 0;
    }

    Vector DA = A - D;
    Vector N1 = (N^AB).normalize();//перпендикуляр к прямой AB, лежащий в плоскости (ABCD)
    Vector N2 = (N^CD).normalize();
    double dist_C_AB = N1*BC;
    double dist_D_AB = -(N1*DA);
    double dist_A_CD = N2*DA;
    double  dist_B_CD = -(N2*BC);
    if( !( ( dist_A_CD*dist_B_CD>=0 && abs(dist_A_CD)>abs(dist_B_CD) )
           && ( dist_C_AB*dist_D_AB>=0 && abs(dist_D_AB)>abs(dist_C_AB) ) ) ){//проверка на не возможность пролёта по всем точкам и пролёт не в том порядке
        cout << "Invalid" << endl;
        return 0;
    }

    cout << "Valid" << endl;
    return 0;
}
////условия решения задачи:AB перпедик-но CD
////AB компланарно CD; (AB*CD)AC==0
////сначала AB потом CD
////проверить не находятся ли правее(я хз, так Вахрушев сказал)))
////