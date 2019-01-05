#include "..\include\ListNode.h"



ListNode::ListNode()
{
}


ListNode::~ListNode()
{
}

ListNode::ListNode(int Data) {
	m_iData = Data;
}
int ListNode::getData() {
	return m_iData;
}
