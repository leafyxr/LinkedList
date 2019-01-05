#pragma once
#include<memory>

class ListNode
{
private:
	int m_iData;
public:
	ListNode();
	~ListNode();
	ListNode(int Data);
	int getData();
	std::unique_ptr<ListNode> m_pNext;
	ListNode *m_pPrev = nullptr;
};
