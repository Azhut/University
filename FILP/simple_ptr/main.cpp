#include <iostream>

using namespace std;

template<class T>
class SmartPtr {
    T *ptr;            // ����������� ���������
    size_t *pCounter;  // ��������� �� ������� ������

public:
    // �����������
    explicit SmartPtr(T *p = nullptr) {
        ptr = p;
        pCounter = new size_t(1);
    }

    // ����������� �����������
    SmartPtr(const SmartPtr &other) {
        ptr = other.ptr;
        pCounter = other.pCounter;
        ++(*pCounter);
    }

    // ����������
    ~SmartPtr() {
        if (--(*pCounter) == 0) {
            delete ptr;
            delete pCounter;
        }
    }

    // ���������� ��������� ������������
    SmartPtr &operator=(const SmartPtr &other) {

        if (this != &other) {

            (*other.pCounter)++;


            if (--(*pCounter) == 0) {
                delete ptr;
                delete pCounter;
            }

            ptr = other.ptr;
            pCounter = other.pCounter;
        }
        return *this;
    }


    // ���������� ��������� ������������� (������������)
    T &operator*() {
        return *ptr;
    }

    // ���������� ��������� ��������� ������
    T *operator->() {
        return ptr;
    }

    // ����� ��� ��������� ���������� ������
    size_t use_count() const {
        return *pCounter;
    }
};

int main() {


    SmartPtr<int> ptr1(new int(10));

    cout << "ptr1 value: " << *ptr1 << ", use count = " << ptr1.use_count() << endl;
    SmartPtr<int> ptr2 = ptr1;
    cout << "ptr2 value: " << *ptr2 << ", use count = " << ptr2.use_count() << endl;

    SmartPtr<int> ptr3(new int(20));
    cout << "ptr3 value: " << *ptr3 << ", use count = " << ptr3.use_count() << endl;


    ptr3 = ptr2;
    cout << "ptr3 value: " << *ptr3 << ", use count = " << ptr3.use_count() << endl;

    return 0;
}