#include "Stack.h"

Stack::Stack() { top = -1; }

bool Stack::isEmpty() {
    return top==-1;
}
bool Stack::isFull() {
    return top == MAX_SIZE-1;
}

void Stack::push(int data) {
    if(!isFull()) n[++top] = data;
    else { printf("Stack Full!\n"); return; }
}

int Stack::pop() {  
    return isEmpty()?-999999:n[top--];
}

void Stack::display() {
    for(int i=0;i<=top;i++) {
        printf("[%d]", n[i]);
    }
    printf("\n");
}