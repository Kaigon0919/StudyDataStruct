#include <stdio.h>
#include "LinkedList.h"

CLinkedList::CLinkedList() {
    head = NULL;
    tail = NULL;
}

void CLinkedList::add(float data) {
    // 1. create a node
    CNode *n = new CNode;
    n->next = NULL;
    n->val = data;

    if(!head) { // if this is the first node
        head = n;
        tail = n;
        return;
    }

    // 3. add the new node to the tail
    tail->next = n; 
    tail = n;
}
float CLinkedList::remove(void) {
    float retTemp;
    if(!head) return -99999999;
    if(!(head->next)) {
        retTemp = head->val; 
        delete head;
        head = tail = NULL;
        return retTemp;
    }
    // 1. find the node just before the tail
    CNode *tailPrev = head;
    CNode *curTail = tailPrev->next;
    while(curTail->next) {
        tailPrev = curTail;
        curTail = curTail->next;        
    }
    // 2. delete tail
    retTemp = tail->val;
    delete tail;
    tailPrev->next = NULL;
    tail = tailPrev;
    return retTemp;

}

void CLinkedList::show(void){
    CNode *n = head;
    while(n) {
        printf("[%f]", n->val);
        n = n->next;
    }

}