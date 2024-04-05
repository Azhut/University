#pragma once

template<typename T>
class List
{
public:
    List();
    ~List();

    //удаление первого элемента в списке
    void pop_front();

    //добавление элемента в конец списка
    void push_back(T data);

    // очистить список
    void clear();

    // получить количество елементов в списке
    int GetSize() { return Size; }

    // перегруженный оператор []
    T& operator[](const int index);

    //добавление элемента в начало списка
    void push_front(T data);

    //добавление элемента в список по указанному индексу
    void insert(T data, int index);

    //удаление элемента в списке по указанному индексу
    void removeAt(int index);

    //удаление последнего элемента в списке
    void  pop_back();

    void quickSort();

private:


    template<typename S>
    class Node
    {
    public:
        Node * pNext;
        T data;

        Node(T data = T(), Node *pNext = nullptr)
        {
            this->data = data;
            this->pNext = pNext;
        }
    };
    int Size;
    Node<T> *head;
};

