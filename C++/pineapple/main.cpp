#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    double Width, High;
    int n;
    double Step;
    double V, Vlast = 0.;
    cout << fixed << setprecision(12);

    cin >> Width >> High >> n;
    Step = High/n;

    for(double  x = Step; x <= High; x += Step){
        V = (M_PI * Width * Width)/(6. * High * High)*(3*High*x*x - 2. * x * x * x);
        cout << V - Vlast<< endl;
        Vlast = V;
    }
}
