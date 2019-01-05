#pragma once
#include<memory>
#include"ListNode.h"

using namespace std;

class DoubleLinkedList
{
private:
	unique_ptr<ListNode> m_pHead;
	ListNode * m_pTail;
public:
	DoubleLinkedList();
	~DoubleLinkedList();
	void addNode(const int Data);
	bool removeNode(const int Data);
	void display();
};

