#include <iostream>
#include <string>
using namespace std;

int main() {
    int NumberOfCompitition;
    string CompName;
    string Data;
    int NumberOfProblems, NumberOfTries;
    char Task;
    int TaskNumber;
    string result;


    cin >> NumberOfCompitition;
    string Sep= "+------------------------------+--------+-------------+\n";
    cout << Sep;
    cout << "|Contest name                  |Date    |ABCDEFGHIJKLM|"<< endl;
    cout << Sep;



    for(int i=0;i<NumberOfCompitition; i++)
    {
        getline(cin,CompName);
        getline(cin,CompName);
        getline(cin,Data);
        cin >> NumberOfProblems >> NumberOfTries;

        //cout << CompName << '\t' << Data << endl;
        //cout << NumberOfProblems << NumberOfTries << endl;

        bool *Accepted= new bool[NumberOfProblems] {0};
        bool *Wrong= new bool[NumberOfProblems]{0};

        for (int j=0;j<NumberOfTries;j++) {
            cin >> Task;
            cin >> result;
            //cout << Task << result << endl;
            TaskNumber = int(Task)-int('A');
            Wrong[TaskNumber]=true;
            if(result == "Accepted") Accepted[TaskNumber]=true;
        }
        string space(30-CompName.length(), ' ');
        cout << "|" << CompName << space << '|' << Data << "|";
        for (int j = 0; j < NumberOfProblems; ++j) {
            if(Accepted[j]) cout << "o";
            else if(Wrong[j]) cout << "x";
            else cout << ".";
        }
        string space1(13-NumberOfProblems, ' ');
        cout << space1 << "|"<<endl;
        cout << Sep;

    }



    /*bool TryOrNot[]
    for()
    cout <<*/
    return 0;
}