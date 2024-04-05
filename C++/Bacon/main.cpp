#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

const string filenameIn = "C:\\Users\\User\\data\\my_scripts\\C++\\inp.txt";
const string filenameOut = "C:\\Users\\User\\data\\my_scripts\\C++\\out.txt";

// Функция для проверки, является ли строка палиндромом
bool isPalindrome(const string& str) {
    int left = 0;
    int right = str.length() - 1;
    while (left < right) {
        if (str[left] != str[right]) {
            return false;
        }
        left++;
        right--;
    }
    return true;
}

int main() {
    ifstream file(filenameIn);
    if (!file.is_open()) {
        cerr << "Unable to open input file." << endl;
        return 1;
    }

    ofstream outFile(filenameOut);
    if (!outFile.is_open()) {
        cerr << "Unable to open output file." << endl;
        return 1;
    }

    string line;
    while (getline(file, line)) {
        int count = 0;
        vector<string> words;

        size_t pos = 0;
        while ((pos = line.find(' ', pos)) != string::npos) {
            count++;
            pos++;
        }
        count++;

        size_t prevPos = 0;
        pos = line.find(' ');
        while (pos != string::npos) {
            words.push_back(line.substr(prevPos, pos - prevPos));
            prevPos = pos + 1;
            pos = line.find(' ', prevPos);
        }
        words.push_back(line.substr(prevPos));

        int maxChars = 0;
        vector<string> maxPalindromeWords;
        for (int mask = 1; mask < (1 << count); mask++) {
            string palindromeString = "";
            int curChars = 0;
            vector<string> curWords;
            for (int b = count - 1; b >= 0; b--) {
                if (mask & (1 << b)) {
                    palindromeString += words[b];
                    curChars += words[b].length();
                    curWords.push_back(words[b]);
                }
            }
            if (isPalindrome(palindromeString)) {
                if (curChars > maxChars) {
                    maxChars = curChars;
                    maxPalindromeWords = curWords;
                }
            }
        }

        for (const auto& word : maxPalindromeWords) {
            outFile << word << " ";
        }
        outFile << endl;
    }

    file.close();
    outFile.close();

    return 0;
}
