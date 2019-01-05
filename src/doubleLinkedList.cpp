#include "doubleLinkedList.h"
#include<memory>
#include<iostream>

void DoubleLinkedList::addNode(const int Data) {
	display();
	cout << "Adding " << Data << " to List..." << endl;
	ListNode *m_pCurr = nullptr;
	if (m_pHead.get() == nullptr) {
		m_pHead = make_unique<ListNode>(Data);
	}
	else if (m_pHead.get()->m_pNext.get() == nullptr) {
		m_pHead.get()->m_pNext = make_unique<ListNode>(Data);
		m_pCurr = m_pHead.get()->m_pNext.get();
		m_pCurr->m_pPrev = m_pHead.get();
		m_pTail = m_pCurr;
	}
	else {
		m_pTail->m_pNext = make_unique<ListNode>(Data);
		m_pCurr = m_pTail->m_pNext.get();
		m_pCurr->m_pPrev = m_pTail;
		m_pTail = m_pCurr;
	}
	display();
}

bool DoubleLinkedList::removeNode(const int Data) {
	return false;
}

void DoubleLinkedList::display() {
	ListNode *m_pCurr = m_pHead.get();
	cout << "List ( ";
	while (m_pCurr != nullptr) {
		cout << m_pCurr->getData() << "  ";
		m_pCurr = m_pCurr->m_pNext.get();
	}
	cout << ")" << endl;
}


