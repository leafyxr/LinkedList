#pragma once
#include<memory>
#include"ListNode.h"

class DoubleLinkedList
{
private:
	std::unique_ptr<ListNode> m_pHead;
	ListNode * m_pTail;
	int iListLength = 0;
public:
	DoubleLinkedList();
	~DoubleLinkedList();
	void addNode(const int Data);
	bool removeNode(const int Data);
	void display();
};
