#include <iostream>
using namespace std;

int binpow (int a, int n) {
    if (n == 0)
        return 1;
    if (n % 2 == 1)
        return binpow (a, n-1) * a;
    else {
        int b = binpow (a, n/2);
        return b * b;
    }
}

long FastPow(int num,int pow){
    if (pow == 0)return 1;
    if(pow==1) return num;
    if(pow&1) return num * FastPow(num*num, pow>>1);
    else return FastPow(num*num, pow>>1);
}


//Быстрое возведение числа num в степень deg
long powerFast(long num, long deg) {
    long result = 1;
    while(deg) {
        if (deg & 1) {
            result *= num;
        }
        deg = deg>>1;
        num *= num;
    }

    return result;
}


int** MatrixMult(int** a,int ** b,int size){
    int ** Matrix=new int*[size];
    int counter;
    for (int i = 0; i < size; ++i) {
        Matrix[i]=new int[size];
        for (int j = 0; j < size; ++j) {
            counter = 0;
            for (int k = 0; k < size; ++k) {
                counter+=a[i][k]*b[k][j];
            }
            Matrix[i][j]=counter;

        }

    }
    return Matrix;
}

int** FastPow(int** matrix, int size,int pow){
    if(pow==1) return matrix;
    int **matrix2 = MatrixMult(matrix, matrix, size);
    if(pow&1) return MatrixMult(matrix, FastPow(matrix2,size, pow >>1), size); //num * FastPow(num*num, pow>>1);
    else return FastPow(matrix2, size, pow>>1);
}



int main() {
    //long a=3;
    long pow=15;

    int** a = new int*[2];
    for (int i = 0; i < 2; ++i) {
        a[i]=new int[2] {3,2};

    }




    int ** ass= FastPow(a,2 ,pow);

    for(int i = 0; i < 2; i++){
        for (int j = 0; j < 2; ++j) {
            cout << ass[i][j]<<' ';
        }
        cout << endl;
    }
    return 0;
}
