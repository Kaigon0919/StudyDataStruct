#include"MyQueue.h"
#include"MyStack.h"
#include<vector>
#include<iostream>
using namespace std;

void main()
{
	MyQueue que(3);
	MyStack stk(3);

	que.Enqueue(1);
	que.Enqueue(2);
	que.Enqueue(3);

	while (!que.isEmpty())
	{
		cout << que.Dequeue() << " ";
	}
	cout << endl;
	que.Enqueue(50);
	que.Enqueue(40);
	que.Enqueue(30);
	while (!que.isEmpty())
	{
		cout << que.Dequeue() << " ";
	}
	cout << endl;

	stk.Push(10);
	stk.Push(30);
	stk.Push(40);
	stk.Push(50);
	while (!stk.isEmpty())
	{
		cout << stk.Pop() << " ";
	}
	cout <<endl;
}