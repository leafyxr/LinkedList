#pragma once
#include<vector>;
#include<memory>;

using namespace std;
template<typename T>
class ListNode
{
private:
	T m_TData;
public:
	ListNode();
	ListNode(T Data);
	~ListNode();
	unique_ptr<ListNode> m_pNext;
	ListNode *m_pPrev = nullptr;
};

template<typename T>
class DoubleLinkedList
{
private :
	unique_ptr<ListNode> m_pHead;
	ListNode * m_pTail;
public :
	DoubleLinkedList();
	~DoubleLinkedList();
	void addNode(const T Data);
	bool removeNode(const T Data);
	void display();
};

