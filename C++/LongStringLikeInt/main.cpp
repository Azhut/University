#include <iostream>
using namespace std;
#include <string>
#include <fstream>

const string filenameIn = "C:\\Users\\Egor\\C++\\LongStringLikeInt\\inp.txt";
const string filenameOut = "C:\\Users\\Egor\\C++\\LongStringLikeInt\\out.txt";



int main() {
    ofstream out;          // поток для записи
    out.open(filenameOut);//нужно
    ifstream file(filenameIn);
    string a, b, result;




    char Minus='-';
    getline(file, a);
    getline(file, b);
    bool SwapChecking=false;

    int LengthA = a.length(), LenghtB = b.length();

    if (LenghtB > LengthA) {

        result = b;
        int Difference = LenghtB - LengthA;
        for (int i=0; i < Difference; i++) {
            a = '0' + a;
        };

    } else if (LenghtB < LengthA) {
        result = a;
        int Difference = LengthA - LenghtB;
        for (int i(0); i < Difference; i++)
        {
            b = '0' + b;
        };
    } else { result = a; };




    int ResultLength = result.length();
    bool bFlag = false;
    for (int i = ResultLength; i >= 0; i--) {
        result[i] = a[i] + b[i] - 48;
        if (bFlag) { result[i]++; };
        if (result[i] >= 58) {
            result[i] -= 10;
            result[i - 1] = result[i - 1] + 1;
            bFlag = true;
        } else { bFlag = false; }

    }


    ofstream l;          // поток для записи
    l.open(filenameOut, ios::app); // окрытие файла для записи
    if (l.is_open()) {
        l << a<< "+"<< b << "=" << result<<endl;
    }
    file.close();


    cout << a<< "+"<< b << "=" << result<<endl;

    if (a<b) {
        swap(a, b);
        SwapChecking=true;
    }

     ResultLength = result.length();
     bFlag = false;
    for (int i = ResultLength - 1; i >= 0; i--) {
        result[i] = a[i] - b[i];
        if (bFlag) { result[i]--; };
        if (result[i] < 0) {
            result[i] += 58;

            if(result[i-1]==48) result[i-1]+=9;

            result[i - 1] = result[i - 1] - 1;
            bFlag = true;
        }
            else {
            bFlag = false;
            result[i]+=48;
            }

    }
    string NewResult="";
    if (SwapChecking) {
        for (int i = 0; i < result.length() ; i++) {
            if(result[i]!=48){
                for (int j = i; j <  result.length()-i+1; ++j) {

                    NewResult+=result[j];
                }
            }
        }
        cout << b<< "-"<< a << "=" << Minus <<NewResult<<endl;
    }
    else cout << a<< "-"<< b << "=" << result<<endl;

   ofstream in;          // поток для записи
    in.open(filenameOut, ios::app); // окрытие файла для записи
    if (in.is_open()) {
        if (SwapChecking) {in << b<< "-"<< a << "=" << Minus <<NewResult<<endl;}
        else in << a<< "-"<< b << "=" << result<<endl;
    }
file.close();
}




