#include <iostream>
#include <string>

using namespace std;
void CoutArray(string*Arr, int n){
    for (int i = 0; i < n; ++i) {
     cout << Arr[i] << endl;
    }
}
int main() {
    int n;
    int HD=0, SZ=0, HP=0, RC=0;
    cin >> n;
    int Size = 2*n+1;
    string* Slytherin=new string[n];
    string* Hufflepuff=new string[n];
    string* Gryffindor=new string[n];
    string* Ravenclaw=new string[n];
    string* All=new string[Size];

    for (int i = 0; i <= 2*n; ++i) {
        getline(cin, All[i]);
    }


   for (int i = 1; i < Size;i+=2) {
        if(All[i+1]=="Slytherin") {Slytherin[SZ]=All[i]; SZ++;}
        else if(All[i+1]=="Hufflepuff") {Hufflepuff[HP] = All[i];HP++;}
        else if(All[i+1]=="Gryffindor") {Gryffindor[HD] = All[i];HD++;}
        else if(All[i+1]=="Ravenclaw") {Ravenclaw[RC] = All[i]; RC++;}
        else cout << "your fucking idiot" << endl;
    }



    cout << "Slytherin: " << endl;
    CoutArray(Slytherin, SZ+1);

    cout << "Hufflepuff: " << endl;
    CoutArray(Hufflepuff, HP+1);

    cout << "Gryffindor: " << endl;
    CoutArray(Gryffindor, HD+1);

    cout << "Ravenclaw: " << endl;
    CoutArray(Ravenclaw, RC+1);


    return 0;
}
