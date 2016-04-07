#pragma once
#ifndef __STATCK_H__
#define __STATCK_H__
class MyStack
{
private:
	int tos;
	int size;
	int * arr;
public:
	MyStack(int size = 10);
	bool isEmpty()const;
	bool isFull()const;

	void Push(int data);
	int Pop();
	int Peek();
	~MyStack();
};

#endif