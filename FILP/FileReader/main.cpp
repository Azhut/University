#include <iostream>
#include <fstream>
#include <map>
#include <chrono>
#include <algorithm>
#include <windows.h>
#include <vector>

using namespace  std;


bool compare(pair<string, int>& n,pair<string, int>& m)
{
    return n.second > m.second;
}
void sort(map<string, size_t> M)
{


    vector<pair<string, int> > Ans;
    for (auto& i : M)
    {
        Ans.push_back(i);
    }

    sort(Ans.begin(), Ans.end(), compare);


    for (auto& i : Ans) {

        cout << i.first << ' '
             << i.second << endl;
    }
}


int main() {

    SetConsoleOutputCP(CP_UTF8);
    map<string, size_t> wordCount;
    map<string, size_t>::iterator wordCount_idx;
    auto start = chrono::high_resolution_clock::now();


    std::ifstream file(R"(C:\Users\Egor\Desktop\Coding\C++\FileReader\input.txt)");
    if (!file.is_open()) {
        cerr << "Error opening file" << endl;
        return 1;
    }

    string word;
    while (file >> word) {
        wordCount[word]++;
    }


    file.close();

    sort(wordCount);

//    for (wordCount_idx=wordCount.begin();  wordCount_idx!=wordCount.end() ; wordCount_idx++) {
//        cout<<wordCount_idx->first<<": "<< wordCount_idx->second << endl;
//    }


    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
    cout << "Execution time: " << duration << " milliseconds" << endl;

    return 0;
}
