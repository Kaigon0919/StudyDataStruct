#include "MyStack.h"

MyStack::MyStack(int size) : tos(-1), size(size)
{
	arr = new int[size];
}

bool MyStack::isEmpty() const
{
	if (tos < 0)
		return true;
	else
		return false;
}

bool MyStack::isFull() const
{
	if (tos >= size - 1)
		return true;
	else
		return false;
}

void MyStack::Push(int data)
{
	if (isFull())
		return;
	arr[++tos] = data;
}

int MyStack::Pop()
{
	if (isEmpty())
		return -1;
	int temp = arr[tos];
	arr[tos--] = -1;
	return temp;
}

int MyStack::Peek()
{
	if (isEmpty())
		return -1;
	return arr[tos];
}

MyStack::~MyStack()
{
	if (arr)
		delete[] arr;
}
