#include"MyQueue.h"
#include"MyStack.h"
#include<iostream>
using namespace std;
void main()
{
	MyQueue que(100);
	MyStack stk(100);

	que.Enqueue(1);
	cout << "Peek : " << que.Peek() << endl;
	que.Enqueue(2);
	que.Enqueue(3);
	que.Enqueue(5);
	while (!que.isEmpty())
	{
		cout << que.Dequeue() << " ";
	}
	cout << endl;

	stk.Push(10);
	stk.Push(20);
	stk.Push(30);
	stk.Push(40);
	while (!stk.isEmpty())
	{
		cout << stk.Pop() << " ";
	}
	cout << endl;
}