#include "Node.h"

Boxptr INIT(int number){
    Boxptr NBox= new Box;
    NBox->prev=nullptr;
    NBox->num=number;
    return NBox;
}
