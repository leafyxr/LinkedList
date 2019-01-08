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
template<typename T>
class ListNode
{
private:
	T m_iData;//!< Data Contained in Node
public:
	//! Default Constructor, Data will be empty
	ListNode(){}

	//! Deconstructor
	~ListNode(){}

	//! Constructor, allows data to be set
	/*!
	\param Data  -  Data to be contained in new node.*/
	ListNode(T Data) {
		m_iData = Data;
	}

	//! Returns value of data held by node
	T getData() {
		return m_iData;
	}

	std::unique_ptr<ListNode> m_pNext;//!< Unique Pointer to Next Node
	ListNode *m_pPrev = nullptr;//!< Standard Pointer to Previous Node, Default is NULL
};
