#include <iostream>
using namespace std;

//сортировки
template <typename elType>
void BubbleSort(elType* arr, int n, bool (*comparator)(elType, elType) = NULL){
    /*
     * BubbleSort простая сортировка для небольших массивов ~1000
     * сложность:
     *   худшая  O(n^2)
     *   средняя O(n^2)
     *   лучшая  O(n^2)
     * память O(1)
    */
    if (comparator == NULL) {
        elType temp;
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
    else{
        elType temp;
        for (int i = 0; i < n - 1; ++i) {
            for (int j = 0; j < n - 1; ++j) {
                if ( comparator( arr[j], arr[j + 1]) ) {
                    temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
    }
}

template <typename elType>
void QuickSort(elType *arr, int end, int start = 0){
    /*
     * recursive QuickSort хорошая и простая в написании сортировка
     * сложность:
     *   худшая  O(n^2)
     *   средняя O(n*log(n))
     *   лучшая  O(n*log(n))
     * память O(1)
     */
    if (start>=end){
        return;
    }
    int pivot= arr[end], SepPointer = start;
    elType temp;
    for(int i = start; i < end; i++){
        if (arr[i] < pivot){
            temp = arr[i];
            arr[i] = arr[SepPointer];
            arr[SepPointer] = temp;
            SepPointer++;
        }
    }
    temp = arr[end];
    arr[end] = arr[SepPointer];
    arr[SepPointer] = temp;
    Quicksort(arr, SepPointer-1, start);
    Quicksort(arr, end, SepPointer+1);
}

template <typename elType>
void Merge_sort(elType* &arr, unsigned int len) {
    /*
     *не рекурсивная MergeSort
     * сложность:
     *   худшая  O(n*log(n))
     *   средняя O(n*log(n))
     *   лучшая  O(n*log(n))
     * память O(n)
     */
    unsigned int block_size = 1, block_start, block_sep, block_end;
    elType *arr2 = new elType[len];
    unsigned int i, j, k;

    while (true) {
        if (block_size >= len) {
            //delete[] arr2;
            break;
        }

        block_end = 0;
        //сортируем все блоки из arr в arr2
        do {
            //сортируем конкретные два блока
            block_start = block_end;
            block_sep = min(block_start + block_size, len);
            block_end = min(block_sep + block_size, len);
            for (i = block_start, j = block_sep, k = block_start; i < block_sep && j < block_end;) {
                if (arr[i] < arr[j]) arr2[k++] = arr[i++];
                else arr2[k++] = arr[j++];
            }
            if (i < block_sep) memcpy(arr2 + k, arr + i, (block_sep - i) * sizeof(elType));
            else if (j < block_end) memcpy(arr2 + k, arr + j, (block_end - j) * sizeof(elType));

        } while (block_end != len);
        block_size *= 2;

        if (block_size >= len) {
            //delete[] arr;
            arr = arr2;
            break;
        }

        block_end = 0;
        //сортируем все блоки из arr2 в arr
        do {
            //сортируем конкретные два блока
            block_start = block_end;
            block_sep = min(block_start + block_size, len);
            block_end = min(block_sep + block_size, len);
            for (i = block_start, j = block_sep, k = block_start; i < block_sep && j < block_end;) {
                if (arr2[i] < arr2[j]) arr[k++] = arr2[i++];
                else arr[k++] = arr2[j++];
            }
            if (i < block_sep) memcpy(arr + k, arr2 + i, (block_sep - i) * sizeof(elType));
            else if (j < block_end) memcpy(arr + k, arr2 + j, (block_end - j) * sizeof(elType));

        } while (block_end != len);
        block_size *= 2;
    }
}


//матрицы
string stl(string s, int ToLen, char fill = ' ', bool beak = false){
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
string GetElement(int **&matrix, int i, int j, int h, int w, int el_num, bool RowCountPrior = true){
    if ((RowCountPrior && i * w + j < el_num) || (!RowCountPrior && j * h +i < el_num)) return to_string(matrix[i][j]);
    else return "";
}
void cinMatrix(int **&matrix, int h, int w, int el_num){
    matrix = new int* [h];
    int i, j, k = 0;
    int temp;
    for(i = 0; i < h; i++){
        matrix[i] = new int[w];
        for(j = 0; j < w; j++){
            if (k++ < el_num) {
                cin>>temp;
                matrix[i][j] = temp;
            }
            else matrix[i][j] = -1;
        }
    }
}
void coutMatrix(int **&matrix, int h, int w, int cell_size,int el_num, bool RowCountPrior = true){
    /* sep chars map
    ctttttttttttttttc
    l   h   h   h   r
    lvvvxvvvxvvvxvvvr
    l   h   h   h   r
    lvvvxvvvxvvvxvvvr
    l   h   h   h   r
    cbbbbbbbbbbbbbbbc
    use lower case x to print nothing*/
    const char L = '{';
    const char H = '|';
    const char R = '}';

    const char T = '_';
    const char V = '-';
    const char B = '=';

    //removed with other lines
    const char X = '+';
    const char C = '*';

    //шапка
    if (T!='x') {
        if (L!='x') cout << C;
        cout<< string((cell_size+1)*w - 1, T);
        if (R!='x')cout << C;
        cout << endl;
    }

    //первоя строка
    if(h > 0) {
        if (L!='x') cout << L ;
        if (w > 0) cout << stl(GetElement(matrix, 0, 0, h,  w, el_num, RowCountPrior), cell_size);
        for (int j = 1; j < w; j++) {
            if (H!='x')cout << H;
            cout << stl(GetElement(matrix, 0, j, h, w, el_num, RowCountPrior), cell_size);
        }
        if (R!='x') cout << R;
        cout << endl;
    }

    //[2;h] строки
    for (int i = 1; i < h; ++i) {
        //разделители строк
        if (V!='x') {
            if (L != 'x') cout << L;
            cout << string(cell_size, V);
            for (int j = 1; j < w; j++){
                if (H!='h') cout << X;
                cout << string(cell_size, V);
            }
            if (R!='x') cout << R;
            cout << endl;
        }

        if (L!='x') cout << L;
        if (w > 0) cout << stl(GetElement(matrix, i, 0, h, w, el_num, RowCountPrior), cell_size);
        for (int j = 1; j < w; ++j) {
            if (H!='x')cout << H;
            cout << stl(GetElement(matrix, i, j, h, w, el_num,RowCountPrior), cell_size);
        }
        if (R!='x') cout << R;
        cout << endl;
    }

    //низ
    if (B!='x') {
        if (L!='x') cout << C;
        cout << string((cell_size + 1) * w - 1, B);
        if (R!='x') cout << C;
        cout << endl;
    }
}
void DeleteMatrix(int **&matrix, int h, int w){
    for (int i = 0; i < h; i++){
        delete matrix[i];
    }
    delete matrix;
}
void GetTransposedMatrix(int **&matrix, int **&matrixT, int h, int w){
    matrixT = new int* [w];
    for (int i = 0; i < w; ++i) {
        matrixT[i] = new int[h];
        for (int j = 0; j < h; ++j) {
            matrixT[i][j] = matrix[j][i];
        }
    }
}

void prefixfuc(char *str, int *pi, int len) {
    pi[0] = 0;
    int i = 0, j = 0;
    //для любого i ограничено сверху числом len
    while (++i < len) {
        //отображение str само на себя сюрьективно, так как из не равенства аргументов
        // (i огр сверху, а j стремиться к 0) следует не равенство значений функции str в них
        //выберем в качестве произвольного j число значение j-ого знака числа pi
        while (str[i] != str[j] && j-->0) j = pi[j];
        //получим что для любого i < len, i-ный символ числа pi равен приделу числа j справа
        pi[i] = ++j;
    }
}

//мой динамический массив
template<typename elType>
struct DArr{//Dynamic Array
            elType *storage;//real array
            unsigned int buffer;//size of storage
            elType *elements;//part of storage filled with real elements, which located somewhere in center
            unsigned int size;//size of elements

            unsigned int LfS ;//Left free Space - cells for adding elements to the beginning
            unsigned  int RfS;//Right free Space - свободные ячейки справа

            float LfR;//Left free Ratio - ratio between size and LfS
            float RfR;//Right free Ratio - ratio between size and RfS
            //LfS = size * LfS_ratio; RfS = size * RfS_ratio; note put ZERO to disable buffering spare space at this side

            unsigned short elsize = sizeof(elType);//размер элементов

            explicit DArr (float Left_free_Space_Ratio = 0.25, float Right_free_Space_Ratio = 0.5){
                //ОСТОРОЖНО - КОСТЫЛЬИ
                //для инициализации нуден пробный элемент для определения типа данных
                elsize = sizeof(elType);
                buffer = 1;
                storage = new elType[buffer];//НЕ ВЫКАЛИ ГЛАЗА

                LfR = Left_free_Space_Ratio;
                RfR = Right_free_Space_Ratio;
                LfS = 0;
                RfS = 1;
                size = 0;
                elements = storage;

            }

            void Normalize(){
                elType *temp = new elType[size];
                memcpy(temp, elements, elsize * size);
                delete[] storage;
                LfS = 0; RfS = 0; buffer = size;
                storage = temp; elements = temp;
            }
            void Buffering(int reserve = 0){
                //положительные значения reserve используются для доп памяти справа, отрицательные для доп памяти слева

                if(reserve > 0){
                    LfS = LfR * (size + reserve);
                    RfS = RfR * (size + reserve) + reserve;
                }
                else{
                    LfS = LfR * (size - reserve) - reserve;
                    RfS = RfR * (size - reserve);
                }

                buffer = LfS + size + RfS;

                elType *temp = new elType[buffer];
                memcpy(temp + LfS, elements, elsize * size);
                delete[] storage;
                storage = temp;
                elements = storage + LfS;
            }

            void Info(){
                cout << "====INFO====\n";
                cout << "buffer: " << buffer << endl;
                cout << "size: " << size << endl;
                cout << "Left free Space: " << LfS << endl;
                cout << "Right free Space: " << RfS << endl;
                cout << "Storage location: " << &storage << endl;
                cout << "elements location: " << &elements << endl;
                cout << "=============\n";
            }
            void Delete(){
        //хз чё ещё должно быть
        delete[] storage;
    }
            void Print(){
                for(int i = 0; i < size; i++){
                    cout << elements[i] << ' ';
                }
                cout << endl;
            }

            elType getel(unsigned int index, elType deflt = NULL){
                if(index >= size) return deflt;
                return elements[index];
            }
            elType* getsubarr(unsigned int start, unsigned int len){
                if (start + len > size) return nullptr;
                elType* temp = new elType[len];
                memcpy(temp, elements + start, elsize * len);
                return temp;
            }

            void append(elType element){
                if(!RfS) Buffering(1);
                RfS--;
                elements[size] = element;
                size++;
            }
            void append(elType *arr, unsigned int len){
                if(RfS < len) Buffering(len);
                RfS -= len;
                memcpy(elements + size, arr, elsize * len);
                size += len;
            }
            void append(DArr arr){
                if(RfS < arr.size) Buffering(arr.size);
                RfS -= arr.size;
                memcpy(elements + size, arr.elements, elsize * arr.size);
                size += arr.size;
            }

            void appbeg(elType element){
                if(!LfS) Buffering(-1);
                LfS--;
                elements--;
                size++;
                elements[0] = element;

            }
            void appbeg(elType *arr, unsigned int len){
                if(LfS < len) Buffering(-len);
                LfS -= len;
                elements -= len;
                size += len;
                memcpy(elements, arr, elsize * len);

            }
            void appbeg(DArr arr){
                if(LfS < arr.size) Buffering(-arr.size);
                RfS -= arr.size;
                elements -= arr.size;
                size += arr.size;
                memcpy(elements, arr.elements, elsize * arr.size);
            }

            elType popend(){
                RfS++;
                return elements[size--];
            }
            elType* popend(unsigned int len){
                if(len > size) return nullptr;
                elType *temp = new elType[len];
                RfS += len;
                size -=len;
                memcpy(temp, elements + size, elsize * len);
                return temp;
            }
            DArr popend_DArr(unsigned int len){
                if(len > size) return nullptr;
                DArr temp = DArr<elType>(LfR, RfR);
                RfS += len;
                size -=len;
                temp.append(elements + size, len);
                return temp;
            }

            elType popbeg(){
                size--;
                elements++;
                LfS++;
                return elements[-1];
            }
            elType* popbeg(unsigned int len){
                if(len > size) return nullptr;
                elType *temp = new elType[len];
                memcpy(temp, elements, elsize * len);
                size -=len;
                elements += len;
                RfS += len;
                return temp;
            }
            DArr popbeg_DArr(unsigned int len){
                if(len > size) cout << "popbeg_DArr function invalid len error"<< endl;
                else {
                    DArr temp = DArr<elType>(LfR, RfR);
                    temp.append(elements, len);
                    size -= len;
                    elements += len;
                    RfS += len;
                    return temp;
                }
            }
        };

void Dynamic_Array_showcase(){
    DArr arr = DArr<char>(0.25,1.0);
    arr.Buffering(-5);

    arr.Info();

    arr.append("abr",3);
    arr.append('a');
    arr.append("ca", 2);
    arr.append("da",2);
    arr.append("bra",3);

    arr.appbeg("!!", 2);
    arr.append("_cool!", 6);

    cout << "after all appending" << endl;
    arr.Info();

    cout<< "1)"; arr.Print();

    cout << endl << "2)"; DArr temp1 = arr.popbeg_DArr(8); temp1.Print();

    cout << endl << "3)";cout << arr.popbeg() << endl;

    cout << endl << "4)"; arr.Print();

    cout << endl << "5)" << endl;
    char *temp2 = arr.getsubarr(4, 5);
    for(int i = 0; i < 5; i++){
        cout << temp2[i]<<endl;
    }
    cout<< endl;

    arr.Info();
}

int main(){
    Dynamic_Array_showcase();
    }