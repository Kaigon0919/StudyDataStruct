#pragma once
#ifndef __PRIORITYQUEUE_H_
#define __PRIORITYQUEUE_H_
struct HeapNode
{
	int pr;
	int data;
};

class PriorityQueue
{
private:
	HeapNode * arr;
	int arrlen;
	int numofData;
private:
	int GetParentIDX(int idx);
	int GetLChildeIDX(int idx);
	int GetRChildeIDX(int idx);
	int GetHiPriChildeIDX(int idx);

public:
	PriorityQueue(int len = 4);
	bool isEmpty();
	void Insert(int data, int pr);
	int Delete();
	~PriorityQueue();
};

#endif