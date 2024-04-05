#include <iostream>
#include "CList.h"

template<class T>
CList<T>::CList(): head(nullptr) {} // Инициализация списка

template<class T>
CList<T>::CList(T *t, int n): head(nullptr) // Инициализация списка по n элементам массива
{
    if (t != nullptr && n > 0) {
        for (int i = 0; i < n; ++i) {
            InsFirst(t[i]);
        }
    }
}

template<class T>
CList<T>::~CList() // удаление списка
{
    CItem *temp = head;
    while (head != nullptr) {
        temp = head;
        head = head->next;
        delete temp;
    }
    this->print();
}

template<class T>
void CList<T>::InsFirst(T value) // Вставка нового элемента в начало списка
{
    CItem *newItem = new CItem;
    newItem->value = value;
    newItem->next = head;
    head = newItem;
}

template<class T>
void CList<T>::InsLast(T value) // Вставка нового элемента в конец списка
{
    CItem *newItem = new CItem;


    CItem *current = head;
    while (current->next != nullptr) {
        current = current->next;
    }
    current->next = newItem;

    newItem->value = value;
    newItem->next = nullptr;

}

template<class T>
void CList<T>::print() // Вывод списка на печать
{
    CItem *current = head;
    while (current != nullptr) {
        std::cout << current->value << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

// Функция для отладочного вывода состояния памяти списка
template<class T>
void CList<T>::printMemoryState(const CList<T> &list) {
    typename CList<T>::CItem* current = list.head;
    std::cout << "Memory state: ";
    while (current != nullptr) {
        std::cout << "[" << current->value << "] -> ";
        current = current->next;
    }
    std::cout << "nullptr" << std::endl;
}

template <class T>
const typename CList<T>::CItem* CList<T>::getHead() const {
    return head;
}

