#include<iostream>
#include <string>
#include <fstream>

using namespace std;

const string filenameIn = "C:\\Users\\Egor\\C++\\Polindrom\\inp.txt";
const string filenameOut = "C:\\Users\\Egor\\C++\\Polindrom\\out.txt"; // Измените путь к выходному файлу по вашему выбору

int main() {
    string s; // Переменная для записи строки из файла
    ifstream file(filenameIn);
    ofstream out; // Поток для записи
    out.open(filenameOut, ios::trunc); // Открываем файл для записи (если файл существует, его содержимое будет удалено)

    int count; // Количество слов
    int saved_mask = -1; // Сохраненная маска самого длинного найденного палиндрома
    int max_char = 0; // Длина самого длинного найденного палиндрома
    int max_words = 0; // Количество слов в самом длинном найденном палиндроме
    int cur_words = 0; // Текущее количество слов

    // Обработка каждой строки из файла
    while (getline(file, s)) {
        int Length = s.length();
        count = 0;

        // Подсчет количества слов в строке
        for (int l = 0; l < Length; l++) {
            if (s[l] != ' ' && ((l + 1 == Length) || s[l + 1] == ' '))
                count++;
        }

        string Word[count];

        // Получение слов из строки
        int j = -1;
        int z = 0;
        do {
            int i = s.find(" ", j + 1);
            if (i < 0) break;
            if (i - j > 1) {
                Word[z++] = s.substr(j + 1, i - j - 1);
            }
            j = i;
        } while (true);
        if (s.length() - j > 1) {
            Word[z] = s.substr(j + 1, s.length() - j);
        }

        // Поиск палиндромов в строке
        for (int mask = 1; mask < (1 << count); mask++) {
            cur_words = 0;
            string PolindromString = "";
            for (int b = count - 1; b >= 0; b--) {
                if (mask & (1 << b)) {
                    PolindromString += Word[b];
                    cur_words += 1;
                }
            }
            int PolindromLength = PolindromString.length();
            bool isPalindrome = true;

            for (int i = 0; i < (PolindromLength / 2); i++) {
                if (PolindromString[i] != PolindromString[(PolindromLength - 1) - i]) {
                    isPalindrome = false;
                    break;
                }
            }
            // Если найден палиндром, проверяем его длину и количество слов
            if (isPalindrome == true) {
                if (max_char < PolindromLength) {
                    max_words = cur_words;
                    saved_mask = mask;
                    max_char = PolindromLength;
                }
                cout << PolindromString << " is a palindrome" << endl;
            } else cout << PolindromString << " is not a palindrome" << endl;
        }

        // Создание строк с правильным и неправильным ответом
        int CountOfWrong = 0;
        string included[max_words];
        string excluded[count - max_words];
        string AnswerWrong = "";
        string AnswerGood = "";

        int i = 0, j = 0;
        for (int b = 0; b <= count - 1; b++) {
            if (saved_mask & (1 << b)) {
                included[i++] = Word[b];
                AnswerGood += Word[b] + " ";
            } else {
                excluded[j++] = Word[b];
                AnswerWrong += Word[b] + " ";
                CountOfWrong++;
            }
        }

        // Запись в файл
        if (out.is_open()) {
            out << AnswerGood << endl;
            out << AnswerWrong << endl;
            out << CountOfWrong << endl;
        }
        cout << "" << '\n';
    }
    file.close();
    out.close();
    return 0;
}
