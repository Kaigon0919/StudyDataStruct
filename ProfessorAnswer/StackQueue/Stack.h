#ifndef STACK_H
#define STACK_H
class Stack
{
private:
    int n[MAX_SIZE];
    int top;
public:
    Stack();
    bool isEmpty();
    bool isFull();
    void push(int data);
    int pop();
    void display();
};
#endif