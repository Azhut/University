#include "Queue.h"
#include <iostream>

Queue::Queue(int size)
{
    arr = new int[size];
    capacity = size;
    front = 0;
    last = -1;
    count = 0;
}
Queue::Queue()//переполненный конструктор без аргумента
{
    int SIZE=10000;
    arr = new int[SIZE];
    capacity = SIZE;
    front = 0;
    last = -1;
    count = 0;
}

Queue::~Queue()
{
    delete[] arr;
}


int Queue::pop() //удаление первого элемента из очереди
{

    if (isEmpty())// проверка на опустошение queue
    {
        std::cout << "Error!!!\n the Queue is empty\n";
        exit(EXIT_SUCCESS);
    }


    int x = arr[front];
    std::cout << "Removing first item. This is: " << x << std::endl;

    front = (front + 1) % capacity;
    count--;

    return x;
}


void Queue::push(int item)//добавление элемента в очередь
{

    if (isFull())// проверка на переполнение queue
    {
        std::cout << "Error!!!\nQueue Overflow\n";
        exit(EXIT_FAILURE);
    }

    std::cout << "Adding new item... This is: " << item << std::endl;

    last = (last + 1) % capacity;
    arr[last] = item;
    count++;
}


int Queue::first()//возврат первого элемента в очереди
{
    if (isEmpty())
    {
        std::cout << "Error!!!\nQueue Underflow\n";
        exit(EXIT_FAILURE);
    }
    return arr[front];
}


int Queue::size() //возврат размера очереди
{
    return count;
}


bool Queue::isEmpty() //проверка на пустоту
{
    return (size() == 0);
}


bool Queue::isFull()//проверка на переполнение
{
    return (size() == capacity);
}
