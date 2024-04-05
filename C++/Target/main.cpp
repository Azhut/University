
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;


double distance(int vx,int vy,int vxt,int vyt) {

    if(vx*vxt+vy*vyt>0){
        if(vx*(vx-vxt)+vy*(vy-vyt)>0){
            return ((vxt*vy-vyt*vx)/(sqrt(vx * vx + vy * vy)));
        }else return sqrt((vxt-vx)*(vxt-vx)+(vyt-vy)*(vyt-vy));

    } else return sqrt(vxt*vxt+vyt*vyt);

}


int main() {
    int n;
    int last_y,last_x, now_y,now_x;
    int xt,yt;
    int first_x, first_y;
    int vx,vy;
    int vxt,vyt;
    bool bFlag=false;
    double MIN=4001;

    cin >> xt >> yt >>n;
    cin >> last_x >> last_y;
    first_x=last_x;
    first_y=last_y;

    for(int i=1;i<n;i++) {
        cin >> now_x >> now_y;
        vx = now_x - last_x;
        vy = now_y - last_y;
        vxt = xt - last_x;
        vyt = yt - last_y;
        if (vxt * vy - vx * vyt > 0) {
            bFlag = true;
            MIN = min(MIN, distance(vx,vy,vxt,vyt));
        }
        last_x=now_x;
        last_y=now_y;
    }
    vx = first_x - last_x;
    vy = first_y - last_y;
    vxt = xt - last_x;
    vyt = yt - last_y;
    if (vxt * vy - vx * vyt > 0) {
        bFlag = true;
        MIN = min(MIN, distance(vx,vy,vxt,vyt));
    }
    cout << fixed << setprecision(3);
    if(bFlag==true){
        cout << endl << 2*MIN << endl;
    } else cout << 0 << endl;

    return 0;
}
