#ifndef __DOUBLYLINKEDLIST_H__
#define __DOUBLYLINKEDLIST_H__

struct DoublyLode
{
	int data;
	DoublyLode * lLink;
	DoublyLode * rLink;
};

class DoublyLinkedList
{
private:
	DoublyLode * head;
	int arrlen;
public:
	DoublyLinkedList();
	void Add(int data);
	void Remove();
	void ShowAll()const;
	int GetLen()const;
	~DoublyLinkedList();
};

#endif

