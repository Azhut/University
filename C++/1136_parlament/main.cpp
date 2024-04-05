#include <iostream>
using namespace std;

struct BineTree {
    int field;           // поле данных
    BineTree *left;  // левая вевть
    BineTree *right; // правая ветвь
};

void RightTreePrint(BineTree *tree) {
    if (tree!=nullptr) { //Пока не встретится пустой узел
        RightTreePrint(tree->right); //Рекурсивная функция для правой ветви
        RightTreePrint(tree->left); //Рекурсивная функция для левой ветви
        cout << tree->field << endl; //Отображаем корень дерева
    }
}

void PostFixTreePrint(BineTree *tree) {
    if (tree!= nullptr) { //Пока не встретится пустой узел
    PostFixTreePrint(tree->left); //Рекурсивная функция для левой ветви
    PostFixTreePrint(tree->right); //Рекурсивная функция для правой ветви
    cout << tree->field; //Отображаем корень дерева
}
}

BineTree * AddNode(int x, BineTree *tree) {
    if (tree == nullptr) { // Если дерева нет, то формируем корень
        tree =new BineTree; // память под узел
        tree->field = x;   // поле данных
        tree->left =  nullptr;
        tree->right = nullptr; // ветви инициализируем пустотой
    }else  if (x < tree->field)   // условие добавление левой ветви
        tree->left = AddNode(x,tree->left);
    else    // условие добавление правой ветви
        tree->right = AddNode(x,tree->right);
    return(tree);
}

void DelTree(BineTree *tree) {
    if(tree!=NULL) {
    DelTree(tree->left);
    DelTree(tree->right);
    delete tree;
}
}


int main() {
    int size;
    cin >> size;
    BineTree *Tree= nullptr;
    int * Array = new int[size];

    for (int i = 0; i < size; ++i) {
        cin >> Array[i];
    }

    for (int i = size-1; i >= 0; i--) {
        Tree=AddNode(Array[i],Tree);
    }

    RightTreePrint(Tree);

    return 0;
}

