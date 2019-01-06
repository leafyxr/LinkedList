#pragma once
#include<memory>
/*! \file ListNode.h
* \brief Header file for ListNode Class
*
*/

/*! \class ListNode
* \brief an Integer Data Node for use in a double linked list
*
*/
class ListNode
{
private:
	int m_iData;//!< Data Contained in Node
public:
	//! Default Constructor, Data will be empty
	ListNode();

	//! Deconstructor
	~ListNode();

	//! Constructor, allows data to be set
	/*!
	\param Data  -  Data to be contained in new node.*/
	ListNode(int Data);

	//! Returns value of data held by node
	int getData();

	std::unique_ptr<ListNode> m_pNext;//!< Unique Pointer to Next Node
	ListNode *m_pPrev = nullptr;//!< Standard Pointer to Previous Node, Default is NULL
};
