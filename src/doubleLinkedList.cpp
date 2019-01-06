#include "..\include\DoubleLinkedList.h"
#include<iostream>
#include<vector>

using namespace std;

DoubleLinkedList::DoubleLinkedList()
{
}


DoubleLinkedList::~DoubleLinkedList()
{
}


void DoubleLinkedList::addNode(const int Data,const int Index) {
}
void DoubleLinkedList::addNodeHead(const int Data) {
	display();
	cout << "Adding " << Data << " to Start of List..." << endl;
	ListNode *m_pCurr = nullptr;
	if (m_pHead.get() == nullptr) {
		m_pHead = make_unique<ListNode>(Data);
	}
	else if (m_pHead.get()->m_pNext.get() == nullptr) {
		m_pCurr = m_pHead.get();
		int iHeldData = m_pCurr->getData();
		m_pHead = make_unique<ListNode>(Data);
		m_pHead.get()->m_pNext = make_unique<ListNode>(iHeldData);
		m_pCurr = m_pHead.get()->m_pNext.get();
		m_pCurr->m_pPrev = m_pHead.get();
		m_pTail = m_pCurr;
	}
	else {
		vector<int> v_iHeldData;
		m_pCurr = m_pHead.get();
		for (int i = 0; i < iListLength; i++) {
			v_iHeldData.push_back(m_pCurr->getData());
			cout << m_pCurr->getData() << endl;
			m_pCurr = m_pCurr->m_pNext.get();
		}
		m_pHead = make_unique<ListNode>(Data);
		m_pCurr = m_pHead.get();
		m_pHead.get()->m_pNext = make_unique<ListNode>(v_iHeldData[0]);
		m_pCurr = m_pHead.get()->m_pNext.get();
		m_pCurr->m_pPrev = m_pHead.get();
		m_pTail = m_pCurr;
		for (int i = 1; i < iListLength; i++) {
			m_pTail->m_pNext = make_unique<ListNode>(v_iHeldData[i]);
			m_pCurr = m_pTail->m_pNext.get();
			m_pCurr->m_pPrev = m_pTail;
			m_pTail = m_pCurr;
		}

	}
	iListLength++;
	display();
	cout << endl;
}
void DoubleLinkedList::addNodeTail(const int Data) {
	display();
	cout << "Adding " << Data << " to End of List..." << endl;
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
	display();
	ListNode *m_pCurr = nullptr;
	if (m_pHead.get() == nullptr) {
		cout << "Error: List is Empty" << endl << endl;
		return false;
	}
	m_pCurr = m_pHead.get();
	if (Index > iListLength) {
		cout << "Error: Invalid Index" << endl << endl;
		return false;
	}
	for (int i = 1; i < Index; i++) {
		m_pCurr = m_pCurr->m_pNext.get();
	}
	cout << "Removing Data : " << m_pCurr->getData() << "  |  Position : " << Index << endl;
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
bool DoubleLinkedList::removeNodeHead() {
	cout << "Removing Head..." << endl;
	return removeNode(1);
}
bool DoubleLinkedList::removeNodeTail() {
	cout << "Removing Tail..." << endl;
	return removeNode(getLength());
}


void DoubleLinkedList::display() {
	ListNode *m_pCurr = m_pHead.get();
	cout << "List ( ";
	while (m_pCurr != nullptr) {
		cout << m_pCurr->getData() << "  ";
		m_pCurr = m_pCurr->m_pNext.get();
	}
	cout << ") Current Length is " << getLength() << endl;
}


int DoubleLinkedList::getNode(const int Index) {
	ListNode *m_pCurr = nullptr;
	if (m_pHead.get() == nullptr) {
		cout << "Error: List is Empty" << endl << endl;
		return false;
	}
	m_pCurr = m_pHead.get();
	if (Index > iListLength) {
		cout << "Error: Invalid Index" << endl << endl;
		return false;
	}
	for (int i = 1; i < Index; i++) {
		m_pCurr = m_pCurr->m_pNext.get();
	}
	cout << "Returning Data Node...			Data : " << m_pCurr->getData() << "  |  Position : " << Index << endl << endl;
	return m_pCurr->getData();
}
int DoubleLinkedList::getNodeHead() {
	return getNode(1);
}
int DoubleLinkedList::getNodeTail() {
	return getNode(getLength());
}


int DoubleLinkedList::getLength() {
	ListNode *m_pCurr = m_pHead.get();
	int iLength = 0;
	while (m_pCurr != nullptr) {
		iLength++;
		m_pCurr = m_pCurr->m_pNext.get();
	}
	iListLength = iLength;
	return iListLength;
}


bool DoubleLinkedList::isEmpty() {
	if (m_pHead.get() == nullptr && getLength() == 0) {
		return true;
	}
	else {
		return false;
	}
}
