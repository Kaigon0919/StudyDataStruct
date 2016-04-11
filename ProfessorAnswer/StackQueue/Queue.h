#ifndef QUEUE_H
#define QUEUE_H
class Queue {
private:
    int n[MAX_SIZE];
    int front;
    int rear;
public:
    Queue();
    bool isEmpty();
    bool isFull();
    void add(int data);
    int remove();
    void display();
};
#endif