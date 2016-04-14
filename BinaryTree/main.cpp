#include<iostream>
using namespace std;
#include"BinaryTree.h"
void main()
{
	bool isExit = false;
	int input;
	BirnaryTree a;
	while (!isExit)
	{
		cout << "1. 삽입, 2. 삭제, 3. 찾기, 4. 종료 : ";
		cin >> input;
		switch (input)
		{
		case 1:
			cout << "입력할 값 : ";
			cin >> input;
			a.insert(input);
			break;
		case 2:
			cout << "삭제할 값 : ";
			cin >> input;
			a.remove(input);
			break;
		case 3:
			cout << " 찾을 값 : ";
			cin >> input;
			cout << a.search(input) << endl;
			break;
		case 4:
			isExit = true;
			break;
		default:
			break;
		}
	}
}