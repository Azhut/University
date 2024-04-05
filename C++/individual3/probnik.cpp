#include<iostream>
#include <string>
#include <fstream>
#include <string.h>
using namespace std;
const string filenameIn = "C:\\Users\\Egor\\Desktop\\coding\\study\\c++\\HomeWork\\stringi\\pol.txt";
const string filenameOut = "C:\\Users\\Egor\\Desktop\\coding\\study\\c++\\HomeWork\\stringi\\out.txt";

int main(){
    string s; //переменная для записи строки из файла
    ifstream file(filenameIn);
    int count;//количесвто слов
    int l, Length, i, j, z;
    int mask;//битовая маска
    string PolindromString;
    bool isPalindrome = true;
    int PolindromLength;


    while(getline(file, s)) {
        Length = s.length();
        l = 0;
        count = 0;

        while (l < int(Length)) {
            if (s[l] != ' ' && ((l + 1 == Length) || s[l + 1] == ' '))
                count++;
            l++;
        }
        cout << count << endl;
        string Word[count];


        j = -1;
        z = 0;

        do {
            i = s.find(" ", j + 1);
            if (i < 0) break;
            if (i - j > 1) {
                Word[z++] = s.substr(j + 1, i - j-1);
            }
            j = i;
        } while (true);
        if (s.length() - j > 1) {
            Word[z] = s.substr(j + 1, s.length() - j);
        }

        for (int f = 0; f < count; f++) {
            cout << Word[f] << endl;
        }
//////////////////////////////////////////////////

            int trashold = 1;
            for (int c = 0; c < count; c++) {
                trashold *= 2;
            }//вычисление степени(2^count)

        for (mask = 1; mask < trashold; mask++ ) {//wbrk для маски(еще не раотает)

            for (int b = count; b > 0; b--) { //Хотел начинать с последнего слова, но
            // не получится, потому что надо писать доп.фунцию по реверсирвоанию слова, иначе никак

                //if (mask & (1 << b)) {//чет похуй стало, написал всё кроме перебора маски
                PolindromString += Word[b - 1];//составление одной большой строки
                //}
            }
            PolindromLength = PolindromString.length();//расчет длины получившегося слова


            for (int i = 0; i < (PolindromLength / 2); i++) {//отсюда и ниже - проверка на полиндромность
                if (PolindromString[i] != PolindromString[(PolindromLength - 1) - i])
                    isPalindrome = false;
            }

            if (isPalindrome == true)
                cout << PolindromString << " is a palindrome" << endl;

            else
                cout << PolindromString << " is not a palindrome" << endl;


            ofstream out;          // поток для записи
            out.open(filenameOut); // окрываем файл для записи
            if (out.is_open())
            {
                out << PolindromString  << endl;//запись
            }
        }

    }
    file.close();
    return 0;
//на самом деле я рот того ебал, потому что в задании помимо этого есть еще один важный пунктик:
//надо вывести все удаленные слова и их количество, то есть надо создавать новый массив слов, в нем все считать. Я ебал. Я спать.

}