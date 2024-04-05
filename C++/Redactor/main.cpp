#include<iostream>
#include <string>
#include <fstream>

using namespace std;
const string filenameIn = "C:\\Users\\Egor\\C++\\Redactor\\inp.txt";
const string filenameOut = "C:\\Users\\Egor\\C++\\Redactor\\out.txt";




int main() {
    ofstream out;          // поток для записи
    out.open(filenameOut, ios::trunc);//нужно
    out.close();
    string s; //переменная для записи строки из файла
    ifstream file(filenameIn);
    out.open(filenameOut, ios::app); // окрытие файла для записи

    int Size;
    cin >> Size;

    string NowString="";
    getline(file, NowString);
    int CounterOfSeparations =0;
    int LastSpace=0;
    int ToAdd;
    int ExtraSpaces, CommonSpaces;
    string Answer;
    int NotExtra;


while(true) {
    while (NowString.length() < Size) {
        if(getline(file, s)) {
            NowString += " ";
            NowString += s;
        } else {
            goto exit;
        }
    }
    for (int i = 0; i < Size; ++i) {
        if (NowString[i] == ' ') {
            CounterOfSeparations++;
            LastSpace = i;
        }
    }

    cout << CounterOfSeparations << ' ' << LastSpace << endl;

    ToAdd = Size - LastSpace;
    CommonSpaces = ToAdd / CounterOfSeparations;
    ExtraSpaces = ToAdd % CounterOfSeparations;
    Answer = NowString.substr(0, LastSpace);
    NotExtra = CounterOfSeparations - ExtraSpaces;

    for (int i = LastSpace - 1; i > 0; --i) {
        if (Answer[i] == ' ') {
            if (NotExtra > 0) {
                NotExtra--;
                Answer.insert(i, string(CommonSpaces, ' '));
            } else {
                Answer.insert(i, string(CommonSpaces + 1, ' '));
            }
        }
    }


    if (out.is_open()) {

        out << Answer << '\n';
    }
    NowString = NowString.substr(LastSpace + 1, NowString.length() - LastSpace);
    CounterOfSeparations=0;

}

exit:
    out << NowString;
    out.close();
    file.close();
    return 0;
}