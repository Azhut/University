#include "Node.h"
void DeleteBox(int idx, Boxptr& root) {
    Boxptr cur, pr;
    pr = cur = root;
    if (idx == root->num) {
        root = root->prev;
    }
    else {
        cur = pr->prev;
        while (cur != nullptr) {
            if (idx == cur->num) {
                pr->prev = cur->prev;
                break;
            }
            pr = cur;
            cur = cur->prev;
        }
        delete cur;
    }
}