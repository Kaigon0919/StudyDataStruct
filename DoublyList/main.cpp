#include"DoublyLinkedList.h"
using namespace std;

void main()
{
	DoublyLinkedList myList;
	myList.Add(30);
	myList.Add(40);
	myList.Add(50);
	myList.ShowAll();
	myList.Remove();
	myList.Remove();
	myList.ShowAll();
}