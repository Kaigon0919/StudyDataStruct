#include "DoublyLinkedList.h"
#include<iostream>
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
	--arrlen;
}

void DoublyLinkedList::Remove(int pos)
{
	--arrlen;
}

int DoublyLinkedList::GetLen() const
{
	return 0;
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
