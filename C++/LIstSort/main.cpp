#include <iostream>
using namespace std;
#include "List.h"

/*
* односвязный список
* реализация
*/





int main()
{
    List<int>  lst;
    lst.push_front(5);
    lst.push_front(7);
    lst.push_front(101);

    for (int i = 0; i < lst.GetSize(); i++)
    {
        cout << lst[i] << endl;
    }

    cout << endl << "pop_back " << endl << endl;

    lst.pop_back();

    for (int i = 0; i < lst.GetSize(); i++)
    {
        cout << lst[i] << endl;
    }

    return 0;
}

