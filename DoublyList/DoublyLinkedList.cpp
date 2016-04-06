#include "DoublyLinkedList.h"
#include<iostream>
using namespace std;
DoublyLinkedList::DoublyLinkedList() : head(NULL), arrlen(0)
{

}

void DoublyLinkedList::Add(int data)
{
	if (!head)
	{
		head = new DoublyLode;
		head->data = data;
		head->lLink = head;
		head->rLink = head;
		++arrlen;
		return;
	}
	DoublyLode * new_node = new DoublyLode;
	new_node->data = data;
	new_node->rLink = head->rLink;
	new_node->lLink = head;
	head->rLink->lLink = new_node;
	head->rLink = new_node;
	head = new_node;
	++arrlen;
}

void DoublyLinkedList::Remove()
{
	DoublyLode * temp = head;
	head->rLink->lLink = head->lLink;
	head->lLink->rLink = head->rLink;
	head = head->lLink;
	delete temp;
	--arrlen;
}

void DoublyLinkedList::ShowAll() const
{
	DoublyLode *cur = head->rLink;
	while (cur != head)
	{
		cout << cur->data << " ";
		cur = cur->rLink;
	}
	cout << cur->data << endl;
}

int DoublyLinkedList::GetLen() const
{
	return arrlen;
}

DoublyLinkedList::~DoublyLinkedList()
{
	DoublyLode * cur = head->rLink;
	DoublyLode * next = cur->rLink;
	int check = 0;
	while (cur != head)
	{
		delete cur;
		check++;
		cur = next;
		next = cur->rLink;
	}
	delete cur;
	check++;
	std::cout << "삭제한 노드 : " << check << std::endl;
}
