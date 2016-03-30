#pragma once
#ifndef __SINGLE_LIST_H__
#define __SINGLE_LIST_H__

#include<iostream>
using namespace std;

struct ListNode
{
	int data;
	ListNode * next;
	ListNode(int data, ListNode * next = NULL) : data(data),next(next){}
};
class SingleList
{
private:
	ListNode * head;
	ListNode * tail;
	ListNode * cur;
	int len;
	
public:
	SingleList();
	void Add(int num);
	void Add(int num, int pos);
	int Search(int pos);
	void Delete(int pos);
	int Length()const;
	~SingleList();
};

#endif