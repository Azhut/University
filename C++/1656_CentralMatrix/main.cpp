#include <iostream>

using namespace std;


void distFromCenter(int** arr, int n, int size){
    int temp, bad;
    for (int j = 0; j < n-1; ++j) {

            if ( (arr[j][0] - size/2) + (arr[j+1][0] - size/2) < (arr[j][1] - size/2) + (arr[j + 1][1]- size/2 )) {
                temp = arr[j][0];
                arr[j][0] = arr[j + 1][0];
                arr[j + 1][0] = temp;

                bad = arr[j][1];
                arr[j][1] = arr[j + 1][1];
                arr[j + 1][1] = bad;
            }
        }



}

/*bool distFromCenter(int *a, int *b, int size){
    return abs(a[0] - size/2)+ abs(a[1] - size/2) < abs(b[0] - size/2) + abs(b[1] - size/2);
}*/

void GrowSort(int* arr, int n){
    int temp;
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void CoutMatrix(int** ans, int size){
    size-=1;
    for(int i = 0; i <1; i++){
        for(int j = 0; j <1; j++){
            cout << ans[0][0] << ' '<< ans[0][size] << ' '<< ans[size][0] << endl
             << ans[0][1] << ' ';
            cout << ans[1][size] << ' '<< ans[size][size] << endl << ans[1][0] << ' ' << ans[size][1] << ' ' ;
            cout << ans[1][1] << ' ';
        }
        cout << endl;
    }
    return;
};

int main(){
    int size, size2;
    cin >> size;
    size2 = size * size;

    int *solders = new  int[size2];
    for(int i = 0; i < size2; i++){
        cin >> solders[i];
    }

    GrowSort(solders, size2);

    int **placement = new  int* [size2];
    //int **placement = new  int* [size2];

    for(int i = 0; i < size; i++){
        for (int j = 0; j <= size; ++j) {
            placement[i * size + j] = new int[2];
            placement[i * size + j][0] = j;
            placement[i * size + j][1] = i;
        }
    }
  /*  for (int i = 0; i < size; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << placement[i * size + j][0] << '\t'
                 << placement[i * size + j][1] << endl;
        }
    }*/

    //сортируем все возможные позиции по удалению от центра
  distFromCenter(placement, size2, size);
    cout << endl;
    /*for (int i = 0; i < size; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << placement[i * size + j][0] << '\t'
                 << placement[i * size + j][1] << endl;
        }
    }*/

    int **ans = new int *[size];
    for(int i = 0; i < size; i++) ans[i] = new int[size];
    for(int i = 0; i < size2; i++){
        ans[placement[i][0]][placement[i][1]] = solders[i];
    }

    CoutMatrix(ans,size); //вывод в терминал

}
