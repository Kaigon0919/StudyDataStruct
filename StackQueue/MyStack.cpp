#include "MyStack.h"

MyStack::MyStack(int size) : tos(-1), size(size)
{
	arr = new int[size];
}

bool MyStack::isEmpty() const
{
	return tos < 0;
}

bool MyStack::isFull() const
{
	return tos >= (size)-1;
}

void MyStack::Push(int data)
{
	if (isFull())	return;
	else { arr[++tos] = data; }
}

int MyStack::Pop()
{
	return isEmpty() ? -1 : arr[tos--];
}

int MyStack::Peek()
{
	return isEmpty() ? -1 : arr[tos];
}

MyStack::~MyStack()
{
	if (arr)
		delete[] arr;
}
