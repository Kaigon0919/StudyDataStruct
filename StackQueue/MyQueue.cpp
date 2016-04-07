#include "MyQueue.h"

MyQueue::MyQueue(int size) : front(-1),rear(-1),size(size)
{
	arr = new int[size];
}

bool MyQueue::isEmpty() const
{
	if (front == rear)
		return true;
	else
		return false;
}

bool MyQueue::isFull() const
{
	if (front%size == (rear + 1) % size)
		return true;
	else
		return false;
}

void MyQueue::Enqueue(int data)
{
	if (isFull())
		return;
	arr[++rear] = data;
}

int MyQueue::Dequeue()
{
	if (isEmpty())
		return -1;
	int temp = arr[++front];
	arr[front] = -1;
	return temp;
}

int MyQueue::Peek()
{
	if (isEmpty())
		return -1;
	return arr[front+1];
}

MyQueue::~MyQueue()
{
	if(arr)
		delete[]arr;
}
