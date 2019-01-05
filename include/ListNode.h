#pragma once
#include<memory>

using namespace std;

class ListNode
{
private:
	int m_iData;
public:
	ListNode();
	~ListNode();
	ListNode(int Data);
	int getData();
	unique_ptr<ListNode> m_pNext;
	ListNode *m_pPrev = nullptr;
};
