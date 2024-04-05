//
// Created by Egor on 02.03.2023.
//

#ifndef QUEUE_CLASS_QUEUE_H
#define QUEUE_CLASS_QUEUE_H


class Queue
{
    int *arr;       // массив для хранения элементов очереди
    int capacity;   // максимальная емкость очереди
    int front;      // передний элемент в очереди
    int last;       // последний элемент в очереди
    int count;      // текущий размер очереди

public:
    Queue(int size);
    Queue();
    ~Queue();

    int pop();
    void push(int x);
    int first();
    int size();
    bool isEmpty();
    bool isFull();
};


#endif //QUEUE_CLASS_QUEUE_H
