#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    static Node* quickSortRecur(Node* head, Node* end);
};

/* Функция для вставки узла в начало связанного списка */
void push(Node** head_ref, int new_data) {
    Node* new_node = new Node;
    new_node->data = new_data;
    new_node->next = *head_ref;
    *head_ref = new_node;
}

/* Функция для печати связанного списка */
void printList(Node* node) {
    while (node != nullptr) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

// Возвращает последний узел списка
Node* getTail(Node* cur) {
    while (cur != nullptr && cur->next != nullptr)
        cur = cur->next;
    return cur;
}

// Разбивает список, взяв последний элемент в качестве опорного
Node* partition(Node* head, Node* end, Node** newHead, Node** newEnd) {
    Node* pivot = end;
    Node* prev = nullptr;
    Node* cur = head;
    Node* tail = pivot;

    while (cur != pivot) {
        if (cur->data < pivot->data) {
            if ((*newHead) == nullptr)
                (*newHead) = cur;
            prev = cur;
            cur = cur->next;
        }
        else {
            if (prev)
                prev->next = cur->next;
            Node* tmp = cur->next;
            cur->next = nullptr;
            tail->next = cur;
            tail = cur;
            cur = tmp;
        }
    }

    if ((*newHead) == nullptr)
        (*newHead) = pivot;

    (*newEnd) = tail;

    return pivot;
}

// Здесь происходит сортировка без учета конечного узла
Node* Node::quickSortRecur(Node* head, Node* end) {
    if (!head || head == end)
        return head;

    Node *newHead = nullptr, *newEnd = nullptr;

    Node* pivot = partition(head, end, &newHead, &newEnd);

    if (newHead != pivot) {
        Node* tmp = newHead;
        while (tmp->next != pivot)
            tmp = tmp->next;
        tmp->next = nullptr;

        newHead = quickSortRecur(newHead, tmp);

        tmp = getTail(newHead);
        tmp->next = pivot;
    }

    pivot->next = quickSortRecur(pivot->next, newEnd);

    return newHead;
}

// Основная функция для быстрой сортировки. Оболочка над рекурсивной функцией quickSortRecur()
void quickSort(Node** headRef) {
    (*headRef) = Node::quickSortRecur(*headRef, getTail(*headRef));
}


