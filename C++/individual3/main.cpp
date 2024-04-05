#include<iostream>
#include <fstream>
#include <string>
using namespace std;

const string filename = "C:\\Users\\Egor\\Desktop\\coding\\study\\c++\\HomeWork\\stringi\\pol.txt";

int main() {
    string s; // переменная для записи строки из файла
    ifstream file(filename);
    int count = 0; // количество слов в строке
    int Length, i, j, z;
    string PolindromString;
    bool isPalindrome = true;
    int PolindromLength;

    while (getline(file, s)) {
        Length = s.length(); // длина строки

        // Подсчет количества слов в строке
        j = -1;
        z = 0;
        do {
            i = s.find(" ", j + 1);
            if (i < 0) break;
            if (i - j > 1) {
                count++;
            }
            j = i;
        } while (true);

        if (s.length() - j > 1) {
            count++;
        }

        cout << count << endl;

        // Создание массива слов
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

        // Вывод слов для проверки
        for (int f = 0; f < count; f++) {
            cout << Word[f] << endl;
        }

        // Поиск и проверка палиндромов
        int trashold = 1;
        for (int c = 0; c < count; c++) {
            trashold *= 2;
        }

        for (int mask = 1; mask < trashold; mask++) {
            PolindromString = "";
            for (int b = count; b > 0; b--) {
                if (mask & (1 << (b-1))) {
                    PolindromString += Word[b - 1];
                }
            }
            PolindromLength = PolindromString.length();
            isPalindrome = true;

            // Проверка является ли полученная строка палиндромом
            for (int i = 0; i < (PolindromLength / 2); i++) {
                if (PolindromString[i] != PolindromString[(PolindromLength - 1) - i]) {
                    isPalindrome = false;
                    break; // если найден непалиндромный символ, нет смысла продолжать проверку
                }
            }

            // Вывод результата проверки
            if (isPalindrome == true) {
                cout << PolindromString << " is a palindrome" << endl;
            } else {
                cout << PolindromString << " is not a palindrome" << endl;
            }
        }
    }
    file.close(); // закрытие файла
    return 0;
}
