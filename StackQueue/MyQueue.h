#pragma once
#ifndef __QUEUE_H__
#define __QUEUE_H__

class MyQueue
{
private:
	int front, rear;
	int size;
	int * arr;
public:
	MyQueue(int size = 4);
	bool isEmpty() const;
	bool isFull() const;

	void Enqueue(int data);
	int Dequeue();
	int Peek();
	~MyQueue();
};
#endif