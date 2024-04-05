#include <iostream>
#include <string>
using namespace std;

struct m{
    int val;
    char s[16];
} voc[100000];

void qsortRecursive(int,int,int*);

int main() {
  /* int n;
   cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> voc[i].s >> voc[i].val;
    }*/
    int* mas = new int[6] {1,58,25, 85,3, 5};

    qsortRecursive(0,5,mas);

    for (int i = 0; i < 6; ++i) {

        cout <<mas[i] << endl;
    }


    return 0;
}


void qsort(int begin,int end, int* arr){
    int l= begin, r  = end;
    int piv = arr[(l+r)/2];
    while (l <= r) {
        while (arr[l] < piv) {
            l++;
        }
        while (arr[r] > piv) {
            r--;
        }
        if(l<= r) swap(arr[l++],arr[r--]);
    }
    if (end < r) {
        //qsort(begin, r);
    }
    if (end > 1) {
        //qsort(l, end);
    }
}

void qsortRecursive(int begin, int end,int *arr) {
    //Указатели в начало и в конец массива
    int i = begin;
    int j = end - 1;

    //Центральный элемент массива
    int mid = arr[end / 2];

    //Делим массив
    do {
        //Пробегаем элементы, ищем те, которые нужно перекинуть в другую часть
        //В левой части массива пропускаем(оставляем на месте) элементы, которые меньше центрального
        while(arr[i] < mid) {
            i++;
        }
        //В правой части пропускаем элементы, которые больше центрального
        while(arr[j] > mid) {
            j--;
        }

        //Меняем элементы местами
        if (i <= j) {
            int tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;

            i++;
            j--;
        }
    } while (i <= j);


    //Рекурсивные вызовы, если осталось, что сортировать
    if(j > 0) {
        //"Левый кусок"
        qsortRecursive(begin, j + 1,arr);
    }
    if (i < end) {
        //"Првый кусок"
        qsortRecursive(arr[i], end - i,arr);
    }
}

