//Node source
#include <iostream>
#include "Node.h"
 using namespace std;

int main(){
    Boxptr root=nullptr;
    int n = 15;
    int k = 5;
    for( int i= 0; i < n; i++){
      PushBox(INIT(i),root);
    }
    printStack(root);
    DeleteBox(k, root);
    printStack(root);
    return 0;
}

