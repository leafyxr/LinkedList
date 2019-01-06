#pragma once
#include<memory>
#include"ListNode.h"
/*! \file DoubleLinkedList.h
* \brief Header file for DoubleLinkedList Class
*
*/

/*! \class Double Linked List
* \brief A double linked list data structure using Integers
*
*/
class DoubleLinkedList
{
private:
	std::unique_ptr<ListNode> m_pHead;//!< Pointer to Head
	ListNode * m_pTail;//!< Pointer to Tail
	int iListLength = 0;//!< Length of list
public:

	//! Constructor
	DoubleLinkedList();

	//! Deconstructor
	~DoubleLinkedList();

	//! Adds a Node at a specified point 
	/*!
	\param Data  -  Data contained in new node.
	\param Index  -  Position in list.*/
	void addNode(const int Data, const int Index);

	//! Adds a Node at the Head
	/*!
	\param Data  -  Data contained in new node..*/
	void addNodeHead(const int Data);

	//! Adds a Node at the Tail 
	/*!
	\param Data  -  Data contained in new node.*/
	void addNodeTail(const int Data);

	//! Removes a Node from a specified point 
	/*!
	\param Index  -  Position in list.*/
	bool removeNode(const int Index);

	//! Removes the current Head Node
	bool removeNodeHead();

	//! Removes the current Tail Node
	bool removeNodeTail();

	//! Displays Current List
	void display();

	//! Returns a Node from a specified point 
	/*!
	\param Index  -  Position in list.*/
	int getNode(const int Index);

	//! Returns the current Head Node
	int getNodeHead();

	//! Returns the current Tail Node
	int getNodeTail();

	//! Checks and returns current Length
	int getLength();

	//! Checks if list is empty
	bool isEmpty();
};
