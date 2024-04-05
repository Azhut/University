#include "Stack.h"
#include <iostream>




Stack::Stack(int size)
{
    arr = new char[size];
    capacity = size;
    top = -1;
}
Stack::Stack()
{
    int size = 10000;
    arr = new char[size];
    capacity = size;
    top = -1;
}

Stack::~Stack() {
    delete[] arr;
}


void Stack::push(char x)// Добавление элемента в стек
{
    if (isFull())
    {
        std::cout << "Error!!!\nOverflow\n";
        exit(EXIT_FAILURE);
    }

    std::cout << "Inserting new item: " << x << std::endl;
    arr[++top] = x;
}


int Stack::pop()//Удаление верхнего элемента стека
{

    if (isEmpty()) // проверка на опустошение стека
    {
        std::cout << "Error!!!\nUnderflow\n";
        exit(EXIT_FAILURE);
    }

    std::cout << "Removing " << peek() << std::endl;

    //необязательный возврат(!)
    return arr[top--];
}


char Stack::peek()//возврат верхнего элемента из стека
{
    if (isEmpty()) {
        exit(EXIT_FAILURE);
    }
    return arr[top];
}


int Stack::size() //возврат размера стека
{
    return top + 1;
}

bool Stack::isEmpty()// проверка на опустошение стека
{
    return size() == 0;
}


bool Stack::isFull() //проверка не переполнение стека
{
    return size() == capacity;
}

