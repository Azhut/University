#include <iostream>
#include <cmath>
using namespace std;
struct Vector{
    double x;
    double y;
    double z;
    Vector() {
        cin >> x >> y >> z;
    }
    Vector(double a,double b,double c) {
        x = a;
        y = b;
        z = c;
    }

    Vector operator-(const Vector& B){//разность
        return Vector(x-B.x, y - B.y, z - B.z);
    }

    Vector operator-(){//обратный вектор
        return Vector(-x, -y, -z);
    }

    double operator*(const Vector &B){//скалярное произведение
        return (x * B.x + y * B.y + z * B.z);
    };

    Vector operator^(const Vector& B){//векторное произведение
        return Vector(y * B.z - B.y * z, x * B.z - B.x * z, x * B.y - B.x * y);
    }

    bool isZero() {//равенство
        return (x == 0) && (y == 0) && (z == 0);
    }
    bool operator||(Vector &B){//коллинеарность
        double temp;
        return (B.x * y * z == (temp = x * B.y * z)) && (temp == x * y * B.z);
    }

    double dist2(){
        return (x*x + y*y + z*z);
    }
    Vector  normalize(){
        double coef = 1/sqrt(dist2());
        return Vector(x*coef, y*coef, z*coef);
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