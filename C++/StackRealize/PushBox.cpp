#include "Node.h"

void PushBox(Boxptr el, Boxptr& Top){
    el->prev=Top;
    Top=el;
}
