#include "..\include\DoubleLinkedList.h"
#include<iostream>

using namespace std;

DoubleLinkedList::DoubleLinkedList()
{
}


DoubleLinkedList::~DoubleLinkedList()
{
}

void DoubleLinkedList::addNode(const int Data) {
	cout << "Adding " << Data << " to List..." << endl;
	display();
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
	iListLength++;
	display();
	cout << endl;
}
bool DoubleLinkedList::removeNode(const int Index) {
	cout << "Removing Node number " << Index << " from the List..." << endl;
	display();
	ListNode *m_pCurr = nullptr;
	if (m_pHead.get() == nullptr) {
		cout << "Error: List is Empty" << endl << endl;
		return false;
	}
	m_pCurr = m_pHead.get();
	if (Index > iListLength) {
		cout << "Error: Invalid Index" << endl << endl;
	}
	for (int i = 1; i < Index; i++) {
		m_pCurr = m_pCurr->m_pNext.get();
	}
	if (m_pCurr->m_pPrev == nullptr) {//If Head
		if (m_pCurr->m_pNext == nullptr) {
			m_pHead = nullptr;
		}
		else {
			m_pHead = move(m_pCurr->m_pNext);
			m_pHead->m_pPrev = nullptr;
		}
	}
	else if (m_pCurr->m_pNext == nullptr) {//If Tail
		m_pTail = m_pCurr->m_pPrev;
		m_pTail->m_pNext.release();
		if (m_pTail == m_pHead.get()) {
			m_pTail = nullptr;
		}
	}
	else {
		m_pCurr->m_pNext->m_pPrev = m_pCurr->m_pPrev;
		m_pCurr->m_pPrev->m_pNext = move(m_pCurr->m_pNext);
	}
	display();
	cout << endl;
	iListLength--;
	return true;
}
void DoubleLinkedList::display() {
	ListNode *m_pCurr = m_pHead.get();
	cout << "List ( ";
	while (m_pCurr != nullptr) {
		cout << m_pCurr->getData() << "  ";
		m_pCurr = m_pCurr->m_pNext.get();
	}
	cout << ") Current Length is " << iListLength << endl;
}
