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
		cout << "1. ����, 2. ����, 3. ã��, 4. ���� : ";
		cin >> input;
		switch (input)
		{
		case 1:
			cout << "�Է��� �� : ";
			cin >> input;
			a.insert(input);
			break;
		case 2:
			cout << "������ �� : ";
			cin >> input;
			a.remove(input);
			break;
		case 3:
			cout << " ã�� �� : ";
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