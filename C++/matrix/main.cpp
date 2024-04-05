#include <iostream>
#include <string>
using namespace std;

// Объявление функций
void cinMatrix(int **&, int, int, int);
void coutMatrix(int **&, int, int, int, int, bool);
void DeleteMatrix(int **&, int, int);
void GetTransposedMatrix(int **&, int **&, int, int);
string StringToLen(string, int, char, bool);
string GetElement(int **&, int, int, int, int, int, bool);

int main(){
    int NumberOfElements, NumberOfColumns;
    int **A, Aw, h;

    // Ввод количества элементов и столбцов матрицы
    cin >> NumberOfElements >> NumberOfColumns;
    Aw = NumberOfElements / NumberOfColumns + bool(NumberOfElements % NumberOfColumns);
    int matrix[Aw][NumberOfColumns];

    // Заполнение матрицы данными
    for (int i = 0; i < Aw; ++i) {
        for (int j = 0; j < NumberOfColumns; ++j) {
            cin >> matrix[i][j];
        }
    }

    // Вывод матрицы
    for (int i = 0; i < Aw; ++i) {
        for (int j = 0; j < NumberOfColumns; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl; // После вывода элементов j-й строки делаем переход на новую строку
    }

    // Транспонирование матрицы
    int **B, Bh = Aw, Bw = NumberOfColumns;
    GetTransposedMatrix(A, B, NumberOfColumns, Aw);
    DeleteMatrix(A, NumberOfColumns, Aw);
    coutMatrix(B, Bh, Bw, 4, NumberOfElements, false);
}

// Функция для форматированного преобразования строки заданной длины
string StringToLen(string s, int ToLen, char fill = ' ', bool beak = false){
    int Len = s.length();
    if (Len < ToLen){
        if (beak){
            s.append(string(ToLen - Len, fill));
            return s;
        }
        else {
            s.insert(0, string(ToLen - Len, fill));
            return s;
        }
    }
    else if (Len > ToLen) {
        if (beak) return s.substr(0, ToLen);
        else return s.substr(Len - ToLen, ToLen);
    }
    else return s;
}

// Функция для получения элемента матрицы в строковом формате
string GetElement(int **&matrix, int i, int j, int h, int w, int el_num, bool RowCountPrior = true){
    if ((RowCountPrior && i * w + j < el_num) || (!RowCountPrior && j * h + i < el_num)) return to_string(matrix[i][j]);
    else return "";
}

// Функция для вывода матрицы с форматированием
void coutMatrix(int **&matrix, int h, int w, int cell_size, int el_num, bool RowCountPrior = true){
    // Определение символов для форматирования
    const char L = 'x';
    const char H = 'x';
    const char R = 'x';

    const char T = 'x';
    const char V = 'x';
    const char B = 'x';

    const char X = 'x';
    const char C = '&';

    // Шапка
    if (T != 'x') {
        if (L != 'x') cout << C;
        cout << string((cell_size + 1) * w - 1, T);
        if (R != 'x') cout << C;
        cout << endl;
    }

    // Первая строка
    if (h > 0) {
        if (L != 'x') cout << L;
        if (w > 0) cout << StringToLen(GetElement(matrix, 0, 0, h, w, el_num, RowCountPrior), cell_size);
        for (int j = 1; j < w; j++) {
            if (H != 'x') cout << H;
            cout << StringToLen(GetElement(matrix, 0, j, h, w, el_num, RowCountPrior), cell_size);
        }
        if (R != 'x') cout << R;
        cout << endl;
    }

    // [2;h] строки
    for (int i = 1; i < h; ++i) {
        if (L != 'x')
            if (w > 0) cout << StringToLen(GetElement(matrix, i, 0, h, w, el_num, RowCountPrior), cell_size);
        for (int j = 1; j < w; ++j) {
            if (H != 'x')
                cout << StringToLen(GetElement(matrix, i, j, h, w, el_num, RowCountPrior), cell_size);
        }
        if (R != 'x') cout << R;
        cout << endl;
    }

    // Низ
    if (B != 'x') {
        if (L != 'x') cout << C;
        cout << string((cell_size + 1) * w - 1, B);
        if (R != 'x') cout << C;
        cout << endl;
    }
}

// Функция для освобождения памяти, занятой матрицей
void DeleteMatrix(int **&matrix, int h, int w){
    for (int i = 0; i < h; i++){
        delete matrix[i];
    }
    delete matrix;
}

// Функция для транспонирования матрицы
void GetTransposedMatrix(int **&matrix, int **&matrixT, int h, int w){
    matrixT = new int* [w];
    for (int i = 0; i < w; ++i) {
        matrixT[i] = new int[h];
        for (int j = 0; j < h; ++j) {
            matrixT[i][j] = matrix[j][i];
        }
    }
}
