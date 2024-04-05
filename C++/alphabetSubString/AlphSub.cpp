#include <iostream>
#include <string>
using namespace std;

int main() {
    string s="hjlfsABCDEFhfABCDEFGHIakjafy";
    string Sub="";
    int j=0;
    int Ln=0;
    int LastPlace=0;
    for (int i = 0; i < s.length(); ++i) {
        if(s[i]-s[i-1]==1)continue;
        if(Ln < i-j) {Ln = i -j; LastPlace = j;}
        j=i;

    }
    cout << "The start of substring: " << LastPlace << endl
         << "The length of substring: " << Ln << endl
         << "The string: " << s.substr(LastPlace, Ln) << endl;


    for (int i = 0; i < 33; ++i) {
        int char(i)[33];
    }
}


