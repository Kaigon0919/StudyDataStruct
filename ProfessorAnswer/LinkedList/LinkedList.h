#ifndef LINKEDLIST2016ONEPOINT_H
#define LINKEDLIST2016ONEPOINT_H

struct CNode {
    float val;

    CNode *next;
};

class CLinkedList {
    CNode *head;
    CNode *tail;
public:
    CLinkedList();
    void add(float data);
    float remove(void);

    void show(void);
};

#endif