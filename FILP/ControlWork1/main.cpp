#include <iostream>
using namespace std;

template <class T>
class CList
{
private:
    struct CItem
    {
        T value;
        CItem* next;
    };
    CItem* head;    // Корень списка
    bool isInList(T t){
        CItem* current=head;
        while(current!=nullptr){
            if(current->value==t) return true;
            current = current->next; // добавлено обновление указателя
        }
        return false;
    }
public:
    CList(): head(nullptr) {} // Инициализация списка
    CList(T* t, int n)  // Инициализация списка по n элементам массива
    {
        if (n <= 0 || t == nullptr) {
            head = nullptr;
            return;
        }

        CItem* p = new CItem;
        head = p;
        p->value = t[0];
        for(int i = 1; i < n; i++)
        {
            p->next = new CItem;
            p = p->next;
            p->value = t[i];
        }
        p->next = nullptr;
    }

    ~CList()
    {
        CItem* p;
        while (head)
        {
            p = head;
            head = head->next;
            delete p;
        }
    }

    void insFirst(T t)  // Вставка элемента в начало списка
    {
        CItem* p = new CItem;
        p->value = t;
        p->next = head;
        head = p;
    }

    void insertAfterEveryFourth(T value) // Вставка элемента после каждого четвертого элемента
    {
        CItem* current = head;
        int count = 0;
        while (current != nullptr) {
            count++;
            if (count % 4 == 0) {
                CItem* newNode = new CItem;
                newNode->value = value;
                newNode->next = current->next;
                current->next = newNode;
                current = newNode->next;
            } else {
                current = current->next;
            }
        }
    }

    CList copySet(){
        CList<T> newCList;
        CList<T> visited;
        CItem* currentOldList=head;

        while(currentOldList!=nullptr){
            if (!visited.isInList(currentOldList->value)) {
                newCList.insFirst(currentOldList->value);
                visited.insFirst(currentOldList->value);
            }
            currentOldList=currentOldList->next;
        }

        return newCList;
    }


    void print()
    {
        CItem* p = head;
        if (!p)
        {
            cout << "List is empty!\n";
            return;
        }
        while(p)
        {
            cout<<'[' << p->value << ']'<< ' ';
            p = p->next;
        }
        cout<<endl;
    }

    int size(){
        int counter=0;
        CItem* current=head;
        while (current!= nullptr){
            counter++;
            current=current->next;
        }

        return counter;
    }
};

int main()
{
    system("chcp 1251");
    int a[] = {9,7,6,4,3,2,1,20,1,3,5,4,4,5,5,};
    CList<int> L1;
    CList<int> L2(a,15);
    L1.print();
    L1.insFirst(5);
    L1.insFirst(8);
    L1.insFirst(7);
    L1.print();
    L2.print();


    cout << "Inserting after every fourth element:\n";
    L2.insertAfterEveryFourth(100); //Вставка после каждого четвертого
    L2.print();

    CList<int> L2_SET=L2.copySet();
    cout << "L2_SET:\n";
    L2_SET.print();

    int b[] = {3,3,3,3,3,3,3,3,3,3,3,3,3,3,3};

    cout<<"b-array:"<<endl;
    for(auto t :b ){
        cout <<'['<< t<<']' <<' ';
    } cout<< endl;

    CList<int> L3(b,15);
    CList<int> L3_SET=L3.copySet();
    cout << "L3_SET:\n";
    L3_SET.print();

    return 0;
}
