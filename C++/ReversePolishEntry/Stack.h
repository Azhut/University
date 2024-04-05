//
// Created by Egor on 02.03.2023.
//

#ifndef REVERSEPOLISHENTRY_STACK_H
#define REVERSEPOLISHENTRY_STACK_H


class Stack
{
    char *arr;
    int top;
    int capacity;

public:
    Stack(int size);
    Stack();
    ~Stack();

    void push(char);
    int pop();
    char peek();

    int size();
    bool isEmpty();
    bool isFull();
};


#endif //REVERSEPOLISHENTRY_STACK_H
