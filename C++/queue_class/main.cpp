
#include <iostream>
#include "Queue.h"
using namespace std;


int main() {
    Node* a = nullptr;
    push(&a, 5);
    push(&a, 20);
    push(&a, 4);
    push(&a, 3);
    push(&a, 30);

    cout << "��������� ������ �� ���������� \n";
    printList(a);

    // ����� ������� ����������
    quickSort(&a);

    cout << "��������� ������ ����� ���������� \n";
    printList(a);

    return 0;
}