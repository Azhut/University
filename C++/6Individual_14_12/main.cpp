#include<iostream>
#include <string>
#include <fstream>

using namespace std;

int*** FileReadDoubleMatrix(string, int***);
void CoutMatrix(int***, int, int);
int QuantityOfTriangleMatrix(int***, int, int, int&);
int *** ChooseTriangularMatrix(int***,int ***, int , int );
int *FindSmallest(int***,int, int, int*);
int ***MatrixSortOfMinElement(int***,int, int, int*);
int* ArraySort(int*, int);



int main(){
    const string filenameIn = "C:\\Users\\Egor\\C++\\6Individual_14_12\\inp.txt";
    ifstream fin;//(filenameIn);
    fin.open(filenameIn);
    int Quantity, Size, l;
    fin >> Quantity >> Size;
    fin.close();
    /////////////////////////////////////Считываем количество и размерность мартиц с файла

    int ***Arr=new int**[Quantity];
    FileReadDoubleMatrix(filenameIn, Arr);
    /////////////////////////////////////Считываем матрицу с файла

    int TringleCounter;
    QuantityOfTriangleMatrix(Arr, Quantity, Size, TringleCounter);
    //cout << "Number is: "<< TringleCounter << endl;
    //////////////////////////////////////Высчитываем количество треугольных матриц

    int ***TriangularArr=new int**[TringleCounter];
    ChooseTriangularMatrix(Arr,TriangularArr, Quantity, Size);
    //////////////////////////////////////Создаем массив треугольных матриц

    int * MinOfMatrix=new int[TringleCounter];
    FindSmallest(TriangularArr,TringleCounter,Size,MinOfMatrix);
    //////////////////////////////////////Ищем наименьший элемент каждой из матриц

    MatrixSortOfMinElement(TriangularArr,TringleCounter, Size, MinOfMatrix);
    ArraySort(MinOfMatrix, Quantity);
    //////////////////////////////////////Сортируем массив матриц по возрастанию наименьшего элемента


    CoutMatrix(TriangularArr,TringleCounter,Size);
    //////////////////////////////////////Вывод всех матриц

  /*  for (int i = 0; i < TringleCounter; ++i) {
        cout << i << ": "<<MinOfMatrix[i] << endl;
        //cout <<MinOfMatrix[i] << endl;
    }
  cout << 0 <<MinOfMatrix[0] << endl;
    /////Очень странная хуйня. Если удалить "<< i << ":"", то меняется содержание массива))))
    /////Если одновременно выводить и тот, и другой вариант, то вообще пиздец будет))))))))))*/
}

int*** FileReadDoubleMatrix(string name, int*** Arr){
    ifstream fin;//(filenameIn);
    fin.open(name);
    int Quantity, Size;
    int l;
    fin >> Quantity >> Size;
    for (int i = 0; i < Quantity; ++i) {
        Arr[i] = new int *[Size];
        for (int j = 0; j < Size; ++j) {
            Arr[i][j] = new int[Size];
            for (int k = 0; k < Size; ++k) {
                fin >> l;
                Arr[i][j][k] = l;
            }
        }
    }

    return Arr;
}

void CoutMatrix(int*** Arr, int Quantity, int Size ){


    int Real=0;
    for (int i = 0; Real < Quantity; ++i) {
        for (int j = 0; j < Size; ++j) {
            for (int k = 0; k < Size; ++k) {
                cout << Arr[i][j][k] << " ";
            }
            cout << endl;
        }
        Real++;
        cout << endl;
    }
};

int QuantityOfTriangleMatrix(int***Arr, int Quantity, int Size, int &TringleCounter){

    int l;
    bool PreviousNotTrigle=false;
    int Real=0, z=0;
    TringleCounter=0;

    int*** NewArr=new int**[Quantity];
    for (int i = 0; Real < Quantity; ++i) {
        if(PreviousNotTrigle){
            PreviousNotTrigle=false;
            i--;
            for (int j = 0; j < Size; ++j) {
                for (int k = 0; k < Size; ++k) {
                    l=Arr[z][j][k];
                    if (j > k && l != 0) PreviousNotTrigle = true;
                    NewArr[i][j][k] = l;
                }
            }
        }else {
            PreviousNotTrigle=false;
            NewArr[i] = new int *[Size];
            for (int j = 0; j < Size; ++j) {
                NewArr[i][j] = new int[Size];
                for (int k = 0; k < Size; ++k) {
                    l =Arr[z][j][k];
                    NewArr[i][j][k] = l;
                    if (j > k && l != 0) PreviousNotTrigle = true;
                }
            }

        }
        Real++;
        TringleCounter=i+1;
        z++;
    }
    TringleCounter-=1;
    return TringleCounter;
}

int ***ChooseTriangularMatrix(int***Arr,int ***TriangularArr, int Quantity, int Size) {

    int l;
    bool PreviousNotTrigle=false;
    int Real=0,z=0;
    int TringleCounter=0;


    for (int i = 0; Real < Quantity; ++i) {
        if(PreviousNotTrigle){
            PreviousNotTrigle=false;
            i--;
            for (int j = 0; j < Size; ++j) {
                for (int k = 0; k < Size; ++k) {
                    l=Arr[z][j][k];
                    if (j > k && l != 0) PreviousNotTrigle = true;
                    TriangularArr[i][j][k] = l;
                }
            }
        }else {
            PreviousNotTrigle=false;
            TriangularArr[i] = new int *[Size];
            for (int j = 0; j < Size; ++j) {
                TriangularArr[i][j] = new int[Size];
                for (int k = 0; k < Size; ++k) {
                    l=Arr[z][j][k];
                    TriangularArr[i][j][k] = l;
                    if (j > k && l != 0) PreviousNotTrigle = true;
                }
            }

        }
        Real++;
        TringleCounter=i+1;
        z++;

    }
    return TriangularArr;
}

int *FindSmallest(int***Arr,int Quantity, int Size, int*MinOfMatrix){

    int Min;
    for (int i = 0; i < Quantity; ++i) {
            Min = 10000000;
            for (int j = 0; j < Size; ++j) {
                for (int k = 0; k < Size; ++k) {
                    if (Arr[i][j][k] < Min) Min = Arr[i][j][k];
                }
            }

        MinOfMatrix[i] = Min;
    }
    return MinOfMatrix;
}

int ***MatrixSortOfMinElement(int***Arr,int Quantity, int Size, int*MinOfMatrix){
    int** temp;
    for (int i = 0; i < Quantity; i++) {
        for (int j = 0; j < Quantity-1; j++) {
            if (MinOfMatrix[j] > MinOfMatrix[j + 1]) {
                int b = MinOfMatrix[j];
                MinOfMatrix[j] = MinOfMatrix[j + 1];
                MinOfMatrix[j + 1] = b;
                temp = Arr[j];
                Arr[j]=Arr[j+1];
                Arr[j + 1] = temp;
            }
        }
    }
    return Arr;
}

int* ArraySort(int* MinOfMatrix, int Quantity) {
    for (int i = 0; i < Quantity; i++) {
        for (int j = 0; j < Quantity - 1; j++) {
            if (MinOfMatrix[j] > MinOfMatrix[j + 1]) {
                int b = MinOfMatrix[j];
                MinOfMatrix[j] = MinOfMatrix[j + 1];
                MinOfMatrix[j + 1] = b;
            }
        }
    }
    return MinOfMatrix;
}