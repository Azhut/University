#include <iostream>
#include "CList.h"

int main() {

    //List<int> first
    CList<int> intList;
    intList.InsFirst(1);
    intList.InsFirst(2);
    intList.InsFirst(3);

    //List<int> last
    intList.InsLast(4);
    intList.InsLast(5);
    intList.InsLast(6);



    // Вывод
    std::cout << "Integer List: ";
    intList.print();


    // stringArray
    std::string strArray[] = {"apple", "banana", "orange"};
    CList<std::string> strList(strArray, 3);

    // Вывод
    std::cout << "String List: ";
    strList.print();

    return 0;
}
