#include "PriorityQueue.h"

int PriorityQueue::GetParentIDX(int idx)
{

	return idx/2;
}

int PriorityQueue::GetLChildeIDX(int idx)
{
	return idx*2;
}

int PriorityQueue::GetRChildeIDX(int idx)
{
	return idx*2+1;
}

int PriorityQueue::GetHiPriChildeIDX(int idx)
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

PriorityQueue::PriorityQueue(int len)
{
	arr = new HeapNode[len+1];
}

bool PriorityQueue::isEmpty()
{
	return numofData == 0;
}

void PriorityQueue::Insert(int data, int pr)
{
	int idx = numofData + 1;
	HeapNode newNode = { pr,data };

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

int PriorityQueue::Delete()
{
	int retData = arr[1].data;
	HeapNode lastNode = arr[numofData];

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

PriorityQueue::~PriorityQueue()
{
	if (arr)
		delete[]arr;
}
