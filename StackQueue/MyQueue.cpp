#include "MyQueue.h"
#include<iostream>
using namespace std;

MyQueue::MyQueue(int size) : front(0),rear(0),size(size+1)
{
	arr = new int[size+1];
}

bool MyQueue::isEmpty() const
{
	return front == rear;
}

bool MyQueue::isFull() const
{
	return front%size == (rear + 1) % size;
}

void MyQueue::Enqueue(int data)
{
	if (isFull())
		return;
	arr[(++rear)%size] = data;
}

int MyQueue::Dequeue()
{
	return isEmpty() ? -1 : arr[(++front)%size];
}

int MyQueue::Peek()
{
	return isEmpty() ? -1 : arr[front + 1];
}

MyQueue::~MyQueue()
{
	if(arr)
		delete[]arr;
}
