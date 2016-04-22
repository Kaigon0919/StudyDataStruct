#pragma once
#ifndef __PRIORITYQUEUE_H_
#define __PRIORITYQUEUE_H_
template <class T>
struct HeapNode
{
	int pr;
	int data;
};

template<class T>
class PriorityQueue
{
private:
	HeapNode<T> * arr;
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
	void Insert(T data, int pr);
	T Delete();
	~PriorityQueue();
};

template<class T>
int PriorityQueue<T>::GetParentIDX(int idx)
{
	return idx / 2;
}
template<class T>
int PriorityQueue<T>::GetLChildeIDX(int idx)
{
	return idx * 2;
}
template<class T>
int PriorityQueue<T>::GetRChildeIDX(int idx)
{
	return idx * 2 + 1;
}
template<class T>
int PriorityQueue<T>::GetHiPriChildeIDX(int idx)
{
	if (GetLChildeIDX(idx) > numofData)
	{
		return 0;
	}
	else if (GetLChildeIDX(idx) == numofData)
		return GetLChildeIDX(idx);
	else
	{
		if (arr[GetLChildeIDX(idx)].pr > arr[GetRChildeIDX(idx)].pr)
			return GetRChildeIDX(idx);
		else
			return GetLChildeIDX(idx);
	}
}
template<class T>
PriorityQueue<T>::PriorityQueue(int len)
{
	arr = new HeapNode<T>[len + 1];
}
template<class T>
bool PriorityQueue<T>::isEmpty()
{
	return numofData == 0;
}
template<class T>
void PriorityQueue<T>::Insert(T data, int pr)
{
	int idx = numofData + 1;
	HeapNode<T> newNode = { pr,data };

	while (idx != 1)
	{
		if (pr < arr[GetParentIDX(idx)].pr)
		{
			arr[idx] = arr[GetParentIDX(idx)];
			idx = GetParentIDX(idx);
		}
		else
			break;
	}
	arr[idx] = newNode;
	numofData += 1;
}
template<class T>
T PriorityQueue<T>::Delete()
{
	T retData = arr[1].data;
	HeapNode<T> lastNode = arr[numofData];

	int parentIdx = 1;
	int childIdx;

	while (childIdx = GetHiPriChildeIDX(parentIdx))
	{
		if (lastNode.pr <= arr[childIdx].pr)
			break;
		arr[parentIdx] = arr[childIdx];
		parentIdx = childIdx;
	}
	arr[parentIdx] = lastNode;
	numofData -= 1;
	return retData;
}

template <class T>
PriorityQueue<T>::~PriorityQueue()
{
	if (arr)
		delete[]arr;
}
#endif
