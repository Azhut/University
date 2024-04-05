#include <iostream>
#include <string>
#define N 5

using namespace std;

bool Ok(int, int);
int direct[4][2]={{1,0}, {0,1}, {-1,0}};

int Table[N][N];
char Alph[N][N];
bool IsWord;

void SrchWord(string w,int i, int j, int k){
    if(!IsWord){
        k++;
        Table[i][j]=k;
        if (k == w.length()) IsWord = true;
        for (int l = 0; l < 4; ++l) {
            int x = i + direct[l][0];
            int y = j + direct[l][1];
            if(Ok(x,y) && (Alph[x][y]==w[k]) SrchWord(w,i,j,k);
        }
        k--;
        Table[i][j]=0;
    }
}

int ** Srch(char a, int& k){
    int **symb = new int *[2];
    symb[0]=new int[16];
    symb[1]=new int[16];
    k=0;
    for (int i = 0; i < N ; ++i) {
        for (int j = 0; j < N; ++j) {
            if(Alph[i][j]==a){
                symb[0][k] =i;
                symb [1][k]=j;
                k++;
            }
        }
    }
    return  symb;
};





int main() {
    for (int i = 1; i <N ; ++i) {
        for (int j = 1; j <N ; ++j) {
            cin >> Alph[i][j];
        }
    }

    string w;
    int n;
    cin >> n;
string* words=

    for (int i = 0; i < n; ++i) {
        w=words[i];
        cout << w << ": "
        for (int i = 1; i < N ; ++i) {
            for (int j = 1; j < ; ++j) {
                Table[i][j]=0;
            }
        }
    }



    for (int j = 1; j < N; ++j) {
        Table[i][j]=0;
        symb= Srch(w[0]),count);
        IsWord=false;
        while(count > 0 && !IsWord){
            int x = symb[0][count - 1];
            int y = symb[1][count-1];
            count--;
            int k=0;
            SrchWord
        }
    }
    return 0;
}
