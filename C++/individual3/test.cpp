#include<iostream>
#include <string>
#include <fstream>

using namespace std;
const string filenameIn = "G:\\temp\\inp.txt";
const string filenameOut = "G:\\temp\\out.txt";

int main(){
    string s; //переменная для записи строки из файла
    ifstream file(filenameIn);
    int count;//количесвто слов
    int l, Length, i, j, z;
    int mask;//битовая маска
    string PolindromString;
    bool isPalindrome;
    int PolindromLength;
    int saved_mask=-1;
    int max_char=0;
    int max_words=0;
    int cur_words=0;

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
                Word[z++] = s.substr(j + 1, i - j - 1);
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
        /*
        int trashold = 1;
        for (int c = 0; c < count; c++) {
            trashold *= 2;
        }//вычисление степени(2^count)
        вычисляем степень через побитовый сдвиг*/


        for (mask = 1; mask < (1 << count); mask++) {//wbrk для маски(еще не раотает)
            cur_words = 0;
            PolindromString = "";
            for (int b = count - 1; b >= 0; b--) { //строки с 3 словами b должно перебераться в диапозоне от 2 до 0
                // а не от 3 до 1. так идеёт нумирация разрядов и маски и  массива слов

                if (mask & (1 << b)) {//чет похуй стало, написал всё кроме перебора маски
                    PolindromString += Word[b];//составление одной большой строки
                    cur_words +=1;

                }
            }
            PolindromLength = PolindromString.length();//расчет длины получившегося слова

            isPalindrome=true;
            for (int i = 0; i < (PolindromLength / 2); i++) {//отсюда и ниже - проверка на полиндромность
                if (PolindromString[i] != PolindromString[(PolindromLength - 1) - i]) {
                    isPalindrome = false;
                    break;
                }
            }

            if (isPalindrome == true) {
                cout << PolindromString << " is a palindrome" << endl;
                if (max_char < PolindromLength) {
                    max_words = cur_words;
                    max_char = PolindromLength;
                    saved_mask = mask;//сохроняем маску самого длинного из найденых полиндромов
                }

            } else cout << PolindromString << " is not a palindrome" << endl;

        }
        string included[max_words];
        string excluded[count-max_words];
        int i = 0;
        int j = 0;

        for (int b = count - 1; b >= 0; b--) {


            if (saved_mask & (1 << b)) included[i++] = Word[b];
            else excluded[j++] = Word[b];
        }
        ofstream out;          // поток для записи
        out.open(filenameOut); // окрываем файл для записи
        if (out.is_open()) {
            out <<  PolindromString <<  endl;//запись
           /* for(int q=0;q<max_words;q++){
                out << included[q];
            }*/
        }

    }
    file.close();
    return 0;
//на самом деле я рот того ебал, потому что в задании помимо этого есть еще один важный пунктик:
//надо вывести все удаленные слова и их количество, то есть надо создавать новый массив слов, в нем все считать. Я ебал. Я спать.

}


//Я егор
//рогЕ я
//егор Я