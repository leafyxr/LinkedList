#pragma once
#define _CRTDBG_MAP_ALLOC  
#include<memory>
#include<iostream>
#include<vector>
#include"ListNode.h"

using namespace std;

/*! \file DoubleLinkedList.h
* \brief Header file for DoubleLinkedList Class
*
*/

/*! \class DoubleLinkedList
* \brief A double linked list data structure
*
*/

template<typename T>
class DoubleLinkedList
{
private:
	unique_ptr<ListNode<T>> m_pHead;//!< Pointer to Head
	ListNode<T> * m_pTail;//!< Pointer to Tail
	ListNode<T> * m_pSelected;//!< Current Pointer Selected
	int iSelectedIndex = 0;
	int iListLength = 0;//!< Length of list
public:

	//! Constructor
	DoubleLinkedList(){}

	//! Deconstructor
	~DoubleLinkedList(){}

	//! Adds a Node after a specified point 
	/*!
	\param Data  -  Data contained in new node.
	\param Index  -  Position in list.*/
	void addNodeAfter(const T Data, const int Index) {
		ListNode<T> *m_pCurr = m_pHead.get(); //!< Sets current Node as Head
		if (Index <= 0) //!< Checks if Index is equal or less than 0, if so add node to head instead
		{ 
			cout << "Index out of range, Adding to head instead" << endl << endl;
			addNodeHead(Data);
			return;
		}
		if (Index > iListLength) {//!< Checks if Index is after end of list, if so add node to tail instead
			cout << "Index after last node, Adding to tail instead" << endl << endl;
			addNodeTail(Data);
			return;
		}
		display();//!< Displays List before Adding
		for (int i = 1; i < Index; i++) { //!< Gets the start Node
			m_pCurr = m_pCurr->m_pNext.get();
		}
		cout << "Adding " << Data << " Between Nodes # " << Index << " & # " << Index + 1 << endl;
		if (m_pHead.get() == nullptr) {//!< If the head node is empty create a new one
			m_pHead = make_unique<ListNode<T>>(Data);
		}
		else if (m_pHead.get()->m_pNext.get() == nullptr) {//!< If the second node is empty
			if (Index <= 1) {
				addNodeHead(Data);//!< Creates New Head
			}
			else {
				addNodeTail(Data);//!< Creates New Tail
			}
		}
		else {
			vector<T> v_tHeldData;//!< Holds Node Data
			ListNode<T> *m_pCurr2 = nullptr;
			m_pCurr2 = m_pCurr;
			for (int i = Index; i < iListLength; i++) { //!< Gets the data for all remaining nodes in the list
				v_tHeldData.push_back(m_pCurr2->getData()); //!< Adds Node Data to Vector
				m_pCurr2 = m_pCurr2->m_pNext.get(); //!< Gets next Node
			}
			m_pCurr->m_pNext = make_unique<ListNode<T>>(Data); //!< Adds new Node
			m_pCurr2 = m_pCurr->m_pNext.get(); //!< Selects Next Node
			m_pCurr2->m_pPrev = m_pCurr;//!< Sets Previous Node
			m_pTail = m_pCurr2; //!< Sets New Tail
			for (int i = 0; i < v_tHeldData.size(); i++) { //!< Adds all held data back to list.
				m_pTail->m_pNext = make_unique<ListNode<T>>(v_tHeldData[i]); //!< Creates new node
				m_pCurr2 = m_pTail->m_pNext.get(); //!< Selects Next Node
				m_pCurr2->m_pPrev = m_pTail; //!< Sets previous Node
				m_pTail = m_pCurr2; //!< Sets New Tail
			}
		}
		iListLength++;//!< Increases Length of list
		display();//!< Displays list after add
		cout << endl;//!< Gap
	}

	//! Adds a Node after the selected Node 
	/*!
	\param Data  -  Data contained in new node.*/
	void addNodeAfterSelected(const T Data) {
		checkSelectedNodeIndex();
		if (m_pSelected == nullptr) { //!< Checks if a node is selected
			cout << "No nodes selected" << endl << endl;
			return;
		}
		else addNodeAfter(Data, iSelectedIndex);
	}

