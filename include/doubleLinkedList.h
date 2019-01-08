#pragma once
#include<memory>
#include<iostream>
#include<vector>
#include"ListNode.h"

using namespace std;

/*! \file DoubleLinkedList.h
* \brief Header file for DoubleLinkedList Class
*
*/

/*! \class Double Linked List
* \brief A double linked list data structure using Integers
*
*/
template<typename T>
class DoubleLinkedList
{
private:
	unique_ptr<ListNode<T>> m_pHead;//!< Pointer to Head
	ListNode<T> * m_pTail;//!< Pointer to Tail
	int iListLength = 0;//!< Length of list
public:

	//! Constructor
	DoubleLinkedList(){}

	//! Deconstructor
	~DoubleLinkedList(){}

	//! Adds a Node at a specified point 
	/*!
	\param Data  -  Data contained in new node.
	\param Index  -  Position in list.*/
	void addNode(const T Data, const int Index) {
	}

	//! Adds a Node at the Head
	/*!
	\param Data  -  Data contained in new node..*/
	void addNodeHead(const T Data) {
		display();
		cout << "Adding " << Data << " to Start of List..." << endl;
		ListNode<T> *m_pCurr = nullptr;
		if (m_pHead.get() == nullptr) {
			m_pHead = make_unique<ListNode<T>>(Data);
		}
		else if (m_pHead.get()->m_pNext.get() == nullptr) {
			m_pCurr = m_pHead.get();
			int iHeldData = m_pCurr->getData();
			m_pHead = make_unique<ListNode<T>>(Data);
			m_pHead.get()->m_pNext = make_unique<ListNode<T>>(iHeldData);
			m_pCurr = m_pHead.get()->m_pNext.get();
			m_pCurr->m_pPrev = m_pHead.get();
			m_pTail = m_pCurr;
		}
		else {
			vector<T> v_tHeldData;
			m_pCurr = m_pHead.get();
			for (int i = 0; i < iListLength; i++) {
				v_iHeldData.push_back(m_pCurr->getData());
				m_pCurr = m_pCurr->m_pNext.get();
			}
			m_pHead = make_unique<ListNode<T>>(Data);
			m_pCurr = m_pHead.get();
			m_pHead.get()->m_pNext = make_unique<ListNode<T>>(v_tHeldData[0]);
			m_pCurr = m_pHead.get()->m_pNext.get();
			m_pCurr->m_pPrev = m_pHead.get();
			m_pTail = m_pCurr;
			for (int i = 1; i < iListLength; i++) {
				m_pTail->m_pNext = make_unique<ListNode<T>>(v_tHeldData[i]);
				m_pCurr = m_pTail->m_pNext.get();
				m_pCurr->m_pPrev = m_pTail;
				m_pTail = m_pCurr;
			}

		}
		iListLength++;
		display();
		cout << endl;
	}

	//! Adds a Node at the Tail 
	/*!
	\param Data  -  Data contained in new node.*/
	void addNodeTail(const T Data) {
		display();
		cout << "Adding " << Data << " to End of List..." << endl;
		ListNode<T> *m_pCurr = nullptr;
		if (m_pHead.get() == nullptr) {
			m_pHead = make_unique<ListNode<T>>(Data);
		}
		else if (m_pHead.get()->m_pNext.get() == nullptr) {
			m_pHead.get()->m_pNext = make_unique<ListNode<T>>(Data);
			m_pCurr = m_pHead.get()->m_pNext.get();
			m_pCurr->m_pPrev = m_pHead.get();
			m_pTail = m_pCurr;
		}
		else {
			m_pTail->m_pNext = make_unique<ListNode<T>>(Data);
			m_pCurr = m_pTail->m_pNext.get();
			m_pCurr->m_pPrev = m_pTail;
			m_pTail = m_pCurr;
		}
		iListLength++;
		display();
		cout << endl;
	}

	//! Removes a Node from a specified point 
	/*!
	\param Index  -  Position in list.*/
	bool removeNode(const int Index) {
		display();
		ListNode<T> *m_pCurr = nullptr;
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

	//! Removes the current Head Node
	bool removeNodeHead() {
		cout << "Removing Head..." << endl;
		return removeNode(1);
	}

	//! Removes the current Tail Node
	bool removeNodeTail() {
		cout << "Removing Tail..." << endl;
		return removeNode(getLength());
	}

	//! Displays Current List
	void display() {
		ListNode<T> *m_pCurr = m_pHead.get();
		cout << "List ( ";
		while (m_pCurr != nullptr) {
			cout << m_pCurr->getData() << "  ";
			m_pCurr = m_pCurr->m_pNext.get();
		}
		cout << ") Current Length is " << getLength() << endl;
	}

	//! Returns a Node from a specified point 
	/*!
	\param Index  -  Position in list.*/
	T getNode(const int Index) {
		ListNode<T> *m_pCurr = nullptr;
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

	//! Returns the current Head Node
	T getNodeHead() {
		return getNode(1);
	}

	//! Returns the current Tail Node
	T getNodeTail() {
		return getNode(getLength());
	}

	//! Checks and returns current Length
	int getLength() {
		ListNode<T> *m_pCurr = m_pHead.get();
		int iLength = 0;
		while (m_pCurr != nullptr) {
			iLength++;
			m_pCurr = m_pCurr->m_pNext.get();
		}
		iListLength = iLength;
		return iListLength;
	}

	//! Checks if list is empty
	bool isEmpty() {
		if (m_pHead.get() == nullptr && getLength() == 0) {
			return true;
		}
		else {
			return false;
		}
	}
};
