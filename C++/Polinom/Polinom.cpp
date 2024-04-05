#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>
#include <fstream>

using namespace std;
const string InputPath = "C:\\Users\\Egor\\C++\\Polinom\\in.txt";
const string OutputPath = "C:\\Users\\Egor\\C++\\Polinom\\out.txt";

void Swap2(int i, int j,int *arr, int* arr2){
    int tmp = arr[j];
    arr[j] = arr[i];
    arr[i] = tmp;

    tmp = arr2[j];
    arr2[j] = arr2[i];
    arr2[i] = tmp;
}

void IDK_sort(int*&arr, int start, int end, int*&arr2){
    //start - индекс первого элемента
    //end - индекс следующий за последним (не включительно)
    if(end - start <= 2){
        if(end-start==1)return;
        if (arr[start + 1] > arr[start]) return;
        Swap2(start, start + 1, arr, arr2);
        return;
    }


    int sep = (start + end) / 2;//начало второй половины
    IDK_sort(arr, start, sep , arr2);
    IDK_sort(arr, sep, end, arr2);

    int* temp = new int[end - start + 1];
    int* temp2 = new int[end - start + 1];
    int i = start, j = sep, k = start;
    while((i < sep) && (j < end)){
        if (arr[i] < arr[j]) {
            temp[k] = arr[i];
            temp2[k++] = arr2[i++];
        }
        else {
            temp[k] = arr[j];
            temp2[k++] = arr2[j++];
        }
    }
    while(i < sep) {

       temp[k]=arr[i];
       temp2[k++]=arr2[i++];
    }
    while(j < end) {
        temp[k]=arr[j];
        temp2[k++]=arr2[j++];
    }
    delete[] arr;
    delete[] arr2;
    arr = temp;
    arr2 =temp2;
}

int main(){
    string inp;
    ifstream fin;
    fin.open(InputPath);
    if (!fin.is_open()){
        cout << "file can't open file";
        return 1;
    }

    int counter=-1;
    while( getline(fin, inp)) {
        counter++;
    }
    fin.close();
    cout << counter << endl;
//Подсчет количества строк




    int x;
    fin.open(InputPath);
    if (!fin.is_open()){
        cout << "file can't open file";
        return 1;
    }
    int *weights = new int[counter];
    int *powers = new int[counter];
    fin >> x;
    getline(fin, inp);
    int i =0, sep;
    while(getline(fin, inp)) {
          sep = inp.find(' ', 0);
          weights[i] = stoi(inp.substr(0,sep));
          powers[i] = stoi(inp.substr(sep+1,inp.length()-sep-1));
          i++;
    }
    fin.close();
//создание массивов с коэффицентами и степенями x


    IDK_sort(powers,0,counter,weights);
//сортируем массивы
    for (int i = 0; i < counter; i++){
        cout << weights[i]<< "x^" <<powers[i] << endl;
    }
//прочекать
int SIZE=powers[counter-1]+1;
int* zero= new int[SIZE];
int j=0;
    for (i = 0; i < SIZE ; i++) {
        if(powers[j]==i) zero[i]=weights[j++];
        else zero[i]=0;
    }
    for (int i = 0; i < SIZE; i++){
        cout << zero[i] << endl;
    }

    int answer=zero[SIZE-1];
    for (int i = SIZE-2; i >= 0; --i) {
        answer*=x;
        answer+=zero[i];
    }
    cout << answer << endl;
}