	//! Adds a Node after a specified point 
	/*!
	\param Data  -  Data contained in new node.
	\param Index  -  Position in list.*/
	void addNodeBefore(const T Data, const int Index) {
		addNodeAfter(Data, Index - 1);
	}

	//! Adds a Node before the selected Node 
	/*!
	\param Data  -  Data contained in new node.*/
	void addNodeBeforeSelected(const T Data) {
		checkSelectedNodeIndex();
		if (m_pSelected == nullptr) {//!< Checks if a node is selected
			cout << "No nodes selected" << endl << endl;
			return;
		}
		else addNodeBefore(Data, iSelectedIndex);
	}

	//! Adds a Node at the Head
	/*!
	\param Data  -  Data contained in new node..*/
	void addNodeHead(const T Data) {
		display(); //!< Displays list before Adding
		cout << "Adding " << Data << " to Start of List..." << endl;
		ListNode<T> *m_pCurr = nullptr;
		if (m_pHead.get() == nullptr) { //!< If No Head
			m_pHead = make_unique<ListNode<T>>(Data); //!< Create Head
		}
		else if (m_pHead.get()->m_pNext.get() == nullptr) { //!< If no second Node
			m_pCurr = m_pHead.get(); 
			int iHeldData = m_pCurr->getData(); //!< Hold Data for the head
			m_pHead = make_unique<ListNode<T>>(Data); //!< Make new head with new data
			m_pHead.get()->m_pNext = make_unique<ListNode<T>>(iHeldData); //!< Creates second node with held data
			m_pCurr = m_pHead.get()->m_pNext.get();//!< selects next node
			m_pCurr->m_pPrev = m_pHead.get();//!< sets previous node
			m_pTail = m_pCurr;//!<sets new tail
		}
		else {
			vector<T> v_tHeldData; //!<Hold all list data
			m_pCurr = m_pHead.get(); //!<set current as head
			for (int i = 0; i < iListLength; i++) { //!< for every item in the list
				v_tHeldData.push_back(m_pCurr->getData());//!< add data to vector
				m_pCurr = m_pCurr->m_pNext.get(); //!< get next node
			}
			m_pHead = make_unique<ListNode<T>>(Data); //!< create new head with new datap
			m_pCurr = m_pHead.get(); 
			m_pHead.get()->m_pNext = make_unique<ListNode<T>>(v_tHeldData[0]); //!<create second Node
			m_pCurr = m_pHead.get()->m_pNext.get(); //!Select second node
			m_pCurr->m_pPrev = m_pHead.get(); //!< set previous Node
			m_pTail = m_pCurr; //!<set new tail
			for (int i = 1; i < iListLength; i++) { //!<add all remaining held data back into list
				m_pTail->m_pNext = make_unique<ListNode<T>>(v_tHeldData[i]);//!<set new node
				m_pCurr = m_pTail->m_pNext.get();//!< select new node
				m_pCurr->m_pPrev = m_pTail; //!< set previous node
				m_pTail = m_pCurr; //!< set new tail
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
		display();//!< Displays list before add
		cout << "Adding " << Data << " to End of List..." << endl;
		ListNode<T> *m_pCurr = nullptr;
		if (m_pHead.get() == nullptr) {//!<If no head
			m_pHead = make_unique<ListNode<T>>(Data);
		}
		else if (m_pHead.get()->m_pNext.get() == nullptr) {//!<if no second Node
			m_pHead.get()->m_pNext = make_unique<ListNode<T>>(Data);//!<Create new node after head
			m_pCurr = m_pHead.get()->m_pNext.get();//!<go to new node
			m_pCurr->m_pPrev = m_pHead.get();//!<set previous node
			m_pTail = m_pCurr;//!<set new tail
		}
		else {
			m_pTail->m_pNext = make_unique<ListNode<T>>(Data);//!<Create new node after current Tail
			m_pCurr = m_pTail->m_pNext.get();//!<Select next node
			m_pCurr->m_pPrev = m_pTail;//!<set previous node
			m_pTail = m_pCurr;//!<set new tail
		}
		iListLength++;//!<Increase list length
		display();//!<Show list after adding
		cout << endl;
	}

	//! Removes a Node from a specified point 
	/*!
	\param Index  -  Position in list.*/
	bool removeNode(const int Index) {
		display();//!<Display list before removing
		ListNode<T> *m_pCurr = nullptr;
		if (m_pHead.get() == nullptr) {//!<if list is empty
			cout << "Error: List is Empty" << endl << endl;
			return false;
		}
		m_pCurr = m_pHead.get();
		if (Index > iListLength || Index <= 0) {//!<If index out of range
			cout << "Error: Invalid Index" << endl << endl;
			return false;
		}
		for (int i = 1; i < Index; i++) {//!<get node to be removed
			m_pCurr = m_pCurr->m_pNext.get();
		}
		cout << "Removing Data : " << m_pCurr->getData() << "  |  Position : " << Index << endl;
		if (m_pCurr->m_pPrev == nullptr) {//!<If Head
			if (m_pCurr->m_pNext == nullptr) {//!<If only head in list
				m_pHead = nullptr;//!<Delete Head
			}
			else {
				m_pHead = move(m_pCurr->m_pNext);//!<Set Head as next node
				m_pHead->m_pPrev = nullptr;//!<Set previous node as null
			}
		}
		else if (m_pCurr->m_pNext == nullptr) {//!<If Tail
			m_pTail = m_pCurr->m_pPrev;//!<Set Tail as previous node
			m_pTail->m_pNext.release();//!<Release the new tails next node
			if (m_pTail == m_pHead.get()) {//!<if tail is same as head
				m_pTail = nullptr;//!<delete tail
			}
		}
		else {
			m_pCurr->m_pNext->m_pPrev = m_pCurr->m_pPrev;//!<set the next nodes previous node to be the same as the current nodes previous node
			m_pCurr->m_pPrev->m_pNext = move(m_pCurr->m_pNext);//!<Set the previous nodes next node as the current nodes next node
		}
		display();//!<Show list after delete
		cout << endl;
		iListLength--;//!<Decrease length of list
		return true;
	}

	bool removeSelectedNode() {
		checkSelectedNodeIndex();
		if (m_pSelected == nullptr) {//!<Check if a node is selected
			return false;
		}
		cout << "Removing Selected Node..." << endl;
		return removeNode(iSelectedIndex);//!<Remove selected node
	}

	//! Removes the current Head Node
	bool removeNodeHead() {
		cout << "Removing Head..." << endl;
		return removeNode(1);//!<Remove first node
	}

	//! Removes the current Tail Node
	bool removeNodeTail() {
		cout << "Removing Tail..." << endl;
		return removeNode(getLength());//!<Remove last node
	}

	//! Displays Current List
	void display() {
		ListNode<T> *m_pCurr = m_pHead.get();//!<Set current node as head
		cout << "List ( ";
		while (m_pCurr != nullptr) {//!<repeats for every node in the list
			cout << m_pCurr->getData() << "  "; //!<get data for current node 
			m_pCurr = m_pCurr->m_pNext.get();//!<get next node
		}
		cout << ") Current Length is " << getLength() << endl;
	}

	//! Returns a Nodes Data  from a specified point 
	/*!
	\param Index  -  Position in list.*/
	T getNodeData(const int Index) {
		ListNode<T> *m_pCurr = nullptr;
		if (m_pHead.get() == nullptr) {//!<If Empty
			cout << "Error: List is Empty" << endl << endl;
			return false;
		}
		m_pCurr = m_pHead.get();
		if (Index > iListLength || Index <= 0) {//!<If index out of range
			cout << "Error: Invalid Index" << endl << endl;
			return false;
		}
		for (int i = 1; i < Index; i++) {//!<go to node
			m_pCurr = m_pCurr->m_pNext.get();
		}
		cout << "Returning Data Node...			Data : " << m_pCurr->getData() << "  |  Position : " << Index << endl << endl;//!<Print data to console
		return m_pCurr->getData();//!<return data value
	}

	//! Returns the current Head Nodes Data
	T getHeadData() {
		return getNodeData(1);//!<Get data of first node
	}

	//! Returns the current Tail Nodes Data
	T getTailData() {
		return getNodeData(getLength());//!<Get data of last node
	}

	//! Returns the Selected Nodes Data
	T getSelectedNodeData() {
		checkSelectedNodeIndex();
		if (m_pSelected == nullptr) {//!<Check if a node is selected
			return NULL;
		}
		return m_pSelected->getData();//!<Return Held Data
	}

	//! Checks if node still in list, also updates the node index if incorrect
	bool checkSelectedNodeIndex() {
		int index = 1;
		if (m_pSelected == nullptr) {//!<Check if a node is selected
			return false;
		}
		ListNode<T> *m_pCurr = m_pHead.get();
		while (m_pSelected != m_pCurr) {
			if (m_pCurr == nullptr) {
				cout << "Error: Selected Node does not exist" << endl << endl;
				m_pSelected = nullptr;
				iSelectedIndex = 0;
				return false;
			}
			index++;
			m_pCurr = m_pCurr->m_pNext.get();
		}
		if (index != iSelectedIndex) {
			iSelectedIndex = index;
			cout << "Updating Index..." << endl << endl;
		}
		return true;
	}

	//! Selects a specific Node
	/*!
	\param Index  -  Position in list.*/
	bool selectNode(const int Index) {
		if (m_pHead.get() == nullptr) {//!<Check if list is empty
			cout << "Error: List is Empty" << endl << endl;
			return false;
		}
		if (Index > iListLength || Index <= 0) {//!<If index out of range
			cout << "Error: Invalid Index" << endl << endl;
			return false;
		}
		m_pSelected = m_pHead.get();
		for (int i = 1; i < Index; i++) {//!<Get Node
			m_pSelected = m_pSelected->m_pNext.get();
		}
		iSelectedIndex = Index;//!<Set Selected node index
		cout << "Selected Node # " << iSelectedIndex << endl << endl;
		return true;
	}

	//! Selects the Head Node
	bool selectHead(){
		if (isEmpty()) {//!<Checks if list is empty
			return false;
		}
		cout << "Selecting Head..." << endl << endl;
		return selectNode(1);//!<Selects first node
	}

	//! Selects the Tail Node
	bool selectTail(){
		if (isEmpty() || m_pTail == nullptr) {//!<Checks if list is empty or no tail
			return false;
		}
		cout << "Selecting Tail..." << endl << endl;
		return selectNode(iListLength);//!<Gets last node
	}

	//! Selects the next node in the list
	bool scrollForwards() {
		checkSelectedNodeIndex();
		if (m_pSelected == nullptr) {//!<Check if a node is selected
			cout << "Error: No Node Selected" << endl << endl;
			return false;
		}
		else if (m_pSelected->m_pNext == nullptr) {//!<Check if next node is null
			cout << "Error: Next Node is Empty" << endl << endl;
			return false;
		}
		else {
			cout << "Next Node Selected" << endl << endl;
			m_pSelected = m_pSelected->m_pNext.get();//!<get next node
			iSelectedIndex++;//!<increase index
			return true;
		}
	}

	//! Selects the previous node in the list
	bool scrollBackwards() {
		checkSelectedNodeIndex();
		if (m_pSelected == nullptr) {//!<Check if list is empty
			cout << "Error: No Node Selected" << endl << endl;
			return false;
		}
		else if (m_pSelected->m_pPrev == nullptr) {//!<check if previous node is null
			cout << "Error: Previous Node is Empty" << endl << endl;
			return false;
		}
		else {
			cout << "Previous Node Selected" << endl << endl;
			m_pSelected = m_pSelected->m_pPrev;//!<get previous node
			iSelectedIndex--;//!<decrease index
			return true;
		}
	}

	//! Checks and returns current Length 
	int getLength() {
		ListNode<T> *m_pCurr = m_pHead.get();//!<get head
		int iLength = 0;
		while (m_pCurr != nullptr) {//!<repeat until node is null
			iLength++;//!<increase length
			m_pCurr = m_pCurr->m_pNext.get();//!<get next node
		}
		iListLength = iLength;//!<set new length
		return iListLength;//!<return length
	}

	//! Checks if list is empty
	bool isEmpty() {
		if (m_pHead.get() == nullptr && getLength() == 0) {//!<if head is null and length is 0
			return true;
		}
		else {
			return false;
		}
	}

	//! Deletes all nodes in List
	void deleteAllNodes() {
		for (int i = iListLength; i > 0; i--) {//!<Cycle from first to last node
			removeNode(i);//!<remove last node
		}
		cout << "All Nodes Deleted..." << endl << endl;
	}
};