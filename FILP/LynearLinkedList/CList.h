#ifndef CLIST_H
#define CLIST_H

template <class T>
class CList
{
private:
    struct CItem  // элемент списка
    {
        T value;        // ключевое поле
        CItem* next;    // указатель на следующий элемент
    };
    CItem* head;        // Корень списка
public:
    CList();
    CList(T* t, int n);
    ~CList();
    void InsFirst(T value);
    void InsLast(T value);
    void print();
    void printMemoryState(const CList<T>& list);
    const CItem* getHead() const;
};




#include "CList.tpp" // Включаем файл с реализацией шаблона

#endif // CLIST_H
