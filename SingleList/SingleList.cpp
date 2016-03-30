#include"SingleList.h"
SingleList::SingleList() : len(0) {}
void SingleList::Add(int num)
{
	if (!head)
	{
		head = new ListNode(num);
		tail = head;
	}
	else
	{
		tail->next = new ListNode(num);
		tail = tail->next;	
	}
	++len;
}
void SingleList::Add(int num, int pos)
{
	ListNode *before = NULL;
	
	if (!head)
	{
		head = new ListNode(num);
		tail = head;
	}
	else if(pos>=len)
	{
		tail->next = new ListNode(num);
		tail = tail->next;
	}
	else
	{
		cur = head;

		for (int i = 0; i < pos; ++i)
		{
			before = cur;
			cur = cur->next;
		}
		before->next = new ListNode(num);
		before->next->next = cur;
	}
	++len;
}
int SingleList::Search(int pos)
{
	if (pos >= len)
	{
		cout << "�ش� �ε������� Node�� �����ϴ�. ����Ʈ�� ���� :" << len << endl;
	}
	cur = head;
	for (int i = 0; i < pos; ++i)
	{
		cur = cur->next;
	}
	return cur->data;
}
void SingleList::Delete(int pos)
{
	ListNode* before =NULL;
	cur = head;
	if (pos >= len || pos<0)
	{
		cout << "�ش� �ε������� Node�� �����ϴ�. ����Ʈ�� ���� :"<<len << endl;
		return;
	}
	if (pos <= 0)
	{
		head = head->next;
		delete cur;
		--len;
		return;
	}
	for (int i = 0; i < pos; ++i)
	{
		before = cur;
		cur = cur->next;
	}
	before->next = cur->next;
	delete cur;
	--len;

}
int SingleList::Length() const
{
	return len;
}
SingleList::~SingleList()
{
	ListNode * next;
	if (!head)
		return;
	cur = head;
	
	int chack = 0;
	while (cur != NULL)
	{
		next = cur->next;
		delete cur;
		cur = next;
		chack++;
	}
	cout <<"�Ҹ��� Delete Ƚ�� : "<< chack << ", ����Ʈ ���� :" << len << endl;
}