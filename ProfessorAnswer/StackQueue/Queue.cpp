#include"Queue.h"
Queue::Queue() { front = rear = -1; }
bool Queue::isFull() {
	return rear == MAX_SIZE - 1;
}
bool Queue::isEmpty() {
	return front == rear;
}

void Queue::add(int data) {

	if (!isFull()) n[++rear] = data;
}
int Queue::remove() {
	if (!isEmpty()) return n[++front];
	return -9999;
}
void Queue::display() {
	for (int i = front + 1; i <= rear; i++) {
		printf("[%d]", n[i]);
	}
	printf("\n");
}