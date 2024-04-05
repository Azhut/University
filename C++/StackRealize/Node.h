//Node.h
#ifndef Node_H

#define Node_H
typedef struct Node {
    int num;
    Node* prev;
} Box;

typedef Box* Boxptr;

Boxptr INIT(int n);
void PushBox(Boxptr, Boxptr&);
void printStack(Boxptr);
void DeleteBox(int idx, Boxptr&);
#endif
