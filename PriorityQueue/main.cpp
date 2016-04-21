#include"PriorityQueue.h"
#include<iostream>
using namespace std;

void main()
{
	PriorityQueue qq(4);
	qq.Insert(4, 3);
	qq.Insert(5, 2);
	qq.Insert(7, 3);
	qq.Insert(3999, 1);
	cout << qq.Delete() << endl;

	cout << qq.Delete() << endl;

	cout << qq.Delete() << endl;
